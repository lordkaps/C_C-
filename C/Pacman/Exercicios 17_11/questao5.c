#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"

/*
⦁	Dada uma matriz 2x2 de valores reais preenchidos pelo usuário calcule o determinante
*/
float matriz[2][2];
float determinante;

void abertura5()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|          Questao ( 5 )               |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void valormatriz()
{

    printf("Informe os valores para a matriz: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Informe o valor para posicao [%d][%d]: ", i, j);
            scanf(" %f", &matriz[i][j]);
        }
    }
    printf("Valores da matriz:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Posicao [%d][%d] - Valor : %f\n", i, j, matriz[i][j]);
        }
    }
}

void calcdeterminante()
{

    determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    printf("Determinante = %.3f", determinante);
}

void questao5()
{
    abertura5();
    printf("\n\n");
    valormatriz();
    printf("\n");
    calcdeterminante();
    printf("\n\n");
    printf("Obrigado por usar o sistema! Abra novamente e execute outro modulo.\n");
}