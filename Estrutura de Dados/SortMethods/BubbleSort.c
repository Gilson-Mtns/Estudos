#include <stdio.h>

int tamanho = 12;
int lista[12] = {3,6,2,7,9,1,2,3,1,5,3,8};

void bubbleSort(int array[], int size){
    int counter = 0;
    for(int i = 0; i <= size-2; i++){
        if(array[i] > array[i+1]){
            counter += 1;
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    if(counter > 0){
        return bubbleSort(array, size);
    }
}

int main(){
    bubbleSort(lista, tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
}