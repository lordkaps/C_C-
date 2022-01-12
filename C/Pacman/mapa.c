#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "pacman.h"

int posicaoauxiliar_x;
int posicaoauxiliar_y;

void encontranomapa(MAPA *map, POSICAO *pos, char personagem)
{
    // acha a posicao do personagem, percorrendo a matriz mapa e define a posicao para o *pos
    for (int i = 0; i < map->linhas; i++)
    {
        for (int j = 0; j < map->colunas; j++)
        {
            if (map->mapamatriz[i][j] == personagem && pos->localizado == 0 && (posicaoauxiliar_y != j || posicaoauxiliar_x != i))
            {
                posicaoauxiliar_x = i;
                posicaoauxiliar_y = j;
                pos->x = i;
                pos->y = j;
                pos->localizado = 1;
                break;
            }
        }
    }
}

void alocamemoria(MAPA *map) // apontando o tipo MAPA
{
    //m->linhas é igual (*m).linhas para apontar struct
    (*map).mapamatriz = malloc(sizeof(char *) * map->linhas);
    for (int i = 0; i < (*map).linhas; i++)
    {
        map->mapamatriz[i] = malloc(sizeof(char) * (map->colunas + 1));
    }
}

void abrearquivo(MAPA *map)
{
    FILE *arquivo;

    arquivo = fopen("mapa.txt", "r");
    if (arquivo == 0)
    {
        printf("Erro na leitura do mapa");
        exit(1);
    }
    fscanf(arquivo, "%d %d", &(map->linhas), &(map->colunas));

    //alocando espaço na memoria para a matriz, pois não sabemos o tamanho antecipadamente.
    alocamemoria(map);

    for (int i = 0; i < map->linhas; i++)
    {
        fscanf(arquivo, "%s", map->mapamatriz[i]);
    }
    fclose(arquivo);
}

/* MAPA ANTIGO agora esta no UI.c
void mostramapa(MAPA *map)
{
    for (int i = 0; i < map->linhas; i++)
    {
        printf("%s\n", map->mapamatriz[i]);
    }
} */

void liberamapa(MAPA *map) // limpa memoria
{
    for (int i = 0; i < map->linhas; i++)
    {
        free(map->mapamatriz[i]);
    }
    free(map->mapamatriz);
}

int limitamapa(MAPA *map,char c, int x, int y)
{
    return map->mapamatriz[x][y] == c;
}

void andanomapa(MAPA *map, int x_origem, int y_origem, int x_destino, int y_destino, POSICAO *p, char personagem)
{
    map->mapamatriz[x_destino][y_destino] = personagem;
    map->mapamatriz[x_origem][y_origem] = VAZIO;

    p->x = x_destino;
    p->y = y_destino;
}