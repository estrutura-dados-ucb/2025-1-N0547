#include <stdio.h>

int main(){
    int valor;
    int pares[5];
    int impares[5];
    int ultPosPares = 0;
    int ultPosImpares = 0;

    for(int i = 0;i < 15;i++){
        scanf("%d", &valor);
        // se for par
        if(valor%2 == 0){
            pares[ultPosPares] = valor;
            ultPosPares++;
            if(ultPosPares == 5){
                for(int j = 0;j < 5;j++){
                   printf("par[%d] = %d\n", j, pares[j]); 
                }
                ultPosPares = 0;
            }
        } 
        
        // se for ímpar
        else {
            impares[ultPosImpares] = valor;
            ultPosImpares++;
            if(ultPosImpares == 5){
                for(int j = 0;j < 5;j++){
                   printf("impar[%d] = %d\n", j, impares[j]); 
                }
                ultPosImpares = 0;
            }
        }
    }

    if(ultPosImpares > 0){
        for(int j = 0;j < ultPosImpares;j++){
            printf("impar[%d] = %d\n", j, impares[j]); 
        }
    }
    if(ultPosPares > 0){
        for(int j = 0;j < ultPosPares;j++){
            printf("par[%d] = %d\n", j, pares[j]); 
        }
    }



    return 0;
}