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
//  Nome: Ranna Anunciação de Carvalho
//  email: rannadecarvalho@gmail
//  Matrícula: 20251160043
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h"
#include <stdlib.h>
#include <string.h>

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
{ // função utilizada para testes
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
int q1(char data[])
{
  int i = 0, j = 0;
  int dia = 0, mes = 0, ano = 0;
  char iDia[3] = "", iMes[3] = "", iAno[5] = "";

  while (data[i] != '/' && data[i] != '\0')
  {
    if (j >= 2)
      return 0;
    iDia[j++] = data[i++];
  }
  iDia[j] = '\0';
  if (data[i] == '\0')
    return 0;
  i++;
  j = 0;
  while (data[i] != '/' && data[i] != '\0')
  {
    if (j >= 2)
      return 0;
    iMes[j++] = data[i++];
  }
  iMes[j] = '\0';
  if (data[i] == '\0')
    return 0;
  i++;
  j = 0;
  while (data[i] != '\0')
  {
    if (j >= 4)
      return 0; // Mais de 4 dígitos
    iAno[j++] = data[i++];
  }
  iAno[j] = '\0';

  if (strlen(iAno) != 2 && strlen(iAno) != 4)
    return 0;

  dia = 0;
  for (i = 0; iDia[i] != '\0'; i++)
  {
    if (iDia[i] < '0' || iDia[i] > '9')
      return 0;
    dia = dia * 10 + (iDia[i] - '0');
  }

  mes = 0;
  for (i = 0; iMes[i] != '\0'; i++)
  {
    if (iMes[i] < '0' || iMes[i] > '9')
      return 0;
    mes = mes * 10 + (iMes[i] - '0');
  }

  ano = 0;
  for (i = 0; iAno[i] != '\0'; i++)
  {
    if (iAno[i] < '0' || iAno[i] > '9')
      return 0;
    ano = ano * 10 + (iAno[i] - '0');
  }

  if (strlen(iAno) == 2)
  {
    ano += 2000; // ex: 23 -> 2023
  }
  if (mes < 1 || mes > 12)
    return 0;
  if (dia < 1)
    return 0;

  int diasNoMes;
  int bissexto = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));

  switch (mes)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    diasNoMes = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    diasNoMes = 30;
    break;
  case 2:
    diasNoMes = bissexto ? 29 : 28;
    break;
  default:
    return 0;
  }

  if (dia > diasNoMes)
    return 0;

  return 1;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq = {0, 0, 0, 0}; // Inicializa com valores zerados e invalido (0)
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/' && data[i] != '\0'; i++)
  {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2)
  {
    sDia[i] = '\0';
  }
  else
  {
    return dq;
  }

  int j = i + 1;
  i = 0;

  for (; data[j] != '/' && data[j] != '\0'; j++)
  {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2)
  {
    sMes[i] = '\0';
  }
  else
  {
    return dq;
  }

  j = j + 1;
  i = 0;

  // --- Extração do Ano ---
  for (; data[j] != '\0'; j++)
  {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4)
  {
    sAno[i] = '\0';
  }
  else
  {
    return dq;
  }
  dq.valido = 0;

  if (q1(data) == 1)
  {
    int dia_int = atoi(sDia);
    int mes_int = atoi(sMes);
    int ano_int = atoi(sAno);

    if (strlen(sAno) == 2)
    {
      ano_int += 2000;
    }

    dq.iDia = dia_int;
    dq.iMes = mes_int;
    dq.iAno = ano_int;
    dq.valido = 1;
  }

  return dq;
}

/**
 * Função q2: Calcula a diferença entre duas datas (DataFinal - DataInicial).
 * * @param datainicial A string da data inicial.
 * @param datafinal A string da data final.
 * @returns DiasMesesAnos A estrutura com a diferença em dias, meses e anos.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DiasMesesAnos dma = {0, 0, 0, 0};

  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }
  if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }

  DataQuebrada inicial = quebraData(datainicial);
  DataQuebrada final = quebraData(datafinal);

  if (final.iAno < inicial.iAno)
  {
    dma.retorno = 4;
    return dma;
  }
  else if ((final.iAno == inicial.iAno) && (inicial.iMes > final.iMes))
  {
    dma.retorno = 4;
    return dma;
  }
  else if ((final.iAno == inicial.iAno) && (inicial.iMes == final.iMes) && (final.iDia < inicial.iDia))
  {
    dma.retorno = 4;
    return dma;
  }

  dma.qtdAnos = final.iAno - inicial.iAno;
  dma.qtdMeses = final.iMes - inicial.iMes;
  dma.qtdDias = final.iDia - inicial.iDia;

  if (dma.qtdDias < 0)
  {
    dma.qtdDias += 30;
    dma.qtdMeses--;
  }

  if (dma.qtdMeses < 0)
  {
    dma.qtdMeses += 12;
    dma.qtdAnos--;
  }

  dma.retorno = 1;
  return dma;
}

/* main removed to avoid multiple-definition when linking with corretor.c / novoCorretor.c
   Keep tests in separate files (corretor.c / novoCorretor.c) which define main(). */
/*int main() {
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
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

#include <ctype.h>
#define TAM 200

int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int i;

  for (i = 0; texto[i] != '\0'; i++)
  {
    if (isCaseSensitive == 1)
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

/*int main()
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
  int qtdOcorrencias = 0;
  int i, j, k = 0;
  int lenTexto = strlen(strTexto);
  int lenBusca = strlen(strBusca);

  // percorre o texto até onde a palavra cabe
  for (i = 0; i <= lenTexto - lenBusca; i++)
  {
    int achou = 1;

    for (j = 0; j < lenBusca; j++)
    {
      if (strTexto[i + j] != strBusca[j])
      {
        achou = 0;
        break;
      }
    }

    if (achou)
    {
      posicoes[k++] = i;                // posição inicial
      posicoes[k++] = i + lenBusca - 1; // posição final
      qtdOcorrencias++;
    }
  }

  return qtdOcorrencias;
}

/*int main()
{
    char strTexto[30];
    char strBusca[30];
    int posicoes[30];
    int i, j, k = 0;
    int qtdOcorrencias = -1;
    int resultado;
    int posicao_ini, posicao_fim;

    printf("Digite um texto: \n");
    fgets(strTexto, sizeof(strTexto), stdin);
    strTexto[strcspn(strTexto, "\n")] = '\0'; // remove o '\n'

    printf("Digite uma palavra a ser buscada: \n");
    fgets(strBusca, sizeof(strBusca), stdin);
    strBusca[strcspn(strBusca, "\n")] = '\0'; // remove o '\n'

    resultado = q4(strTexto, strBusca, posicoes);

    if (resultado <= 0) {
        printf("A palavra buscada nao foi encontrada no texto.\n");
    } else {
        printf("A palavra buscada aparece %d vez(es) no texto.\n", resultado);
        printf("Posicoes iniciais/finais:\n");
        for (i = 0; i < resultado; i++) {
            posicao_ini = posicoes[2 * i];
            posicao_fim = posicoes[2 * i + 1];
            printf("Ocorrencia %d: %d/%d\n", i + 1, posicao_ini, posicao_fim);
        }
    }

    return 0;
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
  int invertido = 0;

  if (num == 0)
    return 0;
  int negativo = 0;
  if (num < 0)
  {
    negativo = 1;
    num = -num;
  }
  while (num > 0)
  {
    invertido = invertido * 10 + (num % 10);
    num /= 10;
  }
  if (negativo)
    invertido = -invertido;
  return invertido;
}
/*int main()
{
    int invertido, num, resultado;
    printf ("Digite o número a ser invertido: \n");
    scanf ("%d", &num);

    printf("\n");
    resultado = q5(num);
    printf("Número invertido: %d\n", resultado);

    return 0;
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
  int tamanho_busca, tamanho_base, qtdOcorrencias = 0;
  char textobase[20], textobusca[10];
  sprintf(textobase, "%d", numerobase);
  sprintf(textobusca, "%d", numerobusca);
  tamanho_busca = strlen(textobusca);
  tamanho_base = strlen(textobase);

  for (int i = 0; i <= tamanho_base - tamanho_busca; i++)
  {
    int j;
    for (j = 0; j < tamanho_busca; j++)
    {
      if (textobase[i + j] != textobusca[j])
        break;
    }
    if (j == tamanho_busca)
      qtdOcorrencias++;
  }
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
  int encontrou = 0;
  int linha, coluna, indice, tamanho;
  char invertida[5];

  for (tamanho = 0; palavra[tamanho]; tamanho++);

  for (linha = tamanho - 1, coluna = 0; linha >= 0; linha--, coluna++)
    invertida[coluna] = palavra[linha];
  

  for (linha = 0; linha < 8 && !encontrou; linha++){
    for (coluna = 0; coluna < 10 - tamanho + 1 && !encontrou; coluna++){
      for (indice = 0; indice < tamanho; indice++){
        if (matriz[linha][coluna + indice] != palavra[indice] &&
            matriz[linha][coluna + indice] != invertida[indice]){
          break;
        }
      }
      if (indice == tamanho)
        encontrou = 1;
    }
  }

  for (linha = 0; linha < 10 - tamanho + 1 && !encontrou; linha++){
    for (coluna = 0; coluna < 8 && !encontrou; coluna++){
      for (indice = 0; indice < tamanho; indice++){
        if (matriz[coluna + indice][linha] != palavra[indice] &&
            matriz[coluna + indice][linha] != invertida[indice]){
          break;
        }
      }
      if (indice == tamanho)
        encontrou = 1;
    }
  }

  for (int linIni = 0; linIni < 8; linIni++){
    for (int colIni = 0; colIni < 10; colIni++){
      for (linha = linIni; linha < 8 && !encontrou; linha++){
        for (coluna = colIni; coluna < 10 && !encontrou; coluna++){
          for (indice = 0; indice < tamanho && coluna + indice < 10; indice++){
            if (matriz[linha + indice][coluna + indice] != palavra[indice] &&
                matriz[linha + indice][coluna + indice] != invertida[indice])
              break;
          }
          if (indice == tamanho)
            encontrou = 1;
        }
      }
    }
  }

  for (int linIni = 0; linIni < 8 && !encontrou; linIni++){
    for (int colIni = 10 - 1; colIni >= 0 && !encontrou; colIni--){
      for (linha = linIni; linha < 8 && !encontrou; linha++){
        for (coluna = colIni; coluna >= 0 && !encontrou; coluna--){
          for (indice = 0; indice < tamanho; indice++){
            if (matriz[linha + indice][coluna - indice] != palavra[indice] &&
                matriz[linha + indice][coluna - indice] != invertida[indice]){
              break;
          }
          if (indice == tamanho)
            encontrou = 1;
        }
      }
    }
  }
  }
  return encontrou;
}

void tratarString(char *strTexto) {
    int i, j;
    const char strComAcento[] = "ÄÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛÙüúûù"; 
    const char strSemAcento[] = "AAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUUuuuu";
    for(i = 0; strTexto[i] != '\0'; i++){
        for(j = 0; strComAcento[j] != '\0'; j++) {
            if(strTexto[i] == strComAcento[j]) {
                strTexto[i] = strSemAcento[j];
                break;
            }
        }
    }
}
