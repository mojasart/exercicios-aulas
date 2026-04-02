#include <stdio.h>

#include <string.h>

#include <stdbool.h>

#include <stdlib.h>



typedef struct {

  char nome[50];

  char raridade[50];

  int custo;

} Carta;



Carta *cartas;

int qtdCartas;



void mostrarCartas(Carta *v, int index, int n) // função para mostrar as cartas

{

  if(index == n)

    return;



  if(index == 0)

    printf("\n--- CARTAS DO DECK ---\n");



  printf("\nCarta %d:\n", index+1);

  printf("Nome: %s\n", v[index].nome);

  printf("Raridade: %s\n", v[index].raridade);

  printf("Custo de Elixir: %d\n", v[index].custo);



  mostrarCartas(v, index+1, n); // uso da recursividade

}



void ordenarPorCusto(Carta *v, int n) // função que ordena as cartas em ordem crescente por custo

{

  Carta aux;

  for(int i = 0; i < n-1; i++)

    for(int j = i+1; j < n; j++)

      if(v[j].custo < v[i].custo)

      {

        aux = v[i];

        v[i] = v[j];

        v[j] = aux;

      }



  printf("\nCartas ordenadas por custo de elixir!\n");

}



void ordenarPorNome(Carta *v, int n) // função que ordena as cartas por nome

{

  Carta aux;

  for(int i = 0; i < n-1; i++)

    for(int j = i+1; j < n; j++)

      if(strcmp(v[j].nome, v[i].nome) < 0)

      {

        aux = v[i];

        v[i] = v[j];

        v[j] = aux;

      }

}



void inserirCartas(Carta *v, int n) // função para o usuário inserir as cartas

{

  for(int i = 0; i < n; i++)

  {

    printf("\nInsira o nome da carta %d: ", i+1);

    scanf(" %[^\n]", v[i].nome);



    printf("Insira a raridade da carta %d: ", i+1);

    scanf(" %[^\n]", v[i].raridade);



    printf("Insira o custo de elixir da carta %d: ", i+1);

    scanf("%d", &v[i].custo);

  }

}



void buscaSeq(Carta *v, int n) // função de busca sequencial

{

  char nomeBusca[50];

  bool encontrado = false;



  printf("\nDigite o nome da carta para buscar: ");

  scanf(" %[^\n]", nomeBusca);



  for(int i = 0; i < n; i++)

    if(strcmp(v[i].nome, nomeBusca) == 0)

    {

      printf("\nCarta encontrada:\n");

      printf("Nome: %s\nRaridade: %s\nCusto: %d\n",

        v[i].nome, v[i].raridade, v[i].custo);

      encontrado = true;

    }



  if(!encontrado)

    printf("\nCarta não encontrada!\n");

}



void buscaBinaria(Carta *v, int n) // função de busca binária

{

  char nomeBusca[50];

  int inicio = 0, fim = n - 1, meio;



  ordenarPorNome(v, n);



  printf("\nDigite o nome da carta para busca binária: ");

  scanf(" %[^\n]", nomeBusca);



  while(inicio <= fim)

  {

    meio = (inicio + fim) / 2;

    int cmp = strcmp(nomeBusca, v[meio].nome);



    if(cmp == 0)

    {

      printf("\nCarta encontrada via busca binária:\n");

      printf("\nNome: %s\nRaridade: %s\nCusto: %d\n",

        v[meio].nome, v[meio].raridade, v[meio].custo);

      return;

    }

    else if(cmp > 0)

      inicio = meio + 1;

    else

      fim = meio - 1;

  }



  printf("\nCarta não encontrada!\n");

}



int main()

{

  int opcao;



  printf("Bem-vindo(a) ao editor de deck!\n");

  printf("Antes de começar, informe a quantidade de cartas do deck: ");

  scanf("%d", &qtdCartas);



  cartas = (Carta*) malloc(qtdCartas * sizeof(Carta)); // uso do malloc para definir a quantidade de cartas



  inserirCartas(cartas, qtdCartas);



  do {

    printf("\n*** MENU PRINCIPAL ***\n"); // menu interativo

    printf("1 - Mostrar cartas do deck (recursivo)\n");

    printf("2 - Ordenar cartas por custo de elixir\n");

    printf("3 - Buscar carta (busca linear)\n");

    printf("4 - Buscar carta (busca binária)\n");

    printf("5 - Sair\n");



    printf("\nDigite uma opção para prosseguir: ");

    scanf("%d", &opcao);



    switch(opcao) // switch com as opções do programa

    {

      case 1:

        mostrarCartas(cartas, 0, qtdCartas);

        break;

       

      case 2:

        ordenarPorCusto(cartas, qtdCartas);

        break;



      case 3:

        buscaSeq(cartas, qtdCartas);

        break;



      case 4:

        buscaBinaria(cartas, qtdCartas);

        break;



      case 5:

        printf("\nSaindo...\n");

        break;



      default:

        printf("Opção inválida!\n");

    }



  } while(opcao != 5);



  free(cartas);

  return 0;

}
