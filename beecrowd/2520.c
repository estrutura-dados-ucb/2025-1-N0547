#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        // com alocação estática
        // int matriz[n][m];

        // com alocacação dinâmica
        int **matriz = (int**) malloc(sizeof(int*)*n);

        for(int k = 0;k < m;k++){
            matriz[k] = (int*) malloc(sizeof(int)*m);
        }



        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        int xPok, yPok;
        int xPess, yPess;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matriz[i][j] == 1){
                    xPess = j;
                    yPess = i;
                }

                if(matriz[i][j] == 2){
                    xPok = j;
                    yPok = i;
                }
            }
        }


        printf("%d\n", abs(xPok - xPess) + abs(yPok - yPess));
    }

    


    return 0;
}