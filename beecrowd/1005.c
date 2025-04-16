#include <stdio.h>

int main(){
    double a, b;

    scanf("%lf", &a);
    scanf("%lf", &b);

    double media = (3.5*a + 7.5*b)/11;

    printf("MEDIA = %.5lf\n", media);


    return 0;
}