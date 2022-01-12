#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"

float vetorx[10], vetory[10];
/*
⦁	Sabendo que um vetor de 10 posições preenchidos pelo usuário de números reais, 
   chamado de vetor X , usando esse vetor calcule o vetor Y de cada função abaixo:
⦁*/
void abertura2()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|          Questao ( 2 )               |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void recebevalor2()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor %d de 10:", i + 1);
        scanf(" %f", &vetorx[i]);
        printf("\n");
    }
}

void calculo1() // Y= 2X + 1
{
    for (int i = 0; i < 10; i++)
    {
        vetory[i] = 2 * vetorx[i] + 1;
        printf("Vetor Y[%d] = %.2f\n", i + 1, vetory[i]);
    }
}

void calculo2() //Y = X2
{
    for (int i = 0; i < 10; i++)
    {
        vetory[i] = vetorx[i] * vetorx[i];
        printf("Vetor Y[%d] = %.2f\n", i + 1, vetory[i]);
    }
}

void calculo3() //Y= X3
{
    for (int i = 0; i < 10; i++)
    {
        vetory[i] = vetorx[i] * vetorx[i] * vetorx[i];
        printf("Vetor Y[%d] = %.2f\n", i + 1, vetory[i]);
    }
}

void questao2()
{

    abertura2();    
    recebevalor2();

    printf("\n\n");
    printf("Y = 2X + 1\n");
    calculo1();
    printf("\n\n");
    printf("Y = X2\n");
    calculo2();
    printf("\n\n");
    printf("Y = X3\n");
    calculo3();
    printf("\n\n");
    printf("Obrigado por usar o sistema! Abra novamente e execute outro modulo.\n");
}