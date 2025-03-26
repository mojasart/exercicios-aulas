#include <stdio.h>

int main() {
    int quantNumeros, maiorSeq = 1, seqAtual = 1;
    int inicioMaior = 0, fimMaior = 0;
    int inicioAtual = 0;

    printf("Numero de Alunos: ");
    scanf("%d", &quantNumeros);

    int listaDeNumeros[quantNumeros];

    for (int i = 0; i < quantNumeros; i++) {
        printf("Numeros %d: ", i + 1);
        scanf("%d", &listaDeNumeros[i]);
    }
    
    for (int j = 1; j < quantNumeros; j++) {
        if (listaDeNumeros[j] > listaDeNumeros[j - 1]) {
            seqAtual++;
        } else {
            if (seqAtual > maiorSeq) { 
                maiorSeq = seqAtual;
                inicioMaior = inicioAtual;
                fimMaior = j - 1;
            }
            seqAtual = 1;  
            inicioAtual = j;
        }
    }


    if (seqAtual > maiorSeq) {
        maiorSeq = seqAtual;
        inicioMaior = inicioAtual;
        fimMaior = quantNumeros - 1;
    }

    printf("\nMaior segmento crescente:\n");
    for (int k = inicioMaior; k <= fimMaior; k++) {
        printf("%d ", listaDeNumeros[k]);
    }
    printf("\n");

    return 0;
}
