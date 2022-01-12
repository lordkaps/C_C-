#ifndef _PACMAN_
#define _PACMAN_

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define EXPLODE 'b'
#define HEROI '@'
#define ENEMY '#'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define BOMBA '*'
#define PILULA 'o'
#define QTD_ENEMY 2

void controle(char comando);
void movenpc();
void defineposicaonpc();
void explodebomba(int x, int y, int addx, int addy, int repetir);
void limpabomba(int x, int y, int addx, int addy, int repetir);

int acabou();
int validadirecao(char c);

int npcposicao(int numero);

//MAPA>H

//CONSTANTES ACIMA DEFINIDOS

//STRUCT DEFINE UM TIPO, ONDE POSSUI PARTES QUE COMPOEM UM TIPO.
struct mapa
{
    int linhas;
    int colunas;
    char **mapamatriz;
};

//apelido para o tipo
typedef struct mapa MAPA;

struct posicao
{
    int x;
    int y;
    int localizado;
};

typedef struct posicao POSICAO;

void abrearquivo(MAPA *mp);
void alocamemoria(MAPA *mp);
void mostramapa(MAPA *mp);
void liberamapa(MAPA *mp);
void encontranomapa(MAPA *mp, POSICAO *ps, char ch);
void andanomapa(MAPA *map, int x_origem, int y_origem, int x_destino, int y_destino, POSICAO *p, char personagem);

int limitamapa(MAPA *map,char c, int x, int y);


//UI.h

void mostramapa(MAPA *mp);
void desenho(char desenho[4][7], int parte);


#endif