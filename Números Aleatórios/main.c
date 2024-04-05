#include <stdio.h>
#include "aleatorios.h"

int main()
{
    //VARIÁVEIS
    int opcao = 0;
    int qtd;
    int num;
    int res;
    int seed;
    int *vet = NULL;
    int i;
    do {
        //menu
        printf("\nEscolha uma opcao: \n");
        printf("1. Gerar números aleatórios\n");
        printf("2. Buscar um numero\n");
        printf("3. Sair\n");

        scanf("%d", &opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                printf("Digite a quantidade de dados desejada: ");
                scanf("%d", &qtd);
                printf("\n");
                printf("\n");
                printf("Digite a semente: ");
                scanf("%d", &seed);
                printf("\n");
                vet = geraAleatorio(qtd, seed);
                for(i=0; i<qtd; i++)
                    printf("%d-", vet[i]);
                printf("\n");
                break;

            case 2:
                if (vet != NULL) {
                    printf("Digite o elemento buscado: ");
                    scanf("%d", &num);
                    res = buscaElemento(vet, qtd, num);
                    if (res == -1){
                        printf("\n");
                        printf("\nElemento não existe no vetor\n");
                    }
                    else{
                        printf("\n");
                        printf("\nElemento encontrado na posicao %d vetor\n", res);
                    }
                    break;
                }
                else
                    printf("Voce deve gerar os numeros aleatorios primeiro.\n");

            case 3:
                break;

        }
    } while (opcao != 3);

    libera_vetor(vet);

    return 0;
}