#include <stdio.h>

int multiplica(int a, int b){
    return a * b;
}

int soma(int x, int y){
    return x + y;
}

int main()
{
    int a, b, c, d;
    int mult1, mult2, resultado;
    
    printf("Digite dois numeros a serem multiplicados: \n");
    scanf("%d %d", &a, &b);
    
    printf("Digite mais dois numeros a serem multiplicados: \n");
    scanf("%d %d", &c, &d);
    
    mult1 = multiplica(a, b);
    mult2 = multiplica(c, d);
    
    resultado = soma(mult1, mult2);
    
    printf("O resultado final: %d\n", resultado);

    return 0;
}
