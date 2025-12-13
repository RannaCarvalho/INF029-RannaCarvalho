#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int dados_par[MAX];
    int topo_par;
    int dados_impar[MAX];
    int topo_impar;
} Pilha;

void inicializar(Pilha *p) {
    p->topo_par = -1;
    p->topo_impar = -1;
}

bool estaCheiapar(Pilha *p) {
    return p->topo_par == MAX - 1;
}
bool estaCheiaimpar(Pilha *p) {
    return p->topo_impar == MAX - 1;
}

bool estaVaziapar(Pilha *p) {
    return p->topo_par == -1;
}
bool estaVaziaimpar(Pilha *p) {
    return p->topo_impar == -1;
}

// Função para pedir o número e empilhar
void push(Pilha *p) {
    if (estaCheiapar(p)) {
        printf("\nErro: A pilha de numero par ja esta cheia!\n");
        return;
    }
    if (estaCheiaimpar(p)) {
        printf("\nErro: A pilha de numero impar ja esta cheia!\n");
        return;
    }
    
    int valor;
    printf("Digite o numero para empilhar: ");
    scanf("%d", &valor);
    
    if (valor%2==0){
        p->topo_par++;
        p->dados_par[p->topo_par] = valor;
        printf("\n--> %d adicionado ao topo da pilha par.\n", valor);
    }
    else {
        p->topo_impar++;
        p->dados_impar[p->topo_impar] = valor;
        printf("\n--> %d adicionado ao topo da pilha impar.\n", valor);
    }
    
}

// Função para remover do topo
void pop(Pilha *p) {
    if (estaVaziapar(p)) {
        printf("\nErro: A pilha par ja esta vazia!\n");
        return;
    }
    else{
        int valor = p->dados_par[p->topo_par];
        p->topo_par--;
        printf("\n--> %d removido do topo da pilha par.\n", valor);
    }
    if (estaVaziaimpar(p)) {
        printf("\nErro: A pilha impar ja esta vazia!\n");
        return;
    }
    else{
        int valor = p->dados_impar[p->topo_impar];
        p->topo_impar--;
        printf("\n--> %d removido do topo da pilha impar.\n", valor);
    }
    
}

// Mostra a pilha visualmente do topo para a base
void mostrarPilha(Pilha *p) {
    if (estaVaziapar(p)) {
        printf("\n[ Pilha Par Vazia ]\n");
        return;
    }
    else {
        printf("\n--- Estado Atual da Pilha Par ---\n");
        // Laço invertido: começa do topo e desce até o 0
        for (int i = p->topo_par; i >= 0; i--) {
        printf("  [%d]\n", p->dados_par[i]);
        }
        printf("-----------------------------\n");
    }
    if (estaVaziaimpar(p)) {
        printf("\n[ Pilha Impar Vazia ]\n");
        return;
    }
    else {
        printf("\n--- Estado Atual da Pilha Impar ---\n");
        // Laço invertido: começa do topo e desce até o 0
        for (int i = p->topo_impar; i >= 0; i--) {
        printf("  [%d]\n", p->dados_impar[i]);
        }
        printf("-----------------------------\n");
    }

}

int main() {
    Pilha p;
    inicializar(&p);
    int opcao;

    do {
        printf("\n1. Empilhar (Push)\n");
        printf("2. Desempilhar (Pop)\n");
        printf("3. Ver Pilha\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                push(&p); 
                break;
            case 2: 
                pop(&p); 
                break;
            case 3: 
                mostrarPilha(&p); 
                break;
            case 0: 
                printf("Saindo...\n"); 
                break;
            default: 
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
