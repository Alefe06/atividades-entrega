#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Stack {
    struct Node* top;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memoria para o no.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("A pilha esta vazia. Nao eh possivel desempilhar elementos.\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("A fila esta vazia. Nao eh possivel desenfileirar elementos.\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* removeFront(struct Node* head) {
    if (head == NULL) {
        printf("A lista esta vazia. Nao eh possivel remover elementos.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void displayStack(struct Node* top) {
    struct Node* current = top;
    if (current == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayQueue(struct Node* front) {
    struct Node* current = front;
    if (current == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }
    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    struct Queue queue;
    struct Node* list = NULL;
    int choice, data;

    while (1) {
        printf("\nEscolha uma estrutura de dados:\n");
        printf("1. Pilha\n");
        printf("2. Fila\n");
        printf("3. Lista\n");
        printf("4. Sair\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stack.top = NULL; 
                while (1) {
                    printf("\nEscolha uma operacao para a pilha:\n");
                    printf("1. Empilhar elemento\n");
                    printf("2. Desempilhar elemento\n");
                    printf("3. Mostrar pilha\n");
                    printf("4. Voltar ao menu anterior\n");

                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Digite o valor a ser empilhado: ");
                            scanf("%d", &data);
                            push(&stack, data);
                            displayStack(stack.top);
                            break;

                        case 2:
                            data = pop(&stack);
                            if (data != -1) {
                                printf("Elemento desempilhado: %d\n", data);
                            }
                            displayStack(stack.top);
                            break;

                        case 3:
                            displayStack(stack.top);
                            break;

                        case 4:
                            break;

                        default:
                            printf("Opçãcao invalida. Tente novamente.\n");
                    }

                    if (choice == 4) {
                        break;
                    }
                }
                break;

            case 2: 
                queue.front = queue.rear = NULL;
                while (1) {
                    printf("\nEscolha uma operacao para a fila:\n");
                    printf("1. Enfileirar elemento\n");
                    printf("2. Desenfileirar elemento\n");
                    printf("3. Mostrar fila\n");
                    printf("4. Voltar ao menu anterior\n");

                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Digite o valor a ser enfileirado: ");
                            scanf("%d", &data);
                            enqueue(&queue, data);
                            displayQueue(queue.front);
                            break;

                        case 2:
                            data = dequeue(&queue);
                            if (data != -1) {
                                printf("Elemento desenfileirado: %d\n", data);
                            }
                            displayQueue(queue.front);
                            break;

                        case 3:
                            displayQueue(queue.front);
                            break;

                        case 4:
                            break;

                        default:
                            printf("Opçcao invalida. Tente novamente.\n");
                    }

                    if (choice == 4) {
                        break;
                    }
                }
                break;

            case 3: 
                while (1) {
                    printf("\nEscolha uma operacao para a lista:\n");
                    printf("1. Inserir elemento no inicio da lista\n");
                    printf("2. Remover elemento do inicio da lista\n");
                    printf("3. Mostrar lista\n");
                    printf("4. Voltar ao menu anterior\n");

                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Digite o valor a ser inserido na lista: ");
                            scanf("%d", &data);
                            list = insertFront(list, data);
                            displayList(list);
                            break;

                        case 2:
                            list = removeFront(list);
                            displayList(list);
                            break;

                        case 3:
                            displayList(list);
                            break;

                        case 4:
                            break;

                        default:
                            printf("Opcao invalida. Tente novamente.\n");
                    }

                    if (choice == 4) {
                        break;
                    }
                }
                break;

            case 4: 
                printf("Encerrando o programa.\n");
                
                while (stack.top != NULL) {
                    struct Node* temp = stack.top;
                    stack.top = stack.top->next;
                    free(temp);
                }
                while (queue.front != NULL) {
                    struct Node* temp = queue.front;
                    queue.front = queue.front->next;
                    free(temp);
                }
                while (list != NULL) {
                    struct Node* temp = list;
                    list = list->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
