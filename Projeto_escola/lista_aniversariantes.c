void listar_aniversariantes(pessoa lista[TAM], int qtd) {
    // pegando o mes atual
    struct tm *data_atual; //ponteiro que vai armazenar data e hora
    time_t tempo; // variavel que vai armazenar os segundos
    time(&tempo); // obtendo o tempo em segundos
    data_atual = localtime(&tempo); // convetendo de segundos para o tempo local
    int mes = data_atual->tm_mon+1; // pegando o mes atual
    
    if (tam_lista(qtd) == LISTA_VAZIA){ // função que informa se a lista tá vazia ou cheia
        printf("Lista vazia!\n");
    } else {
        int achou = 0;
        printf("\nAniversariantes do mês %d:\n", mes);
        for (int i = 0; i < qtd; i++) {
            if (lista[i].data_nascimento.mes == mes) {
                printf("- %s (Dia: %02d/%02d/%04d)\n",
                       lista[i].nome,
                       lista[i].data_nascimento.dia,
                       lista[i].data_nascimento.mes,
                       lista[i].data_nascimento.ano);
                achou = 1;
            }
        }
    
        if (!achou) 
            printf("Nenhum aniversariante encontrado neste mês.\n");
    }
    
}
