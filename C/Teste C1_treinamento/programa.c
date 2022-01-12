#include "programa.h"

/*
Dev : Augusto de Paulo Santos  
Data : 23/11/2021
Projeto: Avaliação modulo C1

*/

void abertura()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|     Bem vindo ao Programa C1         |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void calculoemprestimo()
{

    int mes;
    float composto = 1.0f;
    float taxa = 1.04f;
    float valor = 800.0f;
    int dias;
    float montante = 0;

    printf("Ola Joao, segue a baixo as informacoes do emprestimo:\n");
    printf("Valor do emprestimo: R$ %.2f \n", valor);
    printf("Taxa de juros de 6%% ao pagar em ate 30 dias - valor total de R$ %.2f \n", valor + valor * 0.06f);
    printf("Taxa de juros de 10%% ao pagar entre 31 e 60 dias - valor total de R$ %.2f \n", valor + valor * 0.10f);
    printf("Taxa de juros de 13%% ao pagar entre 61 e 90 dias - valor total de R$ %.2f \n", valor + valor * 0.13f);
    printf("Acima de 90 dias a taxa de juros cobrados ao mes eh de 4%% \n");
    printf("\n");
    printf("Em quantos dias deseja pagar?\n");
    scanf("%d", &dias);

    if (dias <= 30)
    {
        montante = valor + (valor * 0.06f);
        printf("Valor total a pagar = R$ %.2f\n", montante);
    }
    else if (dias >= 31 && dias <= 60)
    {
        montante = valor + (valor * 0.10f);
        printf("Valor total a pagar = R$ %.2f\n", montante);
    }
    else if (dias >= 61 && dias <= 90)
    {
        montante = valor + (valor * 0.13f);
        printf("Valor total a pagar = R$ %.2f\n", montante);
    }
    else
    {
        mes = ((dias-1) / 30) + 1;
        for (int i = 1; i <= mes; i++)
        {
            composto *= taxa;
        }
        montante = valor * (composto);
        printf("Valor total a pagar = R$ %.2f \n", montante);
    }
    printf("--------------------------------------------------\n");
}

void calculaidade()
{
    int anodenascimento;
    int anoatual;

    printf("Digite o ano de nascimento(4 digitos) : ");
    scanf("%d", &anodenascimento);
    printf("Digite agora o ano atual: ");
    scanf("%d", &anoatual);

    printf("A idade eh de : %d anos\n", anoatual - anodenascimento);
    printf("--------------------------------------------------\n");
}

void coroacircular()
{
    float pi = 3.14159265358979323846f;
    float raiomaior;
    float raiomenor;
    float area;
    printf("Informe o raio maior:");
    scanf("%f", &raiomaior);
    printf("Informe o raio menor:");
    scanf("%f", &raiomenor);

    area = pi * (raiomaior * raiomaior - raiomenor * raiomenor);
    printf("A area da coroa circular eh de %.3f\n", area);
    printf("--------------------------------------------------\n");
}

int main()
{
    int modulo;
    char continuar;
    abertura();
    do
    {
        printf("--------------------------------------------------\n");
        printf("Escolha o modulo: \n");
        printf(" Modulo (1): Calculo da idade\n Modulo (2): Emprestimo do Joao\n Modulo (3): Calculo da coroa circular\n");
        do
        {
            printf("Digite o numero do modulo correspondente: ");
            scanf("%d", &modulo);

            switch (modulo)
            {
            case 1:
                printf("\n");
                calculaidade();
                break;
            case 2:
                printf("\n");
                calculoemprestimo();
                break;
            case 3:
                printf("\n");
                coroacircular();
                break;
            default:
                printf("\n");
                printf("Digite o numero correto!\n");
                break;
            }
        } while (modulo > 3);

        printf("Gostaria de ver outro modulo? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' && continuar != 'n');
    printf("\n");
    printf("Obrigado por utilizar o programa!\n");
    getch();
}