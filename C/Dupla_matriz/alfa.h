#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

double randomizador();
void imprime_vetor(double vetor[2]);
void imprime_matrizes(double matriz[2][2]);
void gera_matriz(double vetor[2], double matriz_origem[2][2], double matriz_destino[2][2], int posicao_vetor);
void preencher_vetor_e_matriz(double vet[2], double matriz[2][2]);