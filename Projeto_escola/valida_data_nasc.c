int validar_data(data d) {
    int dias_mes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // ano bissexto
    if ((d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0)) {
        dias_mes[2] = 29;
    }
    if (d.mes < 1 || d.mes > 12) return 0;
    if (d.dia < 1 || d.dia > dias_mes[d.mes]) return 0;
    if (d.ano < 1900 || d.ano > 2025) return 0;

    return 1; // data válida
}
