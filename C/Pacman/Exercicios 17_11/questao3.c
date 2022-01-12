#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"

/*
⦁	O usuário deve preencher um vetor de 10 posições,
 em seguida deve somar todos os valores que foi inserido em seguida mostrar o resultado dessa soma para o usuário.
*/
void abertura3()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|          Questao ( 3 )               |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void questao3()
{
    abertura3();
    float vetor[10];
    float total = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor %d de 10:", i + 1);
        scanf(" %f", &vetor[i]);
        total += vetor[i];
        printf("\n");
    }

    printf("Soma total dos valores = %.2f", total);
    printf("\n\n");

    printf("Obrigado por usar o sistema! Abra novamente e execute outro modulo.\n");
}