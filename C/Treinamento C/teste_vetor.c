#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main()
{

    int x[5];
    int a[5];

    int s = 0;

    x[0] = 4;
    x[1] = 3;
    x[2] = 5;
    x[3] = 1;
    x[4] = 10;

    for (int i = 0; i < 5; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        
        for (int j = 0; j < 5; j++)
        {
            if (x[i] < x[j])
            {
                a[i] = x[i];
            }
        }
    }
    printf("numeros de x:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
    printf("numeros de A:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }


    double metros = 10.0;
    printf("metros = %d\n", metros);
    double minutos = 30.0;
    printf("minutos = %d\n", minutos);
    double segundos = minutos / 60.0;
    printf("segundos = %d\n", segundos);
    double ms = metros / segundos;
    printf("valor do calculo= %d", ms);
}