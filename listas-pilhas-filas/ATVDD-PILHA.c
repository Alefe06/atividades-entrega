#include <stdio.h>
#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void createStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("a pilha esta cheia. Nao eh possivel empilhar mais elementos.\n");
        return;
    }
    stack->data[++stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("a pilha esta vazia. Nao eh possível desempilhar elementos.\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

void displayStack(struct Stack* stack) {
	int i;
    if (isEmpty(stack)) {
        printf("a pilha esta vazia.\n");
        return;
    }
    printf("Pilha: ");
    for ( i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    createStack(&stack);
    int choice, data;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Sair\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &data);
                push(&stack, data);
                displayStack(&stack);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Elemento desempilhado: %d\n", data);
                }
                displayStack(&stack);
                break;

            case 3:
                printf("Encerrando o programa.\n");
                return 0;

            default:
                printf("opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
