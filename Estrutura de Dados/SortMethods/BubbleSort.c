#include <stdio.h>

int tamanho = 0;
int lista[12] = {3,6,2,7,9,1,2,3,1,5,3,8};

int arrayLenght(int array[]){
    int size = 0;
    while(array[size++]);
    return size-1;
}

void bubbleSort(int array[], int size){
    int counter = 0;
    int i = 0;
    while(1){
        if(array[i] > array[i+1]){
            counter += 1;
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
        i++;
        if(counter == 0 && i >= size-1){
            return;
        }
        if(counter > 0 && i >= size-1){
            counter = 0;
            i = 0;
        }
    }
}

int main(){
    tamanho = arrayLenght(lista);
    bubbleSort(lista, tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
    return 0;
}