#include <stdio.h>

int encontrarMaior(int* vetor, int ultimaPos){
    int valorMaiorEl = -1;
    int indiceMaiorEl = -1;
    for(int i = 0; i <= ultimaPos;i++){
        if(vetor[i] > valorMaiorEl){
            valorMaiorEl = vetor[i];
            indiceMaiorEl = i;
        }
    }
    return indiceMaiorEl;
}


int main(){
    int vetor[] = {9, 1, 2, 0, 5, 4, 3, 8, 6, 7};
    int ultimaPos = 9;

    for(int i = 0; i < 10;i++){
        int indiceMaior = encontrarMaior(vetor, ultimaPos);
        int aux = vetor[indiceMaior];
        vetor[indiceMaior] = vetor[ultimaPos];
        vetor[ultimaPos] = aux;
        ultimaPos--;
    }

    for(int i = 0; i < 10;i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }


}