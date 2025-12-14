#include <stdio.h>

int divisao (int *p){
    int resto = *p % 10;
    *p /= 10;
    return printf ("resto: %d\n", resto);
}

int main()
{
    int num;
    
    printf("Digite o numero a ser dividido: ");
    scanf("%d", &num);
    
    divisao (&num);
    
    printf ("divisao: %d", num);
    return 0;
}
