#include <stdio.h>

int soma(int a, int b)
{
    int *p = &a;
    int *q = &b;
    
    int c = *p + *q;

    return c;
}

int main()
{
    int a, b;
    int c;
    
    printf ("digite dois inteiros a ser somados: \n");
    scanf ("%d %d", &a, &b);
    
    c = soma(a, b);
    
    printf("\n o resultado da soma: %d", c);
}
