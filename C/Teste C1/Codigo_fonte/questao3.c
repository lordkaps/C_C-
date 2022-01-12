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
    printf("|QUESTAO (3)                           |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}


int main()
{
    int numero, fatorial;

    abertura();

    printf("Digite um numero inteiro : ");
    scanf("%d", &numero);

    fatorial = numero;
    for (int i = numero; i > 1; i--)
    {
        if ((i - 1) % 2 == 1)
        {
            fatorial = fatorial * (i - 1);
        }
    }

    printf("fatorial utilizando somente numeros impares = %d\n", fatorial);

    printf("\n\n");
    printf("Obrigado por utilizar o programa!\n");
    system("pause");
}