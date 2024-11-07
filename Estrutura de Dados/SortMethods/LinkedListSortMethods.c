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

node* getTail(node *head){
    node *current = head;
    while(current->ptr_next != NULL){
        current = current->ptr_next;
    }
    return current;
}

void printList(node *head){ // Itera sobre a lista e printa os valores de cada nó
    node *current = head;
    while(current != NULL){
        printf("%d ", current->valor);
        current = current->ptr_next;
    }
    printf("\n");
}

void swapValue(node *n1, node *n2){
    int valorTemp = n1->valor;
    n1->valor = n2->valor;
    n2->valor = valorTemp;
    return;
}

void bubbleSort(node *head){
    int counter = 0;
    node *current = head;
    if(head == NULL){
        return;
    }
    while(1){
        if(current->ptr_next == NULL && counter == 0){
            return;
        }
        if(current->ptr_next == NULL && counter != 0){
            current = head;
            counter = 0;
        }
        if(current->valor > current->ptr_next->valor){
            swapValue(current, current->ptr_next);
            counter++;
        }
        current = current->ptr_next;
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
            swapValue(head, head->ptr_next);
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

node *partition(node *head, node *tail){
    node *pivot = head;
    node *previous = head;
    node *current = head;
    int tempVal = 0;
    while(current != tail->ptr_next){
        if(current->valor < pivot->valor){
            swapValue(current, previous->ptr_next);
            previous = previous->ptr_next;
        }
        current = current->ptr_next;
    }
    swapValue(pivot, previous);
    return previous;
}

void intermediate(node *head, node *tail){
    if(head == NULL || head == tail){
        return;
    }
    node *pivot = partition(head, tail);
    intermediate(head, pivot);
    intermediate(pivot->ptr_next, tail);
}

void quickSort(node *head){
    node *tail = getTail(head);
    intermediate(head, tail);
    return;
}

node *split(node *head){
    node *end = head;
    node *middle = head;
    node *temp = NULL;
    while(end != NULL && end->ptr_next != NULL){
        end = end->ptr_next->ptr_next;
        if(end != NULL){
            middle = middle->ptr_next;
        }
    }
    temp = middle->ptr_next;
    middle->ptr_next = NULL;
    return temp;
}
    
node *merge(node *first, node *second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first->valor < second->valor){
        first->ptr_next = merge(first->ptr_next, second);
        return first;
    }
    else{
        second->ptr_next = merge(first, second->ptr_next);
        return second;
    }
}

node *mergeSort(node *head){
    if(head == NULL || head->ptr_next == NULL){
        return head;
    }
    node *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
    //TODO: Tentar utilizar void no retorno da função.
    //Motivo: Fica feio na main.
}

int main(){
    node *lista = NULL;
    lista = initList(lista, 3);
    addNode(lista, 8);
    addNode(lista, 1);
    addNode(lista, 6);
    addNode(lista, 12);
    addNode(lista, 8);
    addNode(lista, 2);
    addNode(lista, 85);
    addNode(lista, 3);
    addNode(lista, 7);
    addNode(lista, 2);
    printList(lista);
    lista = mergeSort(lista);
    printList(lista);
}