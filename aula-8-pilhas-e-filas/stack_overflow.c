#include <stdio.h>



/* fibonacci[47] = fibonacci[46] + fibonacci[45]
fibonacci[46] = fibonacci[45] + fibonacci[44]
fibonacci[45] = fibonacci[44] + fibonacci[43]
...
...
...
...
fibonacci[2] = fibonacci[1] + fibonacci[0]
fibonacci[1] = 1
fibonacci[0] = 0
 */

int fibonacci(int pos){
/*     if(pos == 0){
        return 0;
    } else if(pos == 1){
        return 1;
    } */

    return fibonacci(pos - 1) + fibonacci(pos - 2);
}



int main(){

    printf("fibonacci[30] = %d\n", fibonacci(30));
    return 0;
}