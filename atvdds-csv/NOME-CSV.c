#include <stdio.h>

int main() {
    FILE *file = fopen("entrada.csv", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[100]; // Tamanho arbitrário para a linha

    // Ler e imprimir o cabeçalho
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Cabeçalho: %s", line);
    }

    // Ler e imprimir os dados
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Dados: %s", line);
    }

    fclose(file);

    return 0;
}
