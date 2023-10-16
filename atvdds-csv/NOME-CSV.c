#include <stdio.h>

int main() {
    FILE *file = fopen("entrada.csv", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[100]; // Tamanho arbitr�rio para a linha

    // Ler e imprimir o cabe�alho
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Cabe�alho: %s", line);
    }

    // Ler e imprimir os dados
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Dados: %s", line);
    }

    fclose(file);

    return 0;
}
