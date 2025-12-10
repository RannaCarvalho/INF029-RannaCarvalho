#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct pont {
    int valor;
    struct pont* proximo;
} pont;
pont* insere(pont* topo, int valor) {
    pont* novo = (pont*)malloc(sizeof(pont));
    
    if (novo != NULL) {
        novo->valor = valor;
        novo->proximo = topo; 
        return novo;          
    } else {
        printf("Erro ao alocar memória!\n");
        return topo;
    }
}
void imprimir(No* topo) {
    No* aux = topo;
    printf("\nPilha atual:\nTOPO -> ");
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n\n");
}

int main() {
    No* topo = NULL; 
    int valor, op = 1;

    while (op != 0) {
        printf("Digite um valor inteiro para empilhar: ");
        scanf("%d", &valor);

        topo = insere(topo, valor);
        
        imprimir(topo);

        printf("Digite 1 para inserir outro valor ou 0 para sair: ");
        scanf("%d", &op);
    }

    return 0;
}
