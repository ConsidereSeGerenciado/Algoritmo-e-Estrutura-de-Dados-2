#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "lista.h"

struct hash
{
    lista **tabela;
    int tamanho;
};

//Aloca e inicializa uma tabela hash de tamanho "tam";
hash *criaHash(int tam)
{
  hash *tabelaHash = (hash*) malloc(sizeof(hash) * tam);
  
  tabelaHash->tamanho = tam;
  
  tabelaHash->tabela = (lista**) malloc(sizeof(lista*) * tam);

  for(int i=0; i<tam; i++)
    tabelaHash->tabela[i] = criaLista();
  
  return tabelaHash;
}

//Retorna a posição da palavra na tabela hash de tamanho "tamHash"
//O cálculo está na descrição da atividade
int funcaoHash(char *palavra, int tamHash)
{
  int valorASCII = 0;
  
  for (int i = 0; palavra[i] != '\0'; i++)
    valorASCII += (int) palavra[i];
  
  return valorASCII % tamHash;
}

//Insere uma nova palavra na hash utilizando a função insereLista da TAD lista.
void insere(hash *h, char *palavra)
{
  int pos = funcaoHash(palavra, h->tamanho);
  
  insereLista(h->tabela[pos], palavra);
}

//Verifica a presença de uma palavra na tabela hash utilizando a função buscaLista da TAD lista
//Se o elemento estiver presente, retorna a posição dele na Hash. Caso contrário, retorna -1.
int encontraElemento(hash *h, char *palavra)
{
  int pos = funcaoHash(palavra, h->tamanho);
  
  if(buscaLista(h->tabela[pos], palavra) == 1)
    return pos;
    
  else
    return -1;
}

//Imprime a lista de uma posição da hash utilizando a função imprimeLista da TAD lista
void percorre(hash *h, int pos)
{
  imprimeLista(h->tabela[pos]);
}

//Retorna o tamanho de uma lista da hash utilizando a função getTamLista da TAD lista.
int getTamanhoLista(hash *h, int pos)
{
  return getTamLista(h->tabela[pos]);
}

//Remove uma palavra da hash utilizando as funções encontraElemento e removeLista da TAD lista.
//Se o elemento existia na hash e foi removido, retorna 0. Caso contrário, retorna -1.
int removeElemento(hash *h, char *palavra)
{
  int pos = funcaoHash(palavra, h->tamanho);
  
  if(encontraElemento(h, palavra) != -1)
  {
    removeLista(h->tabela[pos], palavra);
    return 0;
  }
    
  else
    return -1;
}
