#include <iostream>
#include <cstdlib> // funcao srand(TIME(0)) e rand()
#include <ctime>
#include <string> // poder utilizar strings, depende do compilador.
#include <map>
#include <vector>
#include <fstream>

using namespace std;

bool acertou_palavra();
void letra_existe(char chute);
void imprime_chutes_errados();
void imprime_tela_do_jogo();
bool perdeu();
void chuta();
void le_arquivo();

map<char, bool> letraschutadas;   //Tipo map eh igual vetor, porem pode definir a chave de acesso e depois o tipo de dado.
vector<char> chutes_errados;      //Tipo vetor que parece uma lista. Pode ir acrescentando sem precisar definir seu tamanho
vector<string> palavras_secretas; // vetor com as palavras extraidas do arquivo

string palavra_secreta;

void le_arquivo()
{
    int qtd_palavras;
    string palavra; // para receber leitura do arquivo e depois gravar  no vetor de palavras.
    ifstream arquivo_palavras;
    arquivo_palavras.open("palavras.txt");
    if (arquivo_palavras.is_open())
    {
        arquivo_palavras >> qtd_palavras;

        for (int i = 0; i < qtd_palavras; i++)
        {
            arquivo_palavras >> palavra;
            palavras_secretas.push_back(palavra);
        }
        srand(time(0));
        int posicao = rand() % qtd_palavras;

        palavra_secreta = palavras_secretas[posicao];

        arquivo_palavras.close();
    }
    else
    {
        cout << "Arquivo de palavras nao encontrado" << endl;
        exit(1);
    }
}

void letra_existe(char chute)
{
    // este modo de "FOR" passa letra a letra da palavra ate terminar. C++ versao 11, igual FORECH em C#
    for (char letra : palavra_secreta)
    {
        if (chute == letra)
        {
            return;
        }
    }
    chutes_errados.push_back(chute);

    /* Este for eh do C++ porem versao mais antiga onde manipula a string. 
    for (int i = 0; i < palavra_secreta.size(); i++)
    {
        if (letra == palavra_secreta[i])
        {

            return true;
        }
    }
    return false;
    */
}

void imprime_chutes_errados()
{
    cout << "Chutes errados : ";

    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_tela_do_jogo()
{
    // este FOR passa letra a letra da palavra secreta e verifica se a letra da palavra secreta esta TRUE no map Letras chutadas;
    for (char letra : palavra_secreta)
    {
        if (letraschutadas[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }

    cout << endl;
}

bool acertou_palavra()
{
    for (char letra : palavra_secreta)
    {
        if (!letraschutadas[letra])
        {
            return false;
        }
    }
    return true;
}

bool perdeu()
{
    return chutes_errados.size() > 4;
}

void chuta()
{
    char chute;
    cout << "Digite uma letra maiuscula: ";
    cin >> chute;
    letraschutadas[chute] = true;
    cout << endl;

    letra_existe(chute);
}

void adciona_palavra_no_banco()
{
    ofstream arquivo_g;
    string nova_palavra;
    arquivo_g.open("palavras.txt");
    if (arquivo_g.is_open())
    {
        cout << "Digita a palavra com letras maiusculas: ";
        cin >> nova_palavra;
        palavras_secretas.push_back(nova_palavra);
        arquivo_g << palavras_secretas.size() << endl;
        for (string palavra : palavras_secretas)
        {
            arquivo_g << palavra << endl;
        }
        arquivo_g.close();
        cout << endl;

        for (int i = 0; i < palavras_secretas.size(); i++)
        {
            cout << palavras_secretas[i] << endl;
        }
    }
    else
    {
        cout << "Arquivo de palavras nao encontrado" << endl;
        exit(0);
    }
}

int main()
{
    le_arquivo();
    cout << endl;
    while (!acertou_palavra() && !perdeu())
    {
        imprime_chutes_errados();
        imprime_tela_do_jogo();
        chuta();

        system("cls");
    }

    if (acertou_palavra())
    {
        char rspsta;
        cout << "Parabens acertou a Palavra" << endl;
        cout << "Gostaria de adicionar palavra ao banco de dados?(s/n) : ";
        cin >> rspsta;
        cout << endl;
        if (rspsta == 's' || rspsta == 'S')
        {

            adciona_palavra_no_banco();
        }
    }
    else
    {
        cout << "Voce perdeu!" << endl;
    }

    system("pause");
}