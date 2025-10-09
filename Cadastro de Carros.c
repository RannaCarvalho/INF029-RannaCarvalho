#include <stdio.h>
#define TAM 10

int main()
{
    int ano[TAM];
    int chassi[TAM];
    int i, j, qtd_carros=0, novo_cad;
    
   
    for(i = 0; i < TAM; i++){
        printf("Deseja cadastrar um novo carro?(1 - Sim; 2 - Não): ");
        scanf ("%d", &novo_cad);
        if (novo_cad == 1){
            printf("Digite o ano: ");
            scanf("%d", &ano[i]);
            printf("Digite o chassi: ");
            scanf("%d", &chassi[i]);
            qtd_carros++;
            printf ("\nQuantidade de carros cadastrados: %d\n", qtd_carros);
            printf("\n");
        }else {
            printf ("\nQuantidade de carros cadastrados: %d\n", qtd_carros);
            printf("\n");
        }
    }
}
