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

void bubbleSort(node *head){
    int counter = 0;
    node *previous = NULL;
    node *current = head;
    node *temp1 = NULL;
    node *temp2 = NULL;
    while(1){
        if(head->valor > head->ptr_next->valor){
            counter++;
            int valorTemp = head->valor;
            head->valor = head->ptr_next->valor;
            head->ptr_next->valor = valorTemp;
        }
        if(current->ptr_next == NULL && counter == 0){
            return;
        }
        if(current->ptr_next == NULL && counter != 0){
            counter = 0;
            current = head;
            previous = NULL;
        }
        if(current->valor > current->ptr_next->valor){
            counter++;
            temp1 = previous->ptr_next;
            temp2 = current->ptr_next->ptr_next;
            previous->ptr_next = current->ptr_next;
            current->ptr_next->ptr_next = temp1;
            current->ptr_next = temp2;
            current = previous->ptr_next;
        }
        else if(current->valor <= current->ptr_next->valor){
            previous = current;
            current = current->ptr_next;
        }
    }
}

void insertionSort(node *head){
    node *parameter = head->ptr_next;
    node *comparator = head;
    node *next = parameter->ptr_next;
    node *previousParameter = head;
    node *temp1 = NULL;
    node *temp2 = NULL;
    node *temp3 = NULL;
    while(parameter != NULL){
        if(head->valor > head->ptr_next->valor){
            int valorTemp = head->valor;
            head->valor = head->ptr_next->valor;
            head->ptr_next->valor = valorTemp;
        }
        if(next != NULL && comparator->ptr_next == parameter){
            previousParameter = parameter;
            parameter = next;
            next = next->ptr_next;
            comparator = head;
        }
        if(comparator->ptr_next->valor <= parameter->valor){
            comparator = comparator->ptr_next;
        }
        if(comparator->ptr_next->valor > parameter->valor){
            temp1 = previousParameter->ptr_next;
            temp2 = comparator->ptr_next;
            temp3 = parameter->ptr_next;
            comparator->ptr_next = temp1;
            parameter->ptr_next = temp2;
            previousParameter->ptr_next = temp3;
            parameter = next;
            comparator = head;
            if(next != NULL){
                next = next->ptr_next;
            }
        }
    }
}

void swapValue(node *n1, node *n2){
    int valorTemp = n1->valor;
    n1->valor = n2->valor;
    n2->valor = valorTemp;
    return;
}

void quickSort(node *head){
    node *pivot = head;
    node *left = NULL;
    node *right = pivot->ptr_next;
    while(left == NULL && right != NULL){
        if(right->valor < pivot->valor){
            swapValue(right, pivot);
        }
        right = right->ptr_next;
    }
    pivot = pivot->ptr_next;
    left = head;
    right = pivot->ptr_next;
    while(pivot->ptr_next != NULL){
        while(left->ptr_next != pivot && right->ptr_next != NULL){
            while(left->ptr_next != pivot && left->valor < pivot->valor){
                left = left->ptr_next;
            }
            while(right->ptr_next != NULL && right->valor > pivot->valor){
                right = right->ptr_next;
            }
            if(left->valor > pivot->valor && right->valor < pivot->valor){
                swapValue(left, right);
            }
            if(left->valor > pivot->valor && right->valor >= pivot->valor){
                swapValue(left, pivot);
            }
            if(left->valor <= pivot->valor && right->valor < pivot->valor){
                swapValue(right, pivot);
            }
        }
        left = head;
        pivot = pivot->ptr_next;
        right = pivot->ptr_next;
    }
    while(right == NULL & left != pivot){
        if(left->valor > pivot->valor){
            swapValue(left, pivot);
        }
        left = left->ptr_next;
    }
}
    
int main(){
    node *lista = NULL;
    lista = initList(lista, 3);
    addNode(lista, 8);
    addNode(lista, 1);
    addNode(lista, 6);
    addNode(lista, 12);
    addNode(lista, 7);
    addNode(lista, 2);
    printList(lista);
    quickSort(lista);
    printList(lista);
}