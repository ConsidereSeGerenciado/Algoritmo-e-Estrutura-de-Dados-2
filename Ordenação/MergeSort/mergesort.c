#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

struct tVet
{
    int *vet;
    int tam;
};





//Função recursiva que executa a fase de divisão do algoritmo mergesort
void MergeSort(int *v, int inicio, int fim)
{
  int meio;
  if(inicio<fim)
  {
    meio = (inicio+fim)/2;
    MergeSort(v, inicio, meio);
    MergeSort(v, meio+1,fim);
    merge(v, inicio, meio, fim);
  }
}

//Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original
void merge(int *v, int inicio, int meio, int fim)
{
  int marcadorV1 = inicio;
  int marcadorV2 = meio+1;
  int vetAux[(fim-inicio)+1];
  int i = 0;
  int k;
  while(marcadorV1 <= meio && marcadorV2 <= fim)
  {
    if(v[marcadorV1] < v[marcadorV2])
    {
      vetAux[i] = v[marcadorV1];
      marcadorV1++;
    }
    else
    {
      vetAux[i] = v[marcadorV2];
      marcadorV2++;
    }
    i++;
  }
  
  for(k=marcadorV1; k<=meio; k++)
  {
    vetAux[i] = v[k];
    i++;
  }  

  for(k=0; k<i; k++)
  {
    v[inicio+k] = vetAux[k];
  }
}

//Função que imprime um vetor
//printf("%d ", vet[i])
void imprimeVet(int *v, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d ", v[i]);
    }
}

//Função que lê os dados de um arquivo e carrega em um vetor de inteiros
//Retorna o tipo tVet, composto por um vetor de inteiros e o tamanho do vetor
//A primeira linha do arquivo possui o tamanho do vetor
tVet * leArquivo(char *nomeArquivo)
{
    tVet *vetor = (tVet*) malloc(sizeof(tVet));
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "r");

    fscanf(arquivo, "%d", &vetor->tam);  

    vetor->vet = (int*) malloc(sizeof(int) * vetor->tam);

    for(i=0; i<vetor->tam; i++)
    {
        fscanf(arquivo, "%d", &vetor->vet[i]);
    }

    fclose(arquivo);

    return vetor;
}

//Função que retorna o tamanho do vetor
int getVetTam(tVet *res)
{
    return res->tam;
}

//Função que retorna o vetor
int *getVet(tVet *res)
{
    return res->vet;
}

