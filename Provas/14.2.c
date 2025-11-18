#include <stdio.h>

int multiplica (int a, int b){
    int mult;
    
    mult = a*b;
}
int main()
{
    int a, b, resultado;
    
    printf("digite dois numeros a serem multiplicados: \n");
    scanf ("%d %d", &a, &b);
    
    resultado = multiplica(a, b);
    
    printf("%d x %d: %d", a, b, resultado);

    return 0;
}
