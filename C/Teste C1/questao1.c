#include <stdio.h>
#include <stdlib.h>

/*
Dev : Augusto de Paulo Santos
Data: 24/11/2021
TESTE C1
QUESTAO (1)

*/
void abertura()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|     Bem vindo ao Programa C1         |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");

    printf("|**************************************|\n");
    printf("|Dev : Augusto de Paulo Santos         |\n");
    printf("|Data: 24/11/2021                      |\n");
    printf("|TESTE C1                              |\n");
    printf("|QUESTAO (1)                           |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void maiormenor(int n1, int n2, int n3)
{
    if (n1 > n2 && n1 > n3)
    {
        printf("O primeiro = %d eh o maior numero\n", n1);
        if (n2 < n3)
        {
            printf("e o segundo = %d eh o menor numero\n", n2);
        }
        else
        {
            printf("e o terceiro = %d eh o menor numero\n", n3);
        }
    }
    else if (n2 > n1 && n2 > n3)
    {
        printf("O segundo = %d eh o maior\n", n2);
        if (n1 < n3)
        {
            printf("e o primeiro = %d eh o menor numero\n", n1);
        }
        else
        {
            printf("e o terceiro = %d eh o menor numero\n", n3);
        }
    }
    else
    {
        printf("O terceiro = %d eh o maior\n", n3);
        if (n1 < n2)
        {
            printf("e o primeiro = %d eh o menor numero\n", n1);
        }
        else
        {
            printf("E o segundo = %d eh o menor numero\n", n2);
        }
    }
}

int main()
{
    int number1, number2, number3;

    abertura();
    
    printf("Por favor digite 3 numeros inteiros. \n");
    printf("Digite o primeiro numero : ");
    scanf("%d", &number1);
    printf("Digite o segundo numero : ");
    scanf("%d", &number2);
    printf("Digite o terceiro numero : ");
    scanf("%d", &number3);

    maiormenor(number1, number2, number3);

    printf("\n\n");
    printf("Obrigado por utilizar o programa!\n");
    system("pause");
}