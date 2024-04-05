#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no
{
    char palavra[30];
    struct no *prox;
};

struct lista
{
    struct no *inicio;
    int tam;
};

//Aloca e inicializa uma lista
lista *criaLista()
{
    lista *list = (lista*) malloc(sizeof(lista));
    list->inicio = NULL;
    list->tam = 0;
    return list;
}

//Insere uma nova palavra na lista. Ou seja, aloca um nó, inicializa e o insere na lista.
//A insersão é sempre no começo da lista.
//Retorna 1 caso ocorra erro na inserção e 0 caso contrário.
int insereLista(lista *l, char *palavra)
{

  if(l == NULL)
    return 1;
  
  no *noAux = (no*) malloc(sizeof(no));

  if(noAux == NULL)
    return 1;
  
  strcpy(noAux->palavra, palavra);

  if(l->inicio == NULL)
  {
    noAux->prox = NULL;
    l->inicio = noAux;
  }
  
  else
  {
    noAux->prox = l->inicio;
    l->inicio = noAux;
  }
  
  l->tam++;
  
  return 0;
}

//Retorna a lista de uma determinada posição da tabela hash
lista *getLista(lista **vet, int pos)
{
  return vet[pos];
}

//Retorna o tamanho de uma determinada lista
int getTamLista(lista *l)
{
  return l->tam;
}
 

//Verifica se uma palavra está presente ou não em uma lista
//Se a palavra estiver presente, retorna 1. Caso contrário, retorna 0;
int buscaLista(lista *l, char *palavra)
{
  no *noAux = l->inicio;

  while(noAux != NULL && strcmp(noAux->palavra, palavra) != 0)
  {
    noAux = noAux->prox;
  }
  if(noAux == NULL)
    return 0;
  else
    return 1;
}

//Remove uma palavra da lista
void removeLista(lista *l, char *palavra)
{
  no *noAux = l->inicio;
  no *noRemove = NULL;

  if(noAux != NULL && strcmp(l->inicio->palavra, palavra) == 0)
  {
    noRemove = l->inicio;
    l->inicio = noRemove->prox;
  }
    
  else
  {
    while(noAux != NULL && noAux->prox != NULL && strcmp(l->inicio->palavra, palavra) != 0)
        noAux = noAux->prox;
    
    if(noAux != NULL && noAux->prox != NULL)
    {
      noRemove = noAux->prox;
      noAux->prox = noRemove->prox;
    }
  }
  if(noRemove)
  {
    free(noRemove);
    l->tam--;
  }
}

//Imprime as palavras de uma lista => printf("%s\n", noAux->palavra);
//Se a lista estiver vazia => printf("Lista Vazia\n");
void imprimeLista(lista *l)
{
  no *noAux = l->inicio;
  
  if(noAux == NULL)
    printf("Lista Vazia\n");
    
  else
  {
    while(noAux != NULL)
    {
      printf("\n%s", noAux->palavra);
      noAux = noAux->prox;
    }
  }
}