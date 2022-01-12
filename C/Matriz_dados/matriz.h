#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LINHAS 10


char nome[10][21] = {"Augusto", "Henrique Martins", "Jose Paulo", "Alan", "Paulo Henrique", "Ana Carolina", "Loren", "Augusto", "Nelson", "Bruno"};
char endereco[10][21] = {"Rua 1", "Rua 2","Rua 3", "Rua 4","Rua 5", "Rua 6", "Rua 7", "Rua 8", "Rua 9", "Rua 10"};
char cep[10][9]={"74000102", "74000103","74000104","74000105","74000106","74000107","74000108","74000109","74000110","74000111"};
char bairro[10][21] ={"Centro", "leste", "Oeste", "Norte", "sul", "Noroeste", "Centro-Oeste", "Sudeste", "Sudoeste", "Nordeste"};
char telefone[10][21] ={"6299725421", "6299125428", "6299127421", "6299135421", "6299126421", "6299125321", "6299125421", "6299125431", "6299125422", "6298945122"};

void abertura();
void tabela(int linha,int linhas);
void modos();
void tabela_pronta();
void imprimir_dados(int linha);
void preencher_dados();
void busca_dados(char dados[10][21]);
void escolha_busca();
void atualiza_dados(int localizacao);