#include <stdio.h>

int tamanho = 12;
int lista[12] = {3,6,2,7,9,1,2,3,1,5,3,8};

void insertionSort(int array[], int size){
    for(int i = 1;i < size; i++){
        int parameter = array[i];
        int j = i - 1;
    
        while(j >= 0 && array[j] > parameter){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = parameter;
    }
}

int main(){
    insertionSort(lista, tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
    return 0;
}