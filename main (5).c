#include <stdio.h>

int main(void) {
    int mat[4][4];
    int i, j, soma = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("coloque o valor para mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nmatriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i + j == 3) {
                soma += mat[i][j];
            }
        }
    }
    printf("\nSoma da diagonal secundaria: %d\n", soma);

    return 0;
}
