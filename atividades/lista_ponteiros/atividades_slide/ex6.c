#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

int lerdata (Data *p){
    printf ("Digite uma data");
    printf("Dia: ");
    scanf ("%d", &p->dia);
    printf("\nMes: ");
    scanf ("%d", &p->mes);
    printf("Ano: ");
    scanf ("%d", &p->ano);
}
