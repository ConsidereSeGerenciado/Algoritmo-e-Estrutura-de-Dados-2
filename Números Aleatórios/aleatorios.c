#include <stdlib.h>
#include "aleatorios.h"

int *geraAleatorio(int qtd, int seed){
    int i;
    int *v = (int *)malloc(qtd * sizeof(int));
    srand(seed);
    for(i=0; i<qtd; i++){
        v[i] = rand() % qtd+1;
    }
    return v;
}

int buscaElemento(int *vet, int tam, int num){
    int i;
    for(i=0; i< tam; i++){
        if(vet[i] == num)
            return i;
    }
    return -1;
}

void libera_vetor(int *vet){
    free(vet);
} 