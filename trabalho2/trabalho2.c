#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

#define TAM 10

// Estrutura principal otimizada
typedef struct {
    int *vetorAux;
    int qtd;
    int tamanho;
} Descritor;

Descritor vetorPrincipal[TAM];

// --- Funções Auxiliares ---

int ehPosicaoValida(int posicao) {
    if (posicao < 1 || posicao > TAM)
        return 0;
    return 1;
}

int temEstruturaAuxiliar(int posicao) {
    if (vetorPrincipal[posicao - 1].vetorAux != NULL)
        return 1;
    return 0;
}

void ordenarVetor(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// --- Funções Principais ---

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (temEstruturaAuxiliar(posicao))
        return JA_TEM_ESTRUTURA_AUXILIAR;
        
    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    vetorPrincipal[posicao - 1].vetorAux = (int *)malloc(tamanho * sizeof(int));
    
    if (vetorPrincipal[posicao - 1].vetorAux == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao - 1].tamanho = tamanho;
    vetorPrincipal[posicao - 1].qtd = 0;

    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].qtd >= vetorPrincipal[indice].tamanho)
        return SEM_ESPACO;

    vetorPrincipal[indice].vetorAux[vetorPrincipal[indice].qtd] = valor;
    vetorPrincipal[indice].qtd++;

    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;
        
    if (vetorPrincipal[posicao - 1].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao - 1].qtd--;
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;
        
    if (vetorPrincipal[posicao - 1].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int indice = posicao - 1;
    int i, j, encontrado = 0;

    for (i = 0; i < vetorPrincipal[indice].qtd; i++) {
        if (vetorPrincipal[indice].vetorAux[i] == valor) {
            encontrado = 1;
            // Shift para esquerda
            for (j = i; j < vetorPrincipal[indice].qtd - 1; j++) {
                vetorPrincipal[indice].vetorAux[j] = vetorPrincipal[indice].vetorAux[j + 1];
            }
            vetorPrincipal[indice].qtd--;
            break; 
        }
    }

    if (encontrado)
        return SUCESSO;
    else
        return NUMERO_INEXISTENTE;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int indice = posicao - 1;
    for (int i = 0; i < vetorPrincipal[indice].qtd; i++) {
        vetorAux[i] = vetorPrincipal[indice].vetorAux[i];
    }

    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    
    if (retorno == SUCESSO) {
        ordenarVetor(vetorAux, vetorPrincipal[posicao - 1].qtd);
    }
    
    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int k = 0;
    int vazia = 1;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].qtd > 0) {
            vazia = 0;
            for (int j = 0; j < vetorPrincipal[i].qtd; j++) {
                vetorAux[k] = vetorPrincipal[i].vetorAux[j];
                k++;
            }
        }
    }

    if (vazia)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    
    if (retorno == SUCESSO) {
        int totalElementos = 0;
        for (int i = 0; i < TAM; i++) {
            if (vetorPrincipal[i].vetorAux != NULL)
                totalElementos += vetorPrincipal[i].qtd;
        }
        ordenarVetor(vetorAux, totalElementos);
    }
    
    return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int indice = posicao - 1;
    int tamanhoFinal = vetorPrincipal[indice].tamanho + novoTamanho;

    if (tamanhoFinal < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoVetor = (int *)realloc(vetorPrincipal[indice].vetorAux, tamanhoFinal * sizeof(int));

    if (novoVetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[indice].vetorAux = novoVetor;
    vetorPrincipal[indice].tamanho = tamanhoFinal;

    // Se diminuiu o tamanho, ajusta a qtd para não exceder
    if (vetorPrincipal[indice].qtd > tamanhoFinal)
        vetorPrincipal[indice].qtd = tamanhoFinal;

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (!ehPosicaoValida(posicao))
        return POSICAO_INVALIDA;
        
    if (!temEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;
        
    if (vetorPrincipal[posicao - 1].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[posicao - 1].qtd;
}

// --- Funções de Lista Encadeada ---

No *montarListaEncadeadaComCabecote() {
    // Verifica se há elementos antes de alocar
    int haElementos = 0;
    for(int i=0; i<TAM; i++){
        if(vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].qtd > 0){
            haElementos = 1;
            break;
        }
    }
    if(!haElementos) return NULL;

    No *head = (No *)malloc(sizeof(No));
    if (head == NULL) return NULL;
    head->prox = NULL;

    No *ultimo = head; // Ponteiro para inserir sempre no final (O(1))

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].qtd > 0) {
            for (int j = 0; j < vetorPrincipal[i].qtd; j++) {
                No *novo = (No *)malloc(sizeof(No));
                if (novo == NULL) {
                    // Idealmente aqui deveria limpar a memória já alocada em caso de falha
                    return NULL; 
                }
                novo->conteudo = vetorPrincipal[i].vetorAux[j];
                novo->prox = NULL;
                
                ultimo->prox = novo;
                ultimo = novo;
            }
        }
    }
    return head;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    if (inicio == NULL) return;

    No *p = inicio->prox;
    int k = 0;
    while (p != NULL) {
        vetorAux[k] = p->conteudo;
        p = p->prox;
        k++;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio) {
    if (inicio == NULL || *inicio == NULL) return;

    No *atual = *inicio;
    No *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].vetorAux = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetorAux != NULL) {
            free(vetorPrincipal[i].vetorAux);
            vetorPrincipal[i].vetorAux = NULL;
        }
    }
}
