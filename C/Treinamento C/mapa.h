#define HEROI '@'
#define ENEMY '#'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
};

typedef struct posicao POSICAO;


void abrearquivo(MAPA* mp);
void alocamemoria(MAPA* mp);
void mostramapa(MAPA* mp);
void liberamapa(MAPA* mp);
void encontranomapa(MAPA* mp, POSICAO* ps, char ch);
void andanomapa(MAPA *map, int x_origem, int y_origem, int x_destino, int y_destino, POSICAO *p);

int limitamapa(MAPA *map, int x, int y);

