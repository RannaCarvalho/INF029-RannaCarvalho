#include <stdio.h>

void executarExercicio() {
    int i;
    char c;
    char str[10];
    float f;
    double d;

    // Definição dos ponteiros
    int *pi = &i;
    char *pc = &c;
    char *pstr = str;
    float *pf = &f;
    double *pd = &d;

    printf("\n--- Leitura com Variaveis ---\n");
    
    printf("Digite um inteiro: ");
    scanf("%d", &i);

    printf("Digite um caracter: ");
    scanf(" %c", &c);

    printf("Digite uma string (max 9 caracters): ");
    scanf("%s", str);

    printf("Digite um float: ");
    scanf("%f", &f);

    printf("Digite um double: ");
    scanf("%lf", &d);

    printf("\n--- Saida com Variaveis ---\n");
    printf("Inteiro: %d\n", i);
    printf("Char: %c\n", c);
    printf("String: %s\n", str);
    printf("Float: %.2f\n", f);
    printf("Double: %.2lf\n", d);

    printf("\n--- Leitura com Ponteiros ---\n");

    printf("Digite um inteiro: ");
    scanf("%d", pi); 

    printf("Digite um char: ");
    scanf(" %c", pc);

    printf("Digite uma string: ");
    scanf("%s", pstr);

    printf("Digite um float: ");
    scanf("%f", pf);

    printf("Digite um double: ");
    scanf("%lf", pd);

    printf("\n--- Saida com Ponteiros ---\n");
    printf("Inteiro: %d\n", *pi); 
    printf("Char: %c\n", *pc);
    printf("String: %s\n", pstr); 
    printf("Float: %.2f\n", *pf);
    printf("Double: %.2lf\n", *pd);
}

int main() {
    executarExercicio();
    return 0;
}
