#include <stdlib.h>
#include <stdio.h>
#include "arquivo.h"

int geraArquivo(char *nomeSaida, int qtd, int semente){

  FILE *arquivo;
  
  int i;
  int *vet = (int *) malloc(qtd * sizeof(int));

  arquivo = fopen(nomeSaida, "w");

  fprintf(arquivo, "%d\n", qtd);

  srand(semente);
  
  for(i=0; i<qtd; i++)
    vet[i] = rand() % qtd+1;
  
  for(i=0; i<qtd; i++)
    fprintf(arquivo, "%d\n", vet[i]);

  fclose(arquivo);
  
  if(arquivo == NULL)
    return -1;
  else
    return 0;
  
}

void leArquivo(char *nomeEntrada){
  
  FILE *arquivo;
  
  int qtd, i=0;
  
  arquivo = fopen(nomeEntrada, "r");

  fscanf(arquivo, "%d", &qtd);

  int *vet = (int *) malloc(qtd * sizeof(int));
  
  while(fscanf(arquivo, "%d", &vet[i])==1)
    i++;

  fclose(arquivo);
  
  imprimeVet(vet, qtd);
  
  liberaVetor(vet);
}

void imprimeVet(int *vet, int tam){
  
  int i;

  printf("\n");
  
  for(i=0; i<tam; i++)
    printf("%d-", vet[i]);
  
  printf("\n");
  
}

void liberaVetor(int *vet){
      free(vet);
}
