// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

typedef struct DQ
{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido
} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

int q1(char data[])
{
    int i = 0, j = 0;
    int dia = 0, mes = 0, ano = 0;
    char iDia[3] = "", iMes[3] = "", iAno[5] = "";

    while (data[i] != '/' && data[i] != '\0') {
        if (j >= 2) return 0; 
        iDia[j++] = data[i++];
    }
    iDia[j] = '\0';
    if (data[i] == '\0') return 0;
    i++;

    j = 0;
    while (data[i] != '/' && data[i] != '\0') {
        if (j >= 2) return 0;
        iMes[j++] = data[i++];
    }
    iMes[j] = '\0';
    if (data[i] == '\0') return 0;
    i++;

    j = 0;
    while (data[i] != '\0') {
        if (j >= 4) return 0;
        iAno[j++] = data[i++];
    }
    iAno[j] = '\0';

    dia = 0;
    for (i = 0; iDia[i] != '\0'; i++) {
        if (iDia[i] < '0' || iDia[i] > '9') return 0;
        dia = dia * 10 + (iDia[i] - '0');
    }

    mes = 0;
    for (i = 0; iMes[i] != '\0'; i++) {
        if (iMes[i] < '0' || iMes[i] > '9') return 0;
        mes = mes * 10 + (iMes[i] - '0');
    }

    ano = 0;
    for (i = 0; iAno[i] != '\0'; i++) {
        if (iAno[i] < '0' || iAno[i] > '9') return 0;
        ano = ano * 10 + (iAno[i] - '0');
    }

    if (strlen(iAno) == 2) {
        ano += 2000; // ex: 23 -> 2023
    }

    if (mes < 1 || mes > 12) return 0;
    if (dia < 1) return 0;

    int diasNoMes;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31; break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30; break;
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                diasNoMes = 29;
            else
                diasNoMes = 28;
            break;
        default:
            return 0;
    }

    if (dia > diasNoMes) return 0;

    return 1;
}

DataQuebrada quebraData(char data[])
{
    DataQuebrada dq = {0,0,0,0};

    if (!q1(data)) return dq;

    int i = 0, j = 0;
    char iDia[3] = "", iMes[3] = "", iAno[5] = "";

    while (data[i] != '/' && data[i] != '\0') iDia[j++] = data[i++]; iDia[j] = '\0'; i++;
    j = 0;
    while (data[i] != '/' && data[i] != '\0') iMes[j++] = data[i++]; iMes[j] = '\0'; i++;
    j = 0;
    while (data[i] != '\0') iAno[j++] = data[i++]; iAno[j] = '\0';

    /* conversão manual (já validado por q1) */
    int dia = 0, mes = 0, ano = 0;
    for (i = 0; iDia[i] != '\0'; i++) dia = dia * 10 + (iDia[i] - '0');
    for (i = 0; iMes[i] != '\0'; i++) mes = mes * 10 + (iMes[i] - '0');
    for (i = 0; iAno[i] != '\0'; i++) ano = ano * 10 + (iAno[i] - '0');

    if (strlen(iAno) == 2) ano += 2000;

    dq.iDia = dia;
    dq.iMes = mes;
    dq.iAno = ano;
    dq.valido = 1;
    return dq;
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma = {0,0,0,0};

    /* validações iniciais */
    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada inicial = quebraData(datainicial);
    DataQuebrada final = quebraData(datafinal);

    if (final.iAno < inicial.iAno) {
        dma.retorno = 4;
        return dma;
    } else if ((final.iAno == inicial.iAno) && (inicial.iMes > final.iMes)) {
        dma.retorno = 4;
        return dma;
    } else if ((final.iAno == inicial.iAno) && (inicial.iMes == final.iMes) && (final.iDia < inicial.iDia)) {
        dma.retorno = 4;
        return dma;
    }

    dma.qtdAnos = final.iAno - inicial.iAno;
    dma.qtdMeses = final.iMes - inicial.iMes;
    dma.qtdDias = final.iDia - inicial.iDia;

    if (dma.qtdDias < 0) {
        dma.qtdDias += 30; 
        dma.qtdMeses--;
    }

    if (dma.qtdMeses < 0) {
        dma.qtdMeses += 12;
        dma.qtdAnos--;
    }

    dma.retorno = 1;
    return dma;
}

int main() {
    char data[20];
    printf("Digite uma data (dd/mm/aaaa): ");
    if (scanf("%19s", data) != 1) return 0;

    if (q1(data))
        printf("\nData válida\n");
    else
        printf("\nData inválida\n");

    char datainicial[20], datafinal[20];
    printf("\n");
    printf("Digite a data inicial (dd/mm/aaaa): ");
    if (scanf("%19s", datainicial) != 1) return 0;
    printf("Digite a data final (dd/mm/aaaa): ");
    if (scanf("%19s", datafinal) != 1) return 0;

    DiasMesesAnos resposta = q2(datainicial, datafinal);

    switch (resposta.retorno) {
        case 1:
            printf("\nCálculo realizado com sucesso!\n");
            printf("Diferença: %d ano(s), %d mês(es) e %d dia(s)\n",
                   resposta.qtdAnos, resposta.qtdMeses, resposta.qtdDias);
            break;
        case 2:
            printf("\nData inicial inválida!\n"); break;
        case 3:
            printf("\nData final inválida!\n"); break;
        case 4:
            printf("\nData inicial maior que a final!\n"); break;
        default:
            printf("\nErro desconhecido.\n");
    }

    return 0;
}

  //quebrar a string data em strings sDia, sMes, sAno


  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 200

int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i;

    for (i = 0; texto[i] != '\0'; i++)
    {
        if (isCaseSensitive==1)
        {
            if (texto[i] == c)
                qtdOcorrencias++;
        }
        else
        {
            if (tolower(texto[i]) == tolower(c))
                qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

int main()
{
    char texto[TAM];
    char caractere;
    int isCaseSensitive;
    int resultado;

    printf("Digite um texto: ");
    fgets(texto, TAM, stdin);
    texto[strcspn(texto, "\n")] = '\0'; 

    printf("Digite o caractere a ser contado: ");
    scanf(" %c", &caractere);

    printf("Diferenciar maiúsculas e minúsculas? (1 = sim, 0 = não): ");
    scanf("%d", &isCaseSensitive);

    resultado = q3(texto, caractere, isCaseSensitive);

    printf("\nO caractere '%c' aparece %d vezes no texto.\n", caractere, resultado);

    return 0;
}


/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
