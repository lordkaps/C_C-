#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char desenhoparede[4][7] = {
    {"______"},
    {"|    |"},
    {"|    |"},
    {"|____|"}};

char desenhoheroi[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char desenhopilula[4][7] = {
    {"  .-. "},
    {" //// "},
    {" '-'  "},
    {"      "}};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

char desenhofantasma[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char desenhobomba[4][7] = {
    {" #### "},
    {"######"},
    {"######"},
    {" #### "}};

void mostramapa(MAPA *map)
{
    for (int i = 0; i < map->linhas; i++)
    {
        for (int parte = 0; parte < 4; parte++)
        {
            for (int j = 0; j < map->colunas; j++)
            {
                switch (map->mapamatriz[i][j])
                {
                case ENEMY:
                    desenho(desenhofantasma, parte);
                    break;
                case HEROI:
                    desenho(desenhoheroi, parte);
                    break;
                case PILULA:
                    desenho(desenhopilula, parte);
                    break;
                case PAREDE_VERTICAL:
                case PAREDE_HORIZONTAL:
                    desenho(desenhoparede, parte);
                    break;
                case VAZIO:
                    desenho(desenhovazio, parte);
                    break;
                case BOMBA:
                    desenho(desenhobomba, parte);
                    break;
                }
            }
            printf("\n");
        }
    }
   
}

void desenho(char desenho[4][7], int parte)
{   
    printf("%s", desenho[parte]);
}