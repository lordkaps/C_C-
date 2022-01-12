#include "tarefa.h"

/*
DEV: Augusto de Paulo Santos
Data: 02/12/2021
Tarefa: Teste C2 

PERCEPTRON - MLP - MULTI LAYER PERCEPTRON

(1) - preencher vetor x com binario
(2) - preencher vetor w com double de 0 a 1
(3) - calcular net.
(4) - calcular y
(5) - mostrar resultado de y e do vetor x
*/

//(1)
void preencher_vetor_inteiros(int vetor[5])
{
    for (int i = 0; i < 5; i++)
    {
        vetor[i] = rand() % 2;
    }
}
//(2)
void preencher_vetor_double(double vetor[5])
{

    for (int i = 0; i < 5; i++)
    {
        vetor[i] = (-0.1 + rand()) / RAND_MAX;
    }
}
//(3)
double calculo_net(int vetor_x[5], double vetor_w[5])
{
    double var = 0;

    for (int x = 0; x < 5; x++)
    {
        for (int w = 0; w < 5; w++)
        {
            var += vetor_x[x] * vetor_w[w];
        }
    }
    return var;
}
//(5) 
void mostra_resultado(double numero, int vetor[5])
{
    printf("Y = sin(net) : %.2f \n", numero);
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Vetor X[%d] = %d\n",i+1, vetor[i]);
    }
}

int main()
{
    int vetor_x[5];
    double vetor_w[5];
    double net = 0, y;
    srand(time(0));
    //(1)
    preencher_vetor_inteiros(vetor_x);
    //(2)
    preencher_vetor_double(vetor_w);
    //(3)-
    net = calculo_net(vetor_x, vetor_w);
    //(4)
    y = sin(net);
    //5
    mostra_resultado(y, vetor_x);
    system("pause");
}
