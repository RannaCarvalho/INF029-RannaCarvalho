#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINHAS 10
#define COLUNAS 10

int NUM_NAVIOS = 5; 
#define VAZIO ' '
#define NAVIO 'N'
#define ACERTO '0'
#define ERRO 'X'

typedef struct {
    char mapa[LINHAS][COLUNAS]; 
    int navio_cells_totais;     
} Jogador;

void inicializa_tabuleiro(char tab[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            tab[i][j] = VAZIO;
}

void mostrar_tabuleiro_proprio(char tab[LINHAS][COLUNAS]) {
    printf("\n    1   2   3   4   5   6   7   8   9  10\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%c]", tab[i][j]);
            if (j < COLUNAS - 1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void mostrar_tabuleiro_oponente(char tab[LINHAS][COLUNAS]) {
    printf("\n    1   2   3   4   5   6   7   8   9  10\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COLUNAS; j++) {
            char c = tab[i][j];
            if (c == ACERTO) printf("[%c]", ACERTO);
            else if (c == ERRO) printf("[%c]", ERRO);
            else printf("[ ]"); 
            if (j < COLUNAS - 1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int converte_celula(const char *entrada, int *linha, int *coluna) {
    if (!entrada || strlen(entrada) < 2) return 0;

    char letra = toupper(entrada[0]);
    if (letra < 'A' || letra >= 'A' + LINHAS) return 0;

    int num = 0;
    if (sscanf(entrada + 1, "%d", &num) != 1) return 0;

    if (num < 1 || num > COLUNAS) return 0;

    *linha = letra - 'A';
    *coluna = num - 1;
    return 1;
}

int checar_disponibilidade(char tab[LINHAS][COLUNAS], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > COLUNAS) return 0;
        for (int j = coluna; j < coluna + tamanho; j++)
            if (tab[linha][j] != VAZIO) return 0;
    } else { // 'V'
        if (linha + tamanho > LINHAS) return 0;
        for (int i = linha; i < linha + tamanho; i++)
            if (tab[i][coluna] != VAZIO) return 0;
    }
    return 1;
}

void posiciona_navio(char tab[LINHAS][COLUNAS], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int j = coluna; j < coluna + tamanho; j++)
            tab[linha][j] = NAVIO;
    } else {
        for (int i = linha; i < linha + tamanho; i++)
            tab[i][coluna] = NAVIO;
    }
}

int contar_navios_restantes(char tab[LINHAS][COLUNAS]) {
    int cont = 0;
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            if (tab[i][j] == NAVIO) cont++;
    return cont;
}

void ler_string(char *buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
}

int preparar_tamanhos_navios(int tamanhos[]) {
    if (NUM_NAVIOS < 5) NUM_NAVIOS = 5;
    int contador_navios = 0;

    tamanhos[contador_navios++] = 4; 
    tamanhos[contador_navios++] = 3; 
    tamanhos[contador_navios++] = 1;
    tamanhos[contador_navios++] = 1;
    tamanhos[contador_navios++] = 1;

    while (contador_navios < NUM_NAVIOS) {
        tamanhos[contador_navios++] = 2;
    }
    return contador_navios;
}

void posicao_navios_interativa(Jogador *jog, int num_navios, int tamanhos[]) {
    char entrada[16];
    for (int k = 0; k < num_navios; k++) {
        int tam = tamanhos[k];
        int linha, coluna;
        char orientacao = 'H';
        while (1) {
            printf("\nPosicione navio %d de tamanho %d\n", k + 1, tam);
            printf("Digite a célula inicial (ex: A1): ");
            ler_string(entrada, sizeof(entrada));
            if (!converte_celula(entrada, &linha, &coluna)) {
                printf("Entrada inválida. Tente novamente.\n");
                continue;
            }

            if (tam > 1) {
                printf("Digite orientação H (horizontal) ou V (vertical): ");
                ler_string(entrada, sizeof(entrada));
                if (strlen(entrada) == 0) {
                    printf("Orientação inválida. Tente novamente.\n");
                    continue;
                }
                orientacao = toupper(entrada[0]);
                if (orientacao != 'H' && orientacao != 'V') {
                    printf("Orientação inválida. Use H ou V.\n");
                    continue;
                }
            } else {
                orientacao = 'H';
            }

            if (!checar_disponibilidade(jog->mapa, linha, coluna, tam, orientacao)) {
                printf("Posição inválida (sai fora do tabuleiro ou sobrepõe outro navio). Tente outra posição.\n");
                continue;
            }
            posiciona_navio(jog->mapa, linha, coluna, tam, orientacao);
            jog->navio_cells_totais += tam;
            mostrar_tabuleiro_proprio(jog->mapa);
            break;
        }
    }
}

int efetuar_tiro(Jogador *atacante, Jogador *alvo) {
    char entrada[16];
    int linha, coluna;

    while (1) {
        printf("Informe a célula para atirar (ex: B3): ");
        ler_string(entrada, sizeof(entrada));
        if (!converte_celula(entrada, &linha, &coluna)) {
            printf("Entrada inválida. Use A1..J10. Tente novamente.\n");
            continue;
        }

        char estado_no_alvo = alvo->mapa[linha][coluna];
        if (estado_no_alvo == ACERTO || estado_no_alvo == ERRO) {
            printf("Você já atirou nessa célula. Escolha outra.\n");
            continue;
        }

        if (estado_no_alvo == NAVIO) {
            printf("Acertou! Navio atingido em %c%d.\n", 'A' + linha, coluna + 1);
            alvo->mapa[linha][coluna] = ACERTO;
            return 1;
        } else {
            printf("Água (erro).\n");
            alvo->mapa[linha][coluna] = ERRO;
            return 0;
        }
    }
}

int main() {
    printf("=== BATALHA NAVAL (Console) ===\n\n");
    printf("Regras principais:\n");
    printf("- Tabuleiro 10x10 (A-J / 1-10)\n");
    printf("- Símbolos: [ ] vazio, [N] seu navio (visível apenas a você), [0] acerto, [X] erro\n");
    printf("- Cada jogador posiciona seus navios manualmente no início.\n");
    printf("- Depois, alternam-se turnos de tiro até que todos os navios de um jogador sejam abatidos.\n\n");

    int tamanhos[100]; 
    int navios_reais = preparar_tamanhos_navios(tamanhos);
    printf("Número de navios: %d (tamanhos:", navios_reais);
    for (int i = 0; i < navios_reais; i++) {
        printf(" %d", tamanhos[i]);
    }
    printf(" )\n\n");

    Jogador j1, j2;
    inicializa_tabuleiro(j1.mapa);
    inicializa_tabuleiro(j2.mapa);
    j1.navio_cells_totais = 0;
    j2.navio_cells_totais = 0;

    // Posicionamento Jogador 1
    printf("=== Jogador 1: posicione seus navios ===\n");
    mostrar_tabuleiro_proprio(j1.mapa);
    posicao_navios_interativa(&j1, navios_reais, tamanhos);
    printf("Jogador 1 finalizou posicionamento. Pressione ENTER para prosseguir...");
    getchar();

    for (int i = 0; i < 30; i++) printf("\n");

    printf("=== Jogador 2: posicione seus navios ===\n");
    mostrar_tabuleiro_proprio(j2.mapa);
    posicao_navios_interativa(&j2, navios_reais, tamanhos);
    printf("Jogador 2 finalizou posicionamento. Pressione ENTER para iniciar o jogo...");
    getchar();

    // Jogo de turno em turno
    int jogador_atual = 1; // 1 ou 2
    while (1) {
        // mostrar visão do jogador atual
        for (int i = 0; i < 30; i++) printf("\n");
        if (jogador_atual == 1) {
            printf("=== Turno: Jogador 1 ===\n");
            printf("Seu tabuleiro:\n");
            mostrar_tabuleiro_proprio(j1.mapa);
            printf("Tabuleiro do oponente (sua visão - mostra acertos e erros):\n");
            mostrar_tabuleiro_oponente(j2.mapa);
            int acerto = efetuar_tiro(&j1, &j2);
            if (acerto) {
                int restantes = contar_navios_restantes(j2.mapa);
                if (restantes == 0) {
                    printf("\nJogador 1 venceu! Todos os navios do Jogador 2 foram abatidos.\n");
                    break;
                }
            }
            printf("Fim do turno do Jogador 1. Pressione ENTER para continuar...");
            getchar();
            jogador_atual = 2;
        } else {
            printf("=== Turno: Jogador 2 ===\n");
            printf("Seu tabuleiro:\n");
            mostrar_tabuleiro_proprio(j2.mapa);
            printf("Tabuleiro do oponente (sua visão - mostra acertos e erros):\n");
            mostrar_tabuleiro_oponente(j1.mapa);
            int acerto = efetuar_tiro(&j2, &j1);
            if (acerto) {
                int restantes = contar_navios_restantes(j1.mapa);
                if (restantes == 0) {
                    printf("\nJogador 2 venceu! Todos os navios do Jogador 1 foram abatidos.\n");
                    break;
                }
            }
            printf("Fim do turno do Jogador 2. Pressione ENTER para continuar...");
            getchar();
            jogador_atual = 1;
        }
    }

    printf("Jogo encerrado. Obrigado por jogar!\n");
    return 0;
}
