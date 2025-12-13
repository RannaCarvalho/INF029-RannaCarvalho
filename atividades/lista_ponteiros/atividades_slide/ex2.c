#include <stdio.h>

void troca(int *a, int b)
{
    *a = b;
}

int main()
{
    int i = 5, j = 8;
    
    troca(&i, j);
    
    printf("\n o resultado da troca:\n i:%d", i);
}
