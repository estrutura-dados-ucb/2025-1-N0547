#include <stdio.h>

int funcao1(int a){
    return a + 42;
}

int funcao2(int a){
    return funcao1(a);
}

int funcao3(int a){
    return funcao2(a);
}



int main(){

    printf("funcao3(30) = %d\n", funcao3(30));
    return 0;
}