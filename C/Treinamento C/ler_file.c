#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *arquivo;

    arquivo = fopen("ListaPalavras.txt", "r");
    char Linha[100];
    char *result;

    while (!feof(arquivo))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, arq); // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result)                      // Se foi possível ler
            printf("Linha %d : %s", i, Linha);
    }
}