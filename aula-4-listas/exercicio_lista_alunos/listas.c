#include <stdio.h>
#include <stdlib.h>

/* void imprimirLista(int* lista, int tamanho){
    for(int i = 0;i < tamanho;i++){
        printf("lista[%d] = %d\n", i, lista[i]);
    }
} */


int main(){

    // Alocação estática
    // int valores[5];

    // Alocação dinâmica
    // vetor com 5 posições
    int *valores = (int*) malloc(5*sizeof(int));

    valores[4] = 42;
    printf("valores[4] = %d\n", valores[4]);
    realloc(valores, 2);

    printf("Depois de realocar...\n");
    printf("valores[4] = %d\n", valores[4]);
    valores[18] = 1;


    return 0;
}