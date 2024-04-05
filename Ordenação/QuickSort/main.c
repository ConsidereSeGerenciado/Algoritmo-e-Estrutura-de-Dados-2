//QUICKSORT DA PROFESSORA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *vet,int inicio,int fim);
int Particiona(int *vet,int inicio,int fim);

int main(){
    int vet[20];
    int i;

    // Preenche o vetor com números aleatórios entre 0 e 99
    srand(time(NULL));
    for(i=0;i<20;i++){
        vet[i] = rand() % 100;
    }

    // Imprime o vetor desordenado
    printf("Vetor desordenado:\n");
    for(i=0;i<20;i++){
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    // Ordena o vetor
    QuickSort(vet, 0, 19);

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for(i=0;i<20;i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}

void QuickSort(int *vet,int inicio,int fim){
    int posPivo;
    if(inicio < fim){
        posPivo = Particiona(vet,inicio,fim);
        QuickSort(vet,inicio,posPivo-1);
        QuickSort(vet,posPivo+1,fim);
    }
}

int Particiona(int *vet,int inicio,int fim){
    int pivo = vet[inicio];
    int pos = inicio;
    int aux;
    for(int i = inicio+1; i<=fim; i++){
        if(vet[i] < pivo){
            pos++;
            if(i != pos){
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
            }
        }
    }
    aux = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = aux;
    return pos;
}  