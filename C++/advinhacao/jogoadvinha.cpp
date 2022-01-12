#include <iostream>
#include <cstdlib>  // pega funcoes padroes do C
#include <ctime>   // eh igual a time.h

using namespace std;

bool acertou = false;

void jogo(int chute, int numero)
{
    cout << "Qual o numero do chute? : ";
    cin >> chute;

    bool achou = chute == numero;
    bool maior = chute > numero;

    if (achou)
    {
        cout << endl;
        cout << "Parabens voce acertou!" << endl;
        cout << endl;
        acertou = true;
    }
    else if (maior)
    {
        cout << "O seu chute eh maior que numero secreto!" << endl;
    }
    else
    {
        cout << "O seu chute eh menor que o numero secreto!" << endl;
    }
}

void nivel(int chute, int numero)
{
    char nivel;
    int tentativas;
    cout << "Qual o nivel? " << endl;
    do
    {
        cout << "Facil(F), Medio(M), Dificil(D) ?" << endl;
        cin >> nivel;
    } while (nivel != 'F' && nivel != 'M' && nivel != 'D');

    switch (nivel)
    {
    case 'F':
        while (!acertou)
        {
            jogo(chute, numero);
        }
        break;
    case 'M':
        tentativas = 7;
        for (int i = 0; i < tentativas; i++)
        {
            cout << "Tentativa " << i + 1 << " de " << tentativas << endl;
            jogo(chute, numero);
            if (acertou)
            {
                break;
            }
        }
        if (!acertou)
        {
            cout << "Voce perdeu!" << endl;
        }
        break;
    case 'D':
        tentativas = 5;
        for (int i = 0; i < tentativas; i++)
        {
            cout << "Tentativa " << i + 1 << " de " << tentativas << endl;
            jogo(chute, numero);
            if (acertou)
            {
                break;
            }
        }
        if (!acertou)
        {
            cout << "Voce perdeu!" << endl;
        }
        break;
    }
}

int main()
{
    srand(time(0));

    int numero_secreto = rand() % 100, chute;

    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao *" << endl;
    cout << "*************************************" << endl;

    nivel(chute, numero_secreto);

    system("pause");
}
