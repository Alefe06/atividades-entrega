#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
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
    struct Node* list = NULL;
    int choice, data;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento no inicio da lista\n");
        printf("2. Remover elemento do inicio da lista\n");
        printf("3. Mostrar lista\n");
        printf("4. Sair\n");

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
                printf("Encerrando o programa.\n");
               
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
