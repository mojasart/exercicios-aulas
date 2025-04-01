#include <stdio.h>

int main() {
    int numero;

    printf("Quantidade de numeros: ");
    scanf("%d", &numero);

    int arr[numero];

    for (int i = 0; i < numero; i++) {
        printf("numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < numero; i++){
        if(arr[i] < 5){
            printf("[%d] = %d \n", i, arr[i]);
        }
    }

            

    return 0;
}
