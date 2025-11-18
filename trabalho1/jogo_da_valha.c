#include <stdio.h>
#include <ctype.h>
#define N 3

void mostrar_tabuleiro(char tab[N][N]) {
    printf("\n    1   2   3\n");
    printf("A   %c | %c | %c\n", tab[0][0], tab[0][1], tab[0][2]);
    printf("   ---+---+---\n");
    printf("B   %c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
    printf("   ---+---+---\n");
    printf("C   %c | %c | %c\n\n", tab[2][0], tab[2][1], tab[2][2]);
}

int verificar_vencedor(char tab[N][N], char *vencedor) {
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

int converter_celula(char entrada[], int *linha, int *coluna) {
    char letra = toupper(entrada[0]);
    char numero = entrada[1];

    if (letra < 'A' || letra > 'C') return 0;
    if (numero < '1' || numero > '3') return 0;

    *linha = letra - 'A';
    *coluna = numero - '1';

    return 1;
}

int main() {
    char tabuleiro[N][N];
    int linha, coluna;
    char entrada[3];
    int jogador = 1;
    char marca, vencedor = ' ';

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = ' ';

    while (1) {
        mostrar_tabuleiro(tabuleiro);

        marca = (jogador == 1 ? 'X' : '0');

        printf("Jogador %d (%c), informe a celula (ex: B3): ", jogador, marca);
        scanf("%2s", entrada);

        if (!converter_celula(entrada, &linha, &coluna)) {
            printf("Entrada invalida! Use A1, B3, C2, etc.\n\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Celula ocupada! Escolha outra.\n\n");
            continue;
        }

        tabuleiro[linha][coluna] = marca;

        if (verificar_vencedor(tabuleiro, &vencedor)) {
            mostrar_tabuleiro(tabuleiro);
            if (vencedor == 'X') printf("Jogador 1 venceu!\n");
            else printf("Jogador 2 venceu!\n");
            break;
        }

        if (tabuleiro_cheio(tabuleiro)) {
            mostrar_tabuleiro(tabuleiro);
            printf("Nao houve vencedor. Deu empate!\n");
            break;
        }
        jogador = (jogador == 1 ? 2 : 1);
    }
    return 0;
}
        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}
