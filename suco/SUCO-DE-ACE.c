#include <stdio.h>

int main() {
    FILE *inputFile = fopen("suco.in.txt", "r");
    FILE *outputFile = fopen("suco.out.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    int N, F;

    while (1) {
        fscanf(inputFile, "%d %d", &N, &F);

        if (N == 0 && F == 0) {
            break;
        }

        double volumeSuco = (double)F / (N * 50);
        fprintf(outputFile, "%.2lf\n", volumeSuco);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
