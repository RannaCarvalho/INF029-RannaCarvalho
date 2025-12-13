#include <stdio.h>

int posicoes (int a, int b, int c){
    int posicao_maior, posicao_menor;
    int menor, maior;
    
    if (a>b && a>c) {maior = a; posicao_maior = 1;}
    if (b>a && b>c) {maior = b; posicao_maior = 2;}
    if (c>b && c>a) {maior = c; posicao_maior = 3;}
    
    if (a<b && a<c) {menor = a; posicao_menor = 1;}
    if (b<a && b<c) {menor = b; posicao_menor = 2;}
    if (c<b && c<a) {menor = c; posicao_menor = 3;}
    
    return printf ("Menor: %d, Posicao: %d; Maior: %d, Posicao: %d", menor, posicao_menor, maior, posicao_maior);
    
}

int main (){
    int a, b, c;
    
    printf ("Digite os valores de a, b e c: \n");
    scanf ("%d %d %d", &a, &b, &c);
    
    posicoes (a, b, c);
}
