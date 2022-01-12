#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define NUMERO_TENTATIVAS 3

//Usando o while
int main()
{
    
    srand(time(NULL));

    int nu_secret = rand() % 100;  // resto da divisao por 100 = numeros de 0 a 99

    int chute = 0;
    int tentativas = 1;

    float pontos = 1000.0f;
    //Imprimir textos
    printf("**********************\n");
    printf("* Bem vindo ao jogo! *\n");
    printf("**********************\n");

    while (chute != nu_secret)
    {
        printf("Tentativa: %d \n", tentativas);
        printf("Pontos: %.1f \n", pontos);
        printf("Qual o numero que pensei? ");        
        scanf("%d", &chute);
        printf("Seu numero foi: %d \n", chute);

        if (chute < 0)
        {
            printf("Numero nao pode ser negativo!\n");
            continue;
        }

        else if (chute > nu_secret)
        {
            printf("O numero secreto eh menor\n");
            
            
        }
        else if (chute < nu_secret)
        {
            printf("O numero secreto eh maior\n");
        }
        else
        {
            break;
        }
        pontos = pontos - (abs(chute - nu_secret) / 2.0f);
        tentativas++;
    }

    printf("Parabens! Voce acertou! O numero eh %d \n", nu_secret);
    printf("Voce acertou com %d tentativa(s).\n", tentativas);
    printf("Seus pontos %.1f \n", pontos);
}