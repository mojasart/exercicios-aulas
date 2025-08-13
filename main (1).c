#include <stdio.h>
void main(){
    int matriz[3][3];
    
    int i,j;
    int cont = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite Valor p/ [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n matriz \n");
    for(i=0; i<3; i++){
        for(j=0;j<3;j++){
            printf("%d ", matriz[i][j]);
            if(matriz[i][j] %2 == 0){
                cont++;
            }
        }
        printf("\n");
    }
    printf("Numeros Pares: %d", cont);
}