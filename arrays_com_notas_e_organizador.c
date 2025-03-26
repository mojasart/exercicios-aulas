#include <stdio.h>

int main() {
    int quantAlunos;

    printf("Numero de Alunos: ");
    scanf("%d", &quantAlunos);

    int notasDosAlunos[quantAlunos];

    for (int i = 0; i < quantAlunos; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%d", &notasDosAlunos[i]);
    }

    for (int i = 0; i < quantAlunos - 1; i++) {
        for (int j = 0; j < quantAlunos - i - 1; j++) {
            if (notasDosAlunos[j] < notasDosAlunos[j + 1]) {
                int temp = notasDosAlunos[j];
                notasDosAlunos[j] = notasDosAlunos[j + 1];
                notasDosAlunos[j + 1] = temp;
            }
        }
    }

    printf("Notas em ordem decrescente: ");
    for (int i = 0; i < quantAlunos; i++) {
        printf("%d ", notasDosAlunos[i]);
    }

    return 0;
}
