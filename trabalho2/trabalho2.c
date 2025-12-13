#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

// Definição da estrutura auxiliar interna
typedef struct {
    int *dados;
    int tamanho;
    int quantidadeUsada;
} EstruturaAuxiliar;

// Vetor global de ponteiros para as estruturas auxiliares
EstruturaAuxiliar *vetor[TAM];

// Função auxiliar para validar posição (1 a 10)
int ehPosicaoValida(int posicao) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;
    return SUCESSO;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;
        
    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    int i = posicao - 1;

    if (vetor[i] != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    vetor[i] = (EstruturaAuxiliar*) malloc(sizeof(EstruturaAuxiliar));
    if (vetor[i] == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetor[i]->dados = (int*) malloc(tamanho * sizeof(int));
    if (vetor[i]->dados == NULL) {
        free(vetor[i]);
        vetor[i] = NULL;
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetor[i]->tamanho = tamanho;
    vetor[i]->quantidadeUsada = 0;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;

    int i = posicao - 1;

    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetor[i]->quantidadeUsada >= vetor[i]->tamanho)
        return SEM_ESPACO;

    vetor[i]->dados[vetor[i]->quantidadeUsada] = valor;
    vetor[i]->quantidadeUsada++;

    return SUCESSO;
}

/*
Objetivo: excluir o numero do final da estrutura auxiliar.
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;

    int i = posicao - 1;

    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetor[i]->quantidadeUsada == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetor[i]->quantidadeUsada--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;

    int i = posicao - 1;

    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetor[i]->quantidadeUsada == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int encontrado = 0;
    int posValor = -1;

    // Busca o valor
    for (int j = 0; j < vetor[i]->quantidadeUsada; j++) {
        if (vetor[i]->dados[j] == valor) {
            encontrado = 1;
            posValor = j;
            break;
        }
    }

    if (!encontrado)
        return NUMERO_INEXISTENTE;

    // Move os elementos para trás (shift left)
    for (int j = posValor; j < vetor[i]->quantidadeUsada - 1; j++) {
        vetor[i]->dados[j] = vetor[i]->dados[j + 1];
    }

    vetor[i]->quantidadeUsada--;

    return SUCESSO;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;

    int i = posicao - 1;

    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int j = 0; j < vetor[i]->quantidadeUsada; j++) {
        vetorAux[j] = vetor[i]->dados[j];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    
    int ret = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (ret != SUCESSO)
        return ret;

    int qtd = vetor[posicao - 1]->quantidadeUsada;

    // Bubble Sort simples
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - 1 - i; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    
    int k = 0;
    int vazias = 1;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] != NULL && vetor[i]->quantidadeUsada > 0) {
            vazias = 0;
            for (int j = 0; j < vetor[i]->quantidadeUsada; j++) {
                vetorAux[k] = vetor[i]->dados[j];
                k++;
            }
        }
    }

    if (vazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    
    int ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (ret != SUCESSO)
        return ret;

    // Calcula o total de elementos para saber até onde ordenar
    int total = 0;
    for(int i=0; i<TAM; i++) {
        if(vetor[i] != NULL) total += vetor[i]->quantidadeUsada;
    }

    // Bubble Sort
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;

    int i = posicao - 1;
    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoFinal = vetor[i]->tamanho + novoTamanho;

    if (tamanhoFinal < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoDados = (int*) realloc(vetor[i]->dados, tamanhoFinal * sizeof(int));
    if (novoDados == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetor[i]->dados = novoDados;
    vetor[i]->tamanho = tamanhoFinal;

    // Se o tamanho diminuiu, ajusta a quantidade usada para não estourar
    if (vetor[i]->quantidadeUsada > tamanhoFinal)
        vetor[i]->quantidadeUsada = tamanhoFinal;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    
    if (ehPosicaoValida(posicao) != SUCESSO) 
        return POSICAO_INVALIDA;
    
    int i = posicao - 1;

    if (vetor[i] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
        
    if (vetor[i]->quantidadeUsada == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetor[i]->quantidadeUsada;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
    
    No *cabecote = (No*) malloc(sizeof(No));
    if (cabecote == NULL) return NULL;
    cabecote->prox = NULL;

    No *ultimo = cabecote;
    int temElemento = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] != NULL) {
            for (int j = 0; j < vetor[i]->quantidadeUsada; j++) {
                
                No *novo = (No*) malloc(sizeof(No));
                if (novo == NULL) return NULL; // Em produção idealmente limparia a memória
                
                // ATENÇÃO: No .h o campo é 'conteudo', não 'valor'
                novo->conteudo = vetor[i]->dados[j]; 
                novo->prox = NULL;

                ultimo->prox = novo;
                ultimo = novo;
                temElemento = 1;
            }
        }
    }

    if (!temElemento) {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    
    if (inicio == NULL) return;
    
    No *atual = inicio->prox;
    int k = 0;

    while (atual != NULL) {
        // ATENÇÃO: No .h o campo é 'conteudo'
        vetorAux[k] = atual->conteudo; 
        k++;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
    
    if (inicio == NULL || *inicio == NULL)
        return;

    No *atual = *inicio;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar() {
    for (int i = 0; i < TAM; i++) {
        vetor[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] != NULL) {
            if (vetor[i]->dados != NULL) {
                free(vetor[i]->dados);
            }
            free(vetor[i]);
            vetor[i] = NULL;
        }
    }
}
