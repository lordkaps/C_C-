#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"
/*
O usuário deve preencher um vetor de 10 posições de numero inteiros,
 em seguida deve elevar ao cubo cada elemento desse  vetor de 10 posições e exibir o resultado.

*/
void abertura1()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|          Questao ( 1 )               |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void questao1()
{
    abertura1();

    int vet[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor %d de 10:", i + 1);
        scanf(" %d", &vet[i]);
        printf("\n");
    }

    for (int i = 0; i < 10; i++)
    {
        vet[i] = vet[i] * vet[i] * vet[i];
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Vetor de posicao %d elevado ao cubo = %d \n", i, vet[i]);
    }
    printf("\n\n");
    printf("Obrigado por usar o sistema! Abra novamente e execute outro modulo.\n");
}