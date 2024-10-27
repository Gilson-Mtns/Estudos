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

int main(){
    node *lista = NULL;
    lista = initList(lista, 5);
    addNode(lista, 4);
    addNode(lista, 3);
    addNode(lista, 2);
    printList(lista);
    removeNode(lista, 3);
    printList(lista);
    removeNode(lista, 3);
    printList(lista);
    return 0;
}