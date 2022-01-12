#include <stdio.h>
#include <stdlib.h>

/*
Dev : Augusto de Paulo Santos
Data : 19/11/2021
Exercicio de verificação se um numero é par ou impar.
*/

int main (){

    int numero;

    printf("Digite qualquer numero inteiro:");
    scanf(" %d", &numero);
    
    if(numero % 2 == 0) printf("O valor digitado eh par!\n");
    else printf("O valor digitado eh impar!\n");
    
}