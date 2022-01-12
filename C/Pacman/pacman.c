#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "pacman.h"

char opcoes[4];
int randon1, randon2;
int temBomba = 0;
int explodiu = 0;

//apelido para o tipo informado no mapa.h
MAPA m;
POSICAO heroi, enemy[QTD_ENEMY], proximo_mov[QTD_ENEMY];

int npcposicao(int inimigo)
{
    opcoes[0] = 'w';
    opcoes[1] = 'a';
    opcoes[2] = 's';
    opcoes[3] = 'd';

    proximo_mov[inimigo].localizado = 0;

    srand(time(NULL));

    randon1 = rand() % 4;
    randon2 = rand() % 4;
    int n;

    if (inimigo == 0)
    {
        n = randon1;
    }
    else
    {
        n = randon2;
    }

    switch (opcoes[n])
    {
    case 's':
        proximo_mov[inimigo].x = enemy[inimigo].x + 1;
        proximo_mov[inimigo].y = enemy[inimigo].y;
        break;
    case 'a':
        proximo_mov[inimigo].x = enemy[inimigo].x - 1;
        proximo_mov[inimigo].y = enemy[inimigo].y;
        break;
    case 'w':
        proximo_mov[inimigo].x = enemy[inimigo].x;
        proximo_mov[inimigo].y = enemy[inimigo].y - 1;
        break;
    case 'd':
        proximo_mov[inimigo].x = enemy[inimigo].x;
        proximo_mov[inimigo].y = enemy[inimigo].y + 1;
        break;
    }
}

int validadirecao(char comando)
{
    return comando == CIMA || comando == BAIXO || comando == DIREITA || comando == ESQUERDA || comando == EXPLODE;
}

void explodebomba(int x, int y, int addx, int addy, int repetir)
{
    int novox = x + addx;
    int novoy = y + addy;

    if (repetir == 0)
        return;
    if (limitamapa(&m, PAREDE_VERTICAL, novox, novoy))
        return;
    if (limitamapa(&m, PAREDE_HORIZONTAL, novox, novoy))
        return;

    m.mapamatriz[novox][novoy] = BOMBA;
    explodiu = 1;
    for (int i = 0; i < QTD_ENEMY; i++)
    {
        if (enemy[i].x == novox && enemy[i].y == novoy)
        {
            enemy[i].localizado = 0;
        }
    }
    explodebomba(novox, novoy, addx, addy, repetir - 1);
}

void explodebombageral()
{
    explodebomba(heroi.x, heroi.y, 0, 1, 3);
    explodebomba(heroi.x, heroi.y, 0, -1, 3);
    explodebomba(heroi.x, heroi.y, 1, 0, 3);
    explodebomba(heroi.x, heroi.y, -1, 0, 3);
}

void limpabombageral()
{
    limpabomba(heroi.x, heroi.y, 0, 1, 3);
    limpabomba(heroi.x, heroi.y, 0, -1, 3);
    limpabomba(heroi.x, heroi.y, 1, 0, 3);
    limpabomba(heroi.x, heroi.y, -1, 0, 3);
}

void limpabomba(int x, int y, int addx, int addy, int repetir)
{
    int novox = x + addx;
    int novoy = y + addy;

    if (repetir == 0)
        return;
    if (limitamapa(&m, PAREDE_VERTICAL, novox, novoy))
        return;
    if (limitamapa(&m, PAREDE_HORIZONTAL, novox, novoy))
        return;

    m.mapamatriz[novox][novoy] = VAZIO;
    explodiu = 0;
    limpabomba(novox, novoy, addx, addy, repetir - 1);
}

void controle(char comando)
{
    if (!validadirecao(comando))
    {
        return;
    }
    if (explodiu == 1)
    {
        limpabombageral();
    }
    if (comando == EXPLODE && temBomba == 1)
    {
        explodebombageral();
        printf("\a");
        temBomba = 0;
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
    } 
    
    if (!limitamapa(&m, VAZIO, proximo_x, proximo_y) && !limitamapa(&m, PILULA, proximo_x, proximo_y))
    {
        return;
    }
    if (limitamapa(&m, PILULA, proximo_x, proximo_y))
    {
        temBomba = 1;
    }
    /*
    m.mapamatriz[proximo_x][proximo_y] = '@';
    m.mapamatriz[heroi.x][heroi.y] = '.';
    heroi.x = proximo_x;
    heroi.y = proximo_y; */
    andanomapa(&m, heroi.x, heroi.y, proximo_x, proximo_y, &heroi, HEROI);
}

void movenpc()
{
    for (int i = 0; i < QTD_ENEMY; i++)
    {
        npcposicao(i);
        if (enemy[i].localizado == 1 && (limitamapa(&m, VAZIO, proximo_mov[i].x, proximo_mov[i].y) || limitamapa(&m, HEROI, proximo_mov[i].x, proximo_mov[i].y)))
        {
            andanomapa(&m, enemy[i].x, enemy[i].y, proximo_mov[i].x, proximo_mov[i].y, &enemy[i], ENEMY);
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
    if (enemy[0].localizado == 1 || enemy[1].localizado == 1)
    {
        for (int i = 0; i < m.linhas; i++)
        {
            for (int j = 0; j < m.colunas; j++)
            {
                if (m.mapamatriz[i][j] == HEROI)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    abrearquivo(&m);                                //mapa.c
    encontranomapa(&m, &heroi, HEROI);              //mapa.c
    defineposicaonpc();                             //pacman.c

    do
    {
        mostramapa(&m);
        char comando = getch();  
        controle(comando);                          
        movenpc();
        system("cls");         
    } while (!acabou());

    mostramapa(&m);                                 //mapa.c
    liberamapa(&m);                                 //mapa.c
    system("pause");
    system("cls");
}