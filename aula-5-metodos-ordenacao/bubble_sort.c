#include <stdio.h>

int main(){
    int vetor[] = {9, 1, 2, 0, 5, 4, 3, 8, 6, 7};

    for(int j = 0;j < 10;j++){
        // repetir n vezes (n == tamanho do vetor)
        for(int i = 0; i < 10 - j;i++){
            if(vetor[i] > vetor[i+1]){
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i + 1] = aux;
            }
        }
    }

    for(int i = 0; i < 10;i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }


}