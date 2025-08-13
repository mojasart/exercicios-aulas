#include <stdio.h>
void main(){
    int matriz[4][4];
    
    int i,j;
    int soma;
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Digite Valor p/ [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
            if(i==j){
            soma += matriz[i][i];
        }
        }
        printf("\n");
    }
    printf("\n matriz \n");
    for(i=0; i<4; i++){
        for(j=0;j<4;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("%d", soma);
}