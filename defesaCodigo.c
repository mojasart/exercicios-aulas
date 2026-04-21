#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char sintoma[100];
} Paciente;

typedef struct NoFila {
    Paciente p;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

void iniciarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila* f, Paciente p) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    novo->p = p;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Paciente desenfileirar(Fila* f) {
    NoFila* temp = f->inicio;
    Paciente p = temp->p;
    f->inicio = temp->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return p;
}

typedef struct NoPilha {
    Paciente p;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

void iniciarPilha(Pilha* p) {
    p->topo = NULL;
}

void empilhar(Pilha* p, Paciente paciente) {
    NoPilha* novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->p = paciente;
    novo->prox = p->topo;
    p->topo = novo;
}

void mostrarHistorico(Pilha* p) {
    NoPilha* atual = p->topo;
    printf("\n--- HISTORICO DE ATENDIMENTOS ---\n");
    while (atual != NULL) {
        printf("Nome: %s | Idade: %d | Sintoma: %s\n",
               atual->p.nome,
               atual->p.idade,
               atual->p.sintoma);
        atual = atual->prox;
    }
}

int main() {
    Fila fila;
    Pilha historico;
    iniciarFila(&fila);
    iniciarPilha(&historico);
    int opcao;

    do {
        printf("\n1 - add paciente\n");
        printf("2 - atender paciente\n");
        printf("3 - mostra historico\n");
        printf("4 - tirar o proximo da fila\n");
        printf("0 - sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Paciente p;
            printf("nome: ");
            fgets(p.nome, 50, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;
            printf("idade: ");
            scanf("%d", &p.idade);
            getchar();
            printf("sintoma: ");
            fgets(p.sintoma, 100, stdin);
            p.sintoma[strcspn(p.sintoma, "\n")] = 0;
            enfileirar(&fila, p);
        }
        else if (opcao == 2) {
            if (fila.inicio != NULL) {
                Paciente atendido = desenfileirar(&fila);
                printf("atendendo: %s\n", atendido.nome);
                empilhar(&historico, atendido);
            } else {
                printf("nenhum paciente na fila\n");
            }
        }
        else if (opcao == 3) {
            mostrarHistorico(&historico);
        }
        else if (opcao == 4) {
            if (fila.inicio != NULL) {
                Paciente removido = desenfileirar(&fila);
                printf("paciente %s removido da fila\n", removido.nome);
            } else {
                printf("nenhum paciente na fila\n");
            }
        }
    } while (opcao != 0);

    return 0;
}
