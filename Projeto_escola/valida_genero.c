char validar_genero() {
    char sexo;
    do {
        printf("Insira o sexo [F/M/O]: ");
        scanf(" %c", &sexo);
        fflush(stdin);

        if (sexo >= 'a' && sexo <= 'z') {
            sexo = sexo - 32;
        }

        if (sexo != 'F' && sexo != 'M' && sexo != 'O') {
            printf("Opção inválida! Use apenas F (Feminino), M (Masculino) ou O (Outro).\n");
        }

    } while (sexo != 'F' && sexo != 'M' && sexo != 'O');

    return sexo;
}
