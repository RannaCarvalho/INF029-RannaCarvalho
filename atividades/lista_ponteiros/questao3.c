#include <stdio.h>
#define TAM 5

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(int A[], int n) {
    int i, j, trocou;
    for(i = 0; i < n - 1; i++) {
        trocou = 0;
        for (j = 0; j < n - i - 1; j++) {
            if(A[j] > A[j+1]) {
                troca(&A[j], &A[j+1]);
                trocou = 1;
            }
        }
        if (trocou == 0)
            break;
    }
}

void printArray(int A[], int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[TAM];
    int i;
    
    int n = sizeof(A) / sizeof(A[0]); 
    
    printf("Digite %d valores de um vetor: \n", TAM);
    for (i = 0; i < TAM; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    
    ordena(A, n);
    
    printf("\nArray ordenado: ");
    printArray(A, n); 
    
    return 0;
}
