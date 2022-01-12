#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main()
{
    char mapa[5][11];

    FILE *arquivo;

    arquivo = fopen("mapa.txt", "r");
    if (arquivo == 0)
    {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(arquivo, "%s", mapa[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", mapa[i]);
    }

    fclose(arquivo);

    // Alocando memoria *valor ponteiro
    int *valor = malloc(sizeof(int));
    *valor = 10;
    printf("Inteiro com alocacao =  %d\n", *valor);
    free(valor);

    // Alocando um array de 5 posicoes
    int *valor = malloc(sizeof(int) * 5);
    valor[0] = 10;
    valor[1] = 15;
    printf("Inteiro com alocacao =  %d e %d\n", valor[0], valor[1]);
    free(valor);

    //alocando uma matriz

    int **valor = malloc(sizeof(int *) * 5)
    for (int i = 0; i < 5; i++)
    {
        valor[i] = malloc(sizeof(int) * 10);
    }
    printf("Inteiro com alocacao =  %d e %d\n", valor[0][0], valor[1][0]);
    
    for(int i = 0; i < 5; i++){
        free(valor[i]);
    }
    free(valor);
}