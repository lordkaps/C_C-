#include "alfa.h"

/*
DEV's : Augusto e Henrique Martins
Data : 01/12/2021
Atividade : Criar um vetor de 2 posicoes e matriz de 2x2 e preencher randomicamente entre 0 e 1 real. E gerar alfa de Matriz A.
*/

double randomizador()
{
    double randon = 0;

    randon = (-0.1 + rand()) / RAND_MAX; //min + rand() * (max - min) / RAND_MAX;
    return randon;
}

void preencher_vetor_e_matriz(double vet[2], double matriz[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        vet[i] = randomizador();
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz[i][j] = randomizador();
        }
    }
}

void imprime_vetor(double vetor[2])
{
    printf("Alfa = ");
    for (int i = 0; i < 2; i++)
    {
        printf("|%.2f|", vetor[i]);
    }
    printf("\n");
}

void imprime_matrizes(double matriz[2][2])
{
    //imprimir

    for (int i = 0; i < 2; i++)
    {
        printf("| ");
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f |", matriz[i][j]);
        }
        printf("\n");
    }
}

void gera_matrizes(double vetor[2], double matriz_origem[2][2], double matriz_destino[2][2], int posicao_vetor)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz_destino[i][j] = vetor[posicao_vetor] * matriz_origem[i][j];
        }
    }
}

int main()
{
    srand(time(0));
    double lixo = randomizador(); // o primeiro numero randomico esta sendo sempre o mesmo, nao sei o porque...
    double alfa[2];
    double matriz_a[2][2], matriz_alfa1[2][2], matriz_alfa2[2][2];
    preencher_vetor_e_matriz(alfa, matriz_a);

    printf("\n\n");
    imprime_vetor(alfa);

    printf("\n\n");
    printf("Matriz A:\n");
    imprime_matrizes(matriz_a);

    printf("\n\n");
    gera_matrizes(alfa, matriz_a, matriz_alfa1, 0);
    gera_matrizes(alfa, matriz_a, matriz_alfa2, 1);

    printf("Matriz alfa1: \n");
    imprime_matrizes(matriz_alfa1);
    printf("\n\n");

    printf("Matriz alfa2: \n");
    imprime_matrizes(matriz_alfa2);
    printf("\n\n");

    system("pause");
}