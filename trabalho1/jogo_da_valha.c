#include <stdio.h>
#define N 3

void mostrar_tabuleiro(char tab[N][N]) {
    int i, j;
    printf("\n   1   2   3\n");
    for (i = 0; i < N; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < N; j++) {
            printf(" %c ", tab[i][j]);
            if (j < N - 1) printf("|");
        }
        printf("\n");
        if (i < N - 1) printf("  ---+---+---\n");
    }
    printf("\n");
}

int checar_vitoria(char tab[N][N], char *vencedor) {
    int i;

    for (i = 0; i < N; i++) {
        if (tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) {
            *vencedor = tab[i][0];
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) {
            *vencedor = tab[0][i];
            return 1;
        }
    }

    if (tab[0][0] != ' ' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) {
        *vencedor = tab[0][0];
        return 1;
    }
    if (tab[0][2] != ' ' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {
        *vencedor = tab[0][2];
        return 1;
    }

    return 0;
}

int tabuleiro_cheio(char tab[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (tab[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    char tabuleiro[N][N];
    int linha, coluna;
    int jogador = 1; 
    char marca;
    char vencedor = ' ';
    int jogada_valida;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = ' ';

    while (1) {
        mostrar_tabuleiro(tabuleiro);

        if (jogador == 1) marca = 'X';
        else marca = '0'; 

        printf("Jogador %d, informe sua jogada:\n", jogador);
        printf("Informe linha (1-3) e coluna (1-3), separados por espaço: ");
        jogada_valida = scanf("%d %d", &linha, &coluna);

        while (getchar() != '\n');

        if (jogada_valida != 2) {
            printf("Entrada invalida. Tente novamente.\n\n");
            continue;
        }

        linha--; coluna--;

        if (linha < 0 || linha >= N || coluna < 0 || coluna >= N) {
            printf("Posicao invalida. Linhas e colunas devem estar entre 1 e 3.\n\n");
            continue;
        }
        if (tabuleiro[linha][coluna] != ' ') {
            printf("Posicao ja ocupada. Escolha outra.\n\n");
            continue;
        }

        tabuleiro[linha][coluna] = marca;

        if (checar_vitoria(tabuleiro, &vencedor)) {
            mostrar_tabuleiro(tabuleiro);
            if (vencedor == 'X') printf("Jogador 1 (X) venceu! Parabens!\n");
            else printf("Jogador 2 (0) venceu! Parabens!\n");
            break;
        }

        // Checa empate
        if (tabuleiro_cheio(tabuleiro)) {
            mostrar_tabuleiro(tabuleiro);
            printf("Empate! Tabuleiro cheio.\n");
            break;
        }

        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}
