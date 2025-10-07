int validar_cpf(char cpf[CPF]) {
    int i, j, soma, resto;
    int digitos[11], qtd = 0;

    for (i = 0; cpf[i] != '\0' && qtd < 11; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            digitos[qtd++] = cpf[i] - '0';
        }
    }

    if (qtd != 11) return 0;

    int iguais = 1;
    for (i = 1; i < 11; i++) {
        if (digitos[i] != digitos[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) return 0;

    soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += digitos[i] * j;
    }
    resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;
    if (digito1 != digitos[9]) return 0;

    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += digitos[i] * j;
    }
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;
    if (digito2 != digitos[10]) return 0;

    return 1; 
}
