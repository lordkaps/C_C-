#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Augusto.h"

void abertura()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|     Bem vindo a mais um Exercicio    |\n");
    printf("|     Vamos lah Prof: Gustavo!?        |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void escolha()
{
    int modulo;
    printf("Escolha qual modulo deseja utilizar.\n");
    printf("Digite somente o numero de 1 a 5 e aperte enter.\n");
    do
    {
        printf("Questao 1, 2, 3, 4 ou 5 ? ");
        scanf(" %d", &modulo);
        if (modulo > 5 || modulo < 1)
        {
            printf("Valor informado errado!\n");
        }
    } while (modulo < 1 || modulo > 5);

    switch (modulo)
    {
    case 1:
        questao1();
        break;
        case 2:
        questao2();
        break;
        case 3:
        questao3();
        break;
        case 4:
        questao4();
        break;
        case 5:
        questao5();
        break;
    }
}


int main()
{
    abertura();
    escolha();
}