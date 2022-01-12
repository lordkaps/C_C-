#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int nu_secret = rand() % 100;

    int chute = 0;
    int nivel = 0;
    int tentativas;
    float pontos = 1000.0f;
    int acertou = 0;

    printf("**********************\n");
    printf("* Bem vindo ao jogo! *\n");
    printf("**********************\n");

    printf("Escolha seu nivel! \n");
    printf("Nivel (1) Nivel (2) e Nivel (3) \n");
    printf("\n");
    printf("Qual o nivel? ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        tentativas = 10;
        break;
    case 2:
        tentativas = 8;
        break;

    default:
        tentativas = 6;
        break;
    }

    for (int i = 1; i <= tentativas; i++)
    {

        printf("Qual o numero que pensei? ");
        scanf("%d", &chute);
        printf("Seu numero foi: %d \n", chute);

        if (chute < 0)
        {
            printf("Numero nao pode ser negativo!");
            i--;
            continue;
        }
        else if (chute == nu_secret)
        {
            printf("\n\n");
            printf("Parabens! Voce acertou! O numero eh %d \n", nu_secret);
            printf("Seus pontos %.1f \n", pontos);
            acertou = 1;
            printf("\n\n");
            break;
        }
        else if (chute > nu_secret)
        {
            printf("O numero secreto eh menor\n");
            printf("Tentativas: %d de %d\n", i, tentativas);
        }
        else
        {
            printf("O numero secreto eh maior\n");
            printf("Tentativas: %d de %d\n", i, tentativas);
        }
        pontos = pontos - (abs(chute - nu_secret) / 2.0f);
    }
    if (!acertou)
    {
        printf("Infelizmente voce perdeu! Tente novamente.\n");
    }
}