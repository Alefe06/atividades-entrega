#include <stdio.h>
#define MAX_SIZE 100
struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void createQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("A fila esta cheia. Nao eh possível enfileirar mais elementos.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->data[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia. Nao eh possivel desenfileirar elementos.\n");
        return -1;
    }
    int data = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return data;
}

void displayQueue(struct Queue* queue) {
	int i;
    if (isEmpty(queue)) {
        printf("a fila esta vazia.\n");
        return;
    }
    printf("Fila: ");
    for ( i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    createQueue(&queue);
    int choice, data;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Enfileirar elemento\n");
        printf("2. Desenfileirar elemento\n");
        printf("3. Sair\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                displayQueue(&queue);
                break;

            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Elemento desenfileirado: %d\n", data);
                }
                displayQueue(&queue);
                break;

            case 3:
                printf("Encerrando o programa.\n");
                return 0;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
