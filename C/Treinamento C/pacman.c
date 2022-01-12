#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "pacman.h"
#include "mapa.h"

//apelido para o tipo informado no pacman.h
MAPA m;
POSICAO heroi;
POSICAO enemy;

int validadirecao(char c)
{
    return c == 'a' || c == 'w' || c == 's' || c == 'd';
}

void move(char comando)
{
    if (!validadirecao(comando))
    {
        return;
    }

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;

    switch (comando)
    {
    case ESQUERDA:
        proximo_y--;
        break;
    case CIMA:
        proximo_x--;
        break;
    case DIREITA:
        proximo_y++;
        break;
    case BAIXO:
        proximo_x++;
        break;
    } /*
    if(proximo_x >= m.linhas){return;}
    if(proximo_y >= m.colunas){return;}*/
    if (!limitamapa(&m, proximo_x, proximo_y))
    {
        return;
    }
    /*
    m.mapamatriz[proximo_x][proximo_y] = '@';
    m.mapamatriz[heroi.x][heroi.y] = '.';
    heroi.x = proximo_x;
    heroi.y = proximo_y; */
    andanomapa(&m, heroi.x, heroi.y, proximo_x, proximo_y, &heroi);
}

void movenpc()
{
    int proximo_x = enemy.x;
    int proximo_y = enemy.y;
    if (!limitamapa(&m, proximo_x + 1, proximo_y))
    {
        return;
    }

    andanomapa(&m, enemy.x, enemy.y, proximo_x + 1, proximo_y, &enemy);
}

int acabou()
{
    return 0;
}

int main()
{
    abrearquivo(&m);
    encontranomapa(&m, &heroi, HEROI);

    encontranomapa(&m, &enemy, ENEMY);
    printf("Inimigo x = %d e y = %d \n", enemy.x, enemy.y);

    do
    {

        mostramapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        movenpc();

    } while (!acabou());

    liberamapa(&m);
}