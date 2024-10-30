#include <stdlib.h>
#include <stdio.h>

typedef struct Node{ // Estrutura de uma lista encadeada.
    int valor;
    struct Node *ptr_next;
} node;

node* initList(node *head, int val){ // Inicializa uma lista encadeada adicionando seu primeiro valor e definindo seu ponteiro para NULL.
    head = (node*)malloc(sizeof(node));
    head->valor = val;
    head->ptr_next = NULL;
    return head;
}

void addNode(node *head, int val){ // Itera sobre a lista e adiciona um novo nó ao final dela com o valor especificado.
    node *current = head;
    while(current->ptr_next != NULL){
        current = current->ptr_next;
    }
    current->ptr_next = (node*)malloc(sizeof(node));
    current = current->ptr_next;
    current->valor = val;
    current->ptr_next = NULL;
}

void removeNode(node *head, int val){ // Itera sobre a lista buscando o nó com o valor especificado e o remove.
    node *current = head;
    node * previous = NULL;
    while(current->valor != val){
        if(current->ptr_next == NULL){
        return;
        }
        previous = current;
        current = current->ptr_next;
    }
    if(current->valor == val){
        previous->ptr_next = current->ptr_next;
        free(current);
    }
}

void printList(node *head){ // Itera sobre a lista e printa os valores de cada nó
    node *current = head;
    while(current != NULL){
        printf("%d ", current->valor);
        current = current->ptr_next;
    }
    printf("\n");
}

/*void bubbleSort(node *head){
    int counter = 0;
    node *previous = NULL;
    node *current = head;
    node *temp1 = NULL;
    node *temp2 = NULL;
    while(current->ptr_next != NULL){
        if(current->valor > current->ptr_next->valor){
            counter += 1;
            temp1 = previous->ptr_next;
            temp2 = current->ptr_next->ptr_next;
            previous->ptr_next = current->ptr_next;
            current->ptr_next->ptr_next = temp1;
            current->ptr_next = temp2;
        }
        previous = current;
        current = current->ptr_next;
    }
    free(temp1);
    free(temp2);
    if(counter > 0){
        return bubbleSort(head);
    }
}*/
// Implementação alterando ponteiros (Código rodando pra sempre)

void bubbleSort(node *head){
    int counter = 0;
    node *current = head;
    int temp = 0;

    while(current->ptr_next != NULL){
        if(current->valor > current->ptr_next->valor){
            counter += 1;
            temp = current->valor;
            current->valor = current->ptr_next->valor;
            current->ptr_next->valor = temp;
        }
        current = current->ptr_next;
    }
    if(counter > 0){
        return bubbleSort(head);
    }
}

int main(){
    node *lista = NULL;
    lista = initList(lista, 3);
    addNode(lista, 8);
    addNode(lista, 7);
    addNode(lista, 6);
    printList(lista);
    bubbleSort(lista);
    printList(lista);
}