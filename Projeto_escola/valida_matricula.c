int validar_matricula(int matricula, pessoa lista[TAM], int qtd) {
    for (int i = 0; i < qtd; i++) {
        if (lista[i].matricula == matricula) {
            return 0;
        }
    }
    return 1;
}
