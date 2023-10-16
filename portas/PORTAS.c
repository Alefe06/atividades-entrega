#include <stdio.h>

void encontrarPortasAbertas(int N, FILE *saida) {
	int i, j;
    int portas[N + 1]; 
    for ( i = 1; i <= N; i++) {
        portas[i] = 0; 
    }

    for (i = 1; i <= N; i++) {
        for ( j = i; j <= N; j += i) {
            portas[j] = 1 - portas[j];
        }
    }

    int primeiro = 1; 
    for ( i = 1; i <= N; i++) {
        if (portas[i] == 1) {
            if (!primeiro) {
                fprintf(saida, " ");
            }
            fprintf(saida, "%d", i);
            primeiro = 0;
        }
    }
    fprintf(saida, "\n");
}

int main() {
    FILE *entrada = fopen("portas.in.txt", "r");
    FILE *saida = fopen("portas.out.txt", "w");

    int N;
    while (1) {
        fscanf(entrada, "%d", &N);
        if (N == 0) {
            break; 
        }

        encontrarPortasAbertas(N, saida); 
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
