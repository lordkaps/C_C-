#include <stdio.h>
int main()
{
    int chute = 0;
    int numerosecreto = 42;
    int acertou = (chute == numerosecreto); // int acertou recebe 0 ou 1 na comparação se chute é igual a numerosecreto

      // If ja verifica se 1 é verdadeiro ou 0 é falso
    if (acertou)
    {
        printf("Parabéns! Você acertou!\n");
    }
    else
    {
        if (chute > numerosecreto)
        {
            printf("Seu chute foi maior do que o numero secreto!\n");
        }
        if (chute < numerosecreto)
        {
            printf("Seu chute foi menor do que o numero secreto!\n");
        }
    }
}