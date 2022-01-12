#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"
/*
⦁	Busca no vetor de inteiros. Um vetor de 20 posiões deve ser preenchido pelo usuário em seguida uma chave de busca 
também deve ser informada pelo usuário. Em seguida deve ser feito a busca e ao final deve informar 
a posição em que foi encontrado a referida chave no vetor. Atenção ao detalhe: esse vetor poder ter números repetidos.
 */

int vetor[20];
int busca;
char continuar;
int contagem = 0;

void abertura4()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|          Questao ( 4 )               |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void recebevalor4()
{
    printf("Informe 20 valores inteiros para a lista.\n");
    for (int i = 0; i < 20; i++)
    {
        printf("Digite o valor %d de 20:", i + 1);
        scanf(" %d", &vetor[i]);
        printf("\n");
    }
}

void contador()
{
    for (int i = 0; i < 20; i++)
    {
        if (busca == vetor[i])
        {
            contagem++;
        }
    }
}

void posicao()
{
    if (contagem > 1)
    {
        printf("Valores encontrados nas posicoes: ");
        for (int i = 0; i < 20; i++)
        {
            if (busca == vetor[i])
            {
                printf("%d, ", i + 1);
            }
        }
    }
    else if (contagem == 1)
    {
        printf("Valor encontrado na posicao: ");
        for (int i = 0; i < 20; i++)
        {
            if (busca == vetor[i])
            {
                printf("%d", i + 1);
            }
        }
    }
    else if (contagem == 0)
    {
        printf("\n");
        printf("Valor nao encontrado\n");
    }

    printf("\n\n");
}

void questao4()
{
    abertura4();
    contagem = 0;
    recebevalor4();

    do
    {
        printf("\n");
        printf("Informe o valor para buscar: ");
        scanf(" %d", &busca);

        contador();
        posicao();

        do
        {
            printf("Deseja realizar nova consulta?(s/n) : ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'n')
            {
                printf("Utilize somente s ou n \n");
            }
        } while (continuar != 's' && continuar != 'n');
        contagem = 0;
    } while (continuar == 's');

    printf("\n\n");
    printf("Obrigado por usar o sistema! Abra novamente e execute outro modulo.\n");
}