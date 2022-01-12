#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "pacman.h"
#include "mapa.h"

//apelido para o tipo informado no mapa.h
MAPA m;
POSICAO heroi, enemy[QTD_ENEMY], proximo_mov[QTD_ENEMY];


int validadirecao(char comando)
{
    return comando == 'a' || comando == 'w' || comando == 's' || comando == 'd';
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
    for (int i = 0; i < QTD_ENEMY; i++)
    {
        proximo_mov[i].x = enemy[i].x + 1;
        proximo_mov[i].y = enemy[i].y;
        proximo_mov[i].localizado = 0;
    }

    for (int i = 0; i < QTD_ENEMY; i++)
    {
        if (limitamapa(&m, proximo_mov[i].x, proximo_mov[i].y))
        {
            andanomapa(&m, enemy[i].x, enemy[i].y, proximo_mov[i].x, proximo_mov[i].y, &enemy[i]);
        }
    }
}

void defineposicaonpc()
{

    for (int i = 0; i < QTD_ENEMY; i++)
    {
        encontranomapa(&m, &enemy[i], ENEMY);
    }
}

int acabou()
{
    return 0;
}

int main()
{
    abrearquivo(&m);
    encontranomapa(&m, &heroi, HEROI);
    defineposicaonpc();

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