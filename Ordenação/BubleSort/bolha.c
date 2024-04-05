#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"

struct tReturn{
  int *vet;
  int tam;
  int erro;
};

//Essa função aloca memória para uma variável do tipo tReturn
tReturn* alocatReturn(){

  tReturn *variavel = (tReturn*) malloc(sizeof(tReturn));

  if(variavel != NULL)
    variavel->erro = 0;

  return variavel;
}

//Essa função retorna o vetor contido na estrutura tReturn;
int *getVet(tReturn *rep){
  return rep->vet;
}

//Essa função retorna o tamanho vetor contido na estrutura tReturn;
int getTam(tReturn *rep){
  return rep->tam;
}

//Essa função retorna o valor da variável error contido na estrutura tReturn;
int getErro(tReturn *rep){
  return rep->erro;
}

//Essa função trata os erros relativos à função leArquivo
//erro 1 : abertura do arquivo -- printf("Erro ao abrir o arquivo\n");
//erro 2: leitura do arquivo -- printf("Erro ao ler do arquivo\n");
//erro 3 : alocação de memória -- printf("Erro ao alocar memória\n");
void trataErro(int erro){
  
  if(erro == 1)
    printf("Erro ao abrir o arquivo\n");
  
  if(erro == 2)
    printf("Erro ao ler do arquivo\n");
  
  if(erro == 3)
    printf("Erro ao alocar memória\n");
}

//Essa função lê um arquivo com números inteiros (um número por linha) e preenche um vetor
//A primeira linha do arquivo contém o tamanho do vetor
//A função retorna o tipo TReturn formado por um ponteiro para inteiros, um inteiro que guarda o tamanho do vetor e um inteiro que codifica erros
tReturn* leArquivo(char nomeArquivo[]){

  int casoerro;

  tReturn *variavel = alocatReturn();
  
  FILE *arquivo;

  int i;

  arquivo = fopen(nomeArquivo, "r");

  if(arquivo==NULL)
    variavel->erro=1;

  casoerro = fscanf(arquivo, "%d", &variavel->tam);
  
  if(casoerro ==0)
    variavel->erro=2; 

  variavel->vet = (int*) malloc(sizeof(int) * variavel->tam);

  if(variavel->vet==NULL)
    variavel->erro=3;

  for(i=0; i<variavel->tam; i++){
    casoerro = fscanf(arquivo, "%d", &variavel->vet[i])==1;
    if(casoerro==0){
      variavel->erro=2;
      break;
    }
  }

  fclose(arquivo);

  return variavel;
  
}

//Essa função ordena o vetor usando o método bolha e retorna a quantidade de comparações realizadas
int bolha (int *vet, int tam){
  int i, j, aux, comparacao=0;

  for(i=0; i<tam; i++)
  {
    for(j=1;j<tam;j++)
    { 
      if(vet[j]<vet[j-1])
      {
        aux = vet[j-1];
        vet[j-1] = vet[j];
        vet[j] = aux;
      }      
      comparacao++;
    }
  } 
  return comparacao;
}

//Essa função ordena o vetor usando o método bolha inteligente e retorna a quantidade de comparações realizadas
int bolhaInteligente (int *vet, int tam){
  int i, j, aux, comparacao=0, trocas;

  for(i=0; i<tam; i++)
  {
    trocas = 0;
    for(j=1;j<tam-i;j++)
    { 
      if(vet[j]<vet[j-1])
      {
        aux = vet[j-1];
        vet[j-1] = vet[j];
        vet[j] = aux;
        trocas = 1;
      }
     comparacao++;
    }
    if(trocas==0)
      return comparacao; 
  }
  return comparacao;
}


//Essa função imprime os dados de um vetor (um número por linha) - printf("%d\n", vet[i])
void imprimeVet(int *vet, int tam){

  int i;

  for(i=0; i<tam; i++){
    printf("%d\n", vet[i]);
  }
}