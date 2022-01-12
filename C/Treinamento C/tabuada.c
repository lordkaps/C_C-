#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero = 0;

    printf("Escolha o numero da tabuada: ");
    scanf("%d", &numero);

    for(int i = 1; i <= 10; i++){

        int valor = numero * i;
        printf("%d * %d = %d \n", numero, i, valor);
    }
    printf("Finalizado!\n");
}