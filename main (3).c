#include <stdio.h>
void main(){
    int matriz[2][4];
    
    int i,j;
    int soma;
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){
            printf("Digite Valor p/ [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
            soma += matriz[0][j];
        }
        printf("\n");
    }
    printf("\n matriz \n");
    for(i=0; i<2; i++){
        for(j=0;j<4;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("%d", soma);
}