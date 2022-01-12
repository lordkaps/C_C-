#include <stdio.h>

vold soma(int numeros[10])
{

    int total = 0;
    for (int i = 0; i < strlen(numeros); i++)
    {
        total = total + numeros[i];
    }
    printf("Total eh de: %d", total);
}

int main()
{

    int num[10];

    soma(num);
}