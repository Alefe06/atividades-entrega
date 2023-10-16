#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int id;
    char nome[50];
    char nascimento[11];
    int idade;
};

int calculateAge(const char* birthdate) {
    // Implemente a lógica para calcular a idade a partir da data de nascimento.
    // Neste exemplo, a idade é calculada subtraindo o ano de nascimento do ano atual.
    int birthYear, currentYear;
    sscanf(birthdate, "%d-%*2s-%*2s", &birthYear);
    sscanf("2023-10-09", "%d-%*2s-%*2s", &currentYear);
    return currentYear - birthYear;
}

int main() {
    FILE *inputFile = fopen("entrada.csv", "r");
    FILE *outputFile = fopen("saida.csv", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Ler e escrever o cabeçalho
    char header[100]; // Tamanho arbitrário para a linha
    fgets(header, sizeof(header), inputFile);
    fprintf(outputFile, "%sIdade\n", header);

    // Processar os dados
    struct Person person;
    while (fscanf(inputFile, "%d;%49[^;];%10[^;]\n", &person.id, person.nome, person.nascimento) == 3) {
        person.idade = calculateAge(person.nascimento);
        fprintf(outputFile, "%d;%s;%s;%d\n", person.id, person.nome, person.nascimento, person.idade);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
