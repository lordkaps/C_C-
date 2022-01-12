#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void alimentamatriz(int m[3][3])
{
    
    srand(time(0));    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = rand() % 50;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Posicao [%d,%d] = %d ", i, j, m[i][j]);
            
        }
        printf("\n");
    }

    int diagonalp = (m[0][0]*m[1][1]*m[2][2])+(m[0][1]*m[1][2]*m[2][0])+(m[0][2]*m[1][0]*m[2][1]);
    int diagonals = (m[0][1]*m[1][0]*m[2][2])+(m[0][0]*m[1][2]*m[2][0])+(m[0][2]*m[1][1]*m[2][1]);
    int determinante = diagonalp - diagonals;

    printf("\ndeterminante = %d", abs(determinante));
}

int main()
{
    int matriz[3][3];

    alimentamatriz(matriz);
    system("pause");
}