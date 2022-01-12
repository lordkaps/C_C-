#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "forca.h" // << Outro arquivo final .h contendo as assinaturas das funcoes
// bibliotecas acima, ou Header files para este arquivo. Colocando #include "forca.h"

//assinaturas de funcao DENTRO
/*
void abertura();
void escolhepalavra();
void desenhaforca();
void chuta();
void telafinal();

int jachutou(char letra);
int perdeu();
int ganhou();
*/

//Variaveis globais
int tentativas = 0;

char palavrasecreta[TAMANHO_CHAR];
char chutes[26]; //armazena o chute

void abertura()
{

    printf("\n\n");
    printf("|**************************************|\n");
    printf("|     Bem vindo ao Jogo da Forca!      |\n");
    printf("|Utilize letras MaiUsculas para jogar  |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

void escolhepalavra()
{
    //Lendo arquivo txt a cada enter.
    FILE *arquivo;

    arquivo = fopen("ListaPalavras.txt", "r"); // onde vem o nome primeiro do arquivo e depois o que fazer, "r" para ler read

    //verificando se o arquivo esta disponivel ou se existe, se o ponteiro nao esta certo
    if (arquivo == 0)
    {
        printf("Desculpe, nao foi possivel ler o aquivo com as palavras,\n verifique e tente abrir novamente\n\n");
        exit(1);
    }

    //lendo a primeira linha - sendo colocado no arquivo a quantidade de palavras
    int qtdpalavras;
    fscanf(arquivo, "%d", &qtdpalavras);

    //criando randomico para ler e gravar a palavra selecionada no array de caracteres palavrasecreta
    srand(time(0));
    int nu_randon = rand() % qtdpalavras; // de 0 a quantidade de palavras ou numero enorme dividindo pela qtdpalavras pegando o resto

    //Irá ler linha a linha no arquivo e quando chegar no nu_randon irá parar e ficar salvo a palavra lida no arquivo neste momento
    //gravando a palavra no array char palavrasecreta
    for (int p = 0; p <= nu_randon; p++)
    {
        fscanf(arquivo, "%s", palavrasecreta);
    }

    fclose(arquivo); // fechando arquivo para não ficar preso ao programa.

    // sprintf(palavrasecreta, "MELANCIA"); - Colocando dentro do array palavrasecreta direto
}

void desenhaforca()
{
    int erros = 0;
    erros = letraserradas();

    printf("  _______                   \n");
    printf(" |/      |                  \n");

    printf(" |      %c%c%c                 \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c                 \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c                    \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c                  \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));

    printf(" |                          \n");
    printf("_|_____                     \n");
    printf("\n\n");

    // varrer palavra salva
    for (int l = 0; l < strlen(palavrasecreta); l++)
    {
        // Verifica a Letra Chutada para apresentar
        int achou = jachutou(palavrasecreta[l]);

        if (achou) // se achou for verdadeiro na posição do jachutou imprime a letra na posição da palavra secreta
        {
            printf("[%c]", palavrasecreta[l]);
        }
        else
        {
            printf("[_]");
        }
    }
    printf("\n\n");
}

void chuta()
{
    char chute;

    printf("Digite uma Letra: ");
    scanf(" %c", &chute);
    printf("\n");

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra)
{
    int achou = 0;
    //varrer o chute
    for (int c = 0; c < tentativas; c++)
    {
        //se a letra foi chutada e esta salva na array chutes na posicao C for igual a letra da palavra secreta, ele marca achou = 1
        if (chutes[c] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

int letraserradas()
{

    int erros = 0;
    // varrer chutes novamente e verificar quantidade de chutes errados
    for (int c = 0; c < tentativas; c++)
    {
        int existe = 0;

        for (int p = 0; p < strlen(palavrasecreta); p++)
        {

            if (chutes[c] == palavrasecreta[p])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
        {
            erros++;
        }
    }
    return erros;
}

int perdeu()
{
    return letraserradas() >= 5;
}

int ganhou()
{

    //verificar se todas as letras da palavra secreta existem no array dos chutes
    int pontos = 0;
    for (int l = 0; l < strlen(palavrasecreta); l++)
    {
        for (int c = 0; c < tentativas; c++)
        {
            if (palavrasecreta[l] == chutes[c])
            {
                pontos++;
            }
        }
    }
    return pontos == strlen(palavrasecreta);
}

void telafinal()
{
    if (perdeu())
    {
        printf("\n");
        printf("                  uu$$$$$$$$$$$uu             			  \n");
        printf("               uu$$$$$$$$$$$$$$$$$uu         			  \n");
        printf("              u$$$$$$$$$$$$$$$$$$$$$u         			  \n");
        printf("            u$$$$$$$$$$$$$$$$$$$$$$$u         			  \n");
        printf("           u$$$$$$$$$$$$$$$$$$$$$$$$$u       		      \n");
        printf("           u$$$$$$*   *$$$*   *$$$$$$u        			  \n");
        printf("           *$$$$*      u$u       $$$$*      		      \n");
        printf("            $$$u       u$u       u$$$       		      \n");
        printf("            $$$u      u$$$u      u$$$        			  \n");
        printf("             *$$$$uu$$$   $$$uu$$$$*       			      \n");
        printf("              *$$$$$$$*   *$$$$$$$*       			      \n");
        printf("                u$$$$$$$u$$$$$$$u        				  \n");
        printf("                 u$*$*$*$*$*$*$u         				  \n");
        printf("      uuu        $$u$ $ $ $ $u$$       uuu  	          \n");
        printf("      u$$$$       $$$$$u$u$u$$$       u$$$$   	          \n");
        printf("      $$$$$uu      *$$$$$$$$$*     uu$$$$$$     	      \n");
        printf("    u$$$$$$$$$$$uu    *****    uuuu$$$$$$$$$     	      \n");
        printf("    $$$$***$$$$$$$$$$uuu   uu$$$$$$$$$***$$$*             \n");
        printf("     ***      **$$$$$$$$$$$uu **$***         			  \n");
        printf("              uuuu **$$$$$$$$$$uuu         				  \n");
        printf("     u$$$uuu$$$$$$$$$uu **$$$$$$$$$$$uuu$$$ 	          \n");
        printf("     $$$$$$$$$$****           **$$$$$$$$$$$*  	          \n");
        printf("       *$$$$$*                      **$$$$**  	          \n");
        printf("         $$$*                         $$$$*      	      \n\n");
        printf("Infelizmente voce perdeu! Jogue novamente!\n\n");
    }
    else
    {
        printf("\n");
        printf("						$$$$$$$$$$$$$$$$$$$$$$$$$    							\n");
        printf("                      $$$$$$$$$$$$$$$$$$$$$$$$$$$$$								\n");
        printf("                    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         $$   $$$$$		\n");
        printf("    $$$$$$        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$$$$$$$		\n");
        printf(" $$ $$$$$$      $$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$       $$$$$$$$		\n");
        printf(" $$$$$$$$$     $$$$$$$$$$  ()  $$$$$$$$$$$  ()    $$$$$$$$$$$    $$$$$$$$		\n");
        printf("   $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$			\n");
        printf("   $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  $$$$$$			\n");
        printf("    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$			\n");
        printf("     $$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$		\n");
        printf("    $$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$		\n");
        printf("    $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$		\n");
        printf("   $$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$	\n");
        printf("   $$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$			\n");
        printf("  $$$$       $$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      $$$$					\n");
        printf("             $$$$$     $$$$$$$$$$$$$$$$$$$$$$$$$         $$$					\n");
        printf("               $$$$          $$$$$$$$$$$$$$$           $$$$						\n");
        printf("                $$$$$                                $$$$$						\n");
        printf("                 $$$$$$      $$$$$$$$$$$$$$        $$$$$						\n");
        printf("                   $$$$$$$$     $$$$$$$$$$$$$   $$$$$$$							\n");
        printf("                      $$$$$$$$$$$ $$$$$$$$$$$$ $$$$$							\n");
        printf("                         $$$$$$$$$ $$$$$$$$$$$$$$								\n");
        printf("                                 $$$$$$$$$$$$$$$								\n");
        printf("                                     $$$$$$$$$$$$								\n");
        printf("                                      $$$$$$$$$$$								\n");
        printf("                                        $$$$$$$$								\n");

        printf("Parabens voce ganhou! \n\n");
    }
}

void adicionapalavra()
{
    char escolha;
    printf("Gostaria de adicionar uma palavra ao banco? (S/N): ");
    scanf(" %c", &escolha);
    printf("\n");

    if (escolha == 'S')
    {
        char novapalavra[TAMANHO_CHAR];

        printf("Digite a nova palavra, em letras MAIUSCULAS: ");
        scanf("%s", novapalavra);
        printf("\n");
        printf("%s\n", novapalavra);
        printf("A palavra esta correta? (S/N) : ");
        scanf(" %c", &escolha);

        FILE *arquivo;
        if (escolha == 'S')
        {
            arquivo = fopen("ListaPalavras.txt", "r+");

            if (arquivo == 0)
            {
                printf("Desculpe, nao foi possivel abrir o arquivo,\n verifique e tente abrir novamente\n\n");
                exit(1);
            }
            int qtdpalavras;
            fscanf(arquivo, "%d", &qtdpalavras); // ira ler a primeira linha que tem a qtd e gravar em qtdpalavras depois add +1
            qtdpalavras++;

            fseek(arquivo, 0, SEEK_END);         // posiciona a linha da leitura ou gravacao do arquivo. Colocando na primeira em zero 0
            fprintf(arquivo, "%d", qtdpalavras); // gravando qtd na primeira linha.

            fseek(arquivo, 0, SEEK_END); // gravando a nova palavra na utima linha
            fprintf(arquivo, "\n%s", novapalavra);
            printf("Gravado com sucesso!\n");

            fclose(arquivo);
        }
    }
    printf("OK, bye!\n");
}

int main() //funcao principal
{
    setlocale(LC_ALL, "Portuguese.1252");
    //Abertura do jogo
    escolhepalavra();
    abertura();

    do
    {
        //Imprime a palavra secreta e o [_]
        desenhaforca();
        chuta();
        system("cls");

    } while (!perdeu() && !ganhou());

    desenhaforca();
    telafinal();

    adicionapalavra();
}
