#include <stdio.h>

int main() {
    FILE *entrada = fopen("esquerda.in.txt", "r");
    FILE *saida = fopen("esquerda.out.txt", "w");

    int N, i;

    while (1) {
        fscanf(entrada, "%d", &N);
        if (N == 0) {
            break;
        }

        char comandos[1001];
        fscanf(entrada, "%s", comandos);

        char direcao = 'N';

        for (i = 0; i < N; i++) {
            if (comandos[i] == 'E') {
                if (direcao == 'N') {
                    direcao = 'O';
                } else if (direcao == 'O') {
                    direcao = 'S';
                } else if (direcao == 'S') {
                    direcao = 'L';
                } else if (direcao == 'L') {
                    direcao = 'N';
                }
            } else if (comandos[i] == 'D') {
                if (direcao == 'N') {
                    direcao = 'L';
                } else if (direcao == 'L') {
                    direcao = 'S';
                } else if (direcao == 'S') {
                    direcao = 'O';
                } else if (direcao == 'O') {
                    direcao = 'N';
                }
            }
        }

        fprintf(saida, "%c\n", direcao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
