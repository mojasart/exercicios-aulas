#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 8
#define MAX_NOME    30

/* definindo as structs */

typedef struct {
    char nomes[MAX_CIDADES][MAX_NOME];
    int  matriz[MAX_CIDADES][MAX_CIDADES];
    int  num_cidades;
} Grafo;

/* fila pra fazer bfs (menor caminho em numero de paradas) */

typedef struct {
    int dados[MAX_CIDADES * 2];
    int inicio, fim, tamanho;
} Fila;

void fila_init(Fila *f) { f->inicio = 0; f->fim = -1; f->tamanho = 0; }
int  fila_vazia(Fila *f) { return f->tamanho == 0; }

void enfileirar(Fila *f, int v) {
    f->fim = (f->fim + 1) % (MAX_CIDADES * 2);
    f->dados[f->fim] = v;
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    int v = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % (MAX_CIDADES * 2);
    f->tamanho--;
    return v;
}

/* grafosss */

void grafo_init(Grafo *g) {
    g->num_cidades = 0;
    memset(g->matriz, 0, sizeof(g->matriz));
}

int adicionar_cidade(Grafo *g, const char *nome) {
    int id = g->num_cidades;
    strncpy(g->nomes[id], nome, MAX_NOME - 1);
    g->num_cidades++;
    return id;
}

void adicionar_estrada(Grafo *g, int a, int b) {
    g->matriz[a][b] = 1;
    g->matriz[b][a] = 1; /* a estrada vai nos dois sentidos */
}

/* mostra */

void exibir_grafo(Grafo *g) {
    int n = g->num_cidades;

    printf("=========================================\n");
    printf("   MAPA DE ROTAS - CIDADES DO PARANA\n");
    printf("=========================================\n");
    printf("Cidades cadastradas: %d\n\n", n);

    /* adjacencia */
    for (int i = 0; i < n; i++) {
        printf("  %-15s --> ", g->nomes[i]);
        int tem = 0;
        for (int j = 0; j < n; j++) {
            if (g->matriz[i][j]) {
                printf("%s  ", g->nomes[j]);
                tem = 1;
            }
        }
        if (!tem) printf("(sem conexao)");
        printf("\n");
    }

    printf("\nMatriz de Adjacencia:\n     ");
    for (int j = 0; j < n; j++) printf("%-4d", j);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("  %d  ", i);
        for (int j = 0; j < n; j++) {
            printf("%-4d", g->matriz[i][j]);
        }
        printf("  (%s)\n", g->nomes[i]);
    }
    printf("=========================================\n\n");
}

/* bfs busca em lagura e n profundidade */

void bfs(Grafo *g, int inicio) {
    int n = g->num_cidades;
    int visitado[MAX_CIDADES] = {0};
    int nivel[MAX_CIDADES];
    memset(nivel, -1, sizeof(nivel));

    Fila f;
    fila_init(&f);

    visitado[inicio] = 1;
    nivel[inicio] = 0;
    enfileirar(&f, inicio);

    printf("--- BFS a partir de \"%s\" ---\n", g->nomes[inicio]);
    printf("(Descobre cidades em ordem de distancia - numero de paradas)\n\n");

    int nivel_impresso = -1;

    while (!fila_vazia(&f)) {
        int v = desenfileirar(&f);

        if (nivel[v] != nivel_impresso) {
            nivel_impresso = nivel[v];
            printf("  Paradas: %d  -->  %s\n", nivel_impresso, g->nomes[v]);
        } else {
            printf("            -->  %s\n", g->nomes[v]);
        }

        for (int j = 0; j < n; j++) {
            if (g->matriz[v][j] && !visitado[j]) {
                visitado[j] = 1;
                nivel[j] = nivel[v] + 1;
                enfileirar(&f, j);
            }
        }
    }
    printf("\n");
}

/* dfs, n garante menor rota explora tudo possivel, por profundidade */


void dfs_recursiva(Grafo *g, int v, int *visitado, int prof) {
    visitado[v] = 1;
    for (int i = 0; i < prof; i++) printf("  ");
    printf("|-- %s\n", g->nomes[v]);

    for (int j = 0; j < g->num_cidades; j++) {
        if (g->matriz[v][j] && !visitado[j]) {
            dfs_recursiva(g, j, visitado, prof + 1);
        }
    }
}

void dfs(Grafo *g, int inicio) {
    int visitado[MAX_CIDADES] = {0};
    printf("--- DFS a partir de \"%s\" ---\n", g->nomes[inicio]);
    printf("(Exploracao em profundidade - todas as rotas alcancaveis)\n\n");
    dfs_recursiva(g, inicio, visitado, 0);
    printf("\n");
}

/* menor caminho, usando bfs */

void menor_caminho(Grafo *g, int origem, int destino) {
    int n = g->num_cidades;
    int visitado[MAX_CIDADES] = {0};
    int anterior[MAX_CIDADES];
    memset(anterior, -1, sizeof(anterior));

    Fila f;
    fila_init(&f);
    visitado[origem] = 1;
    enfileirar(&f, origem);

    while (!fila_vazia(&f)) {
        int v = desenfileirar(&f);
        if (v == destino) break;
        for (int j = 0; j < n; j++) {
            if (g->matriz[v][j] && !visitado[j]) {
                visitado[j] = 1;
                anterior[j] = v;
                enfileirar(&f, j);
            }
        }
    }

    printf("--- Menor Caminho: \"%s\" -> \"%s\" ---\n",
           g->nomes[origem], g->nomes[destino]);

    if (!visitado[destino]) {
        printf("  Sem caminho entre as cidades.\n\n");
        return;
    }

    /* mostra o caminho do jeito certo */
    int caminho[MAX_CIDADES], tam = 0, atual = destino;
    while (atual != -1) {
        caminho[tam++] = atual;
        atual = anterior[atual];
    }

    printf("  Rota: ");
    for (int i = tam - 1; i >= 0; i--) {
        printf("%s", g->nomes[caminho[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\n  Total de paradas intermediarias: %d\n\n", tam - 2);
}

/* nossa mainzinha */

int main(void) {
    Grafo g;
    grafo_init(&g);

    /* --- vertices sao as cidades --- */
    int curitiba  = adicionar_cidade(&g, "Curitiba");
    int ponta     = adicionar_cidade(&g, "Ponta Grossa");
    int londrina  = adicionar_cidade(&g, "Londrina");
    int maringa   = adicionar_cidade(&g, "Maringa");
    int cascavel  = adicionar_cidade(&g, "Cascavel");
    int foz       = adicionar_cidade(&g, "Foz do Iguacu");
    int guarapuava= adicionar_cidade(&g, "Guarapuava");
    int uniao     = adicionar_cidade(&g, "Uniao da Vitoria");

    /* --- arestas sao as estradas --- */
    adicionar_estrada(&g, curitiba,  ponta);
    adicionar_estrada(&g, curitiba,  uniao);
    adicionar_estrada(&g, ponta,     londrina);
    adicionar_estrada(&g, ponta,     guarapuava);
    adicionar_estrada(&g, londrina,  maringa);
    adicionar_estrada(&g, guarapuava,cascavel);
    adicionar_estrada(&g, guarapuava,uniao);
    adicionar_estrada(&g, cascavel,  foz);
    adicionar_estrada(&g, cascavel,  maringa);

    exibir_grafo(&g);

    /* --- BFS (menor caminho em paradas) --- */
    bfs(&g, curitiba);

    /* --- DFS (vai ate o fim antes de voltar) --- */
    dfs(&g, curitiba);

    /* --- menor caminho usando bfs --- */
    menor_caminho(&g, londrina, curitiba);
    menor_caminho(&g, londrina, uniao);

    return 0;
}
