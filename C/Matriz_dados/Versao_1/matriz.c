#include "matriz.h"

/*
DEV's = AUGUSTO E HENRIQUE MARTINS
DATE =  30/11/2021
Proposta = MODULO DE CADASTRO DE DADOS, BUSCA E ATUALIZACAO.
*/

void abertura()
{
    printf("\n\n");
    printf("|**************************************|\n");
    printf("|                                      |\n");
    printf("|  Bem vindo ao Modulo de Cadastro!    |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|______________________________________|\n");
    printf("\n\n");
}

//Esta funcao da opcao ao usuario se quer preencher a matriz manualmente ou o sistema preenche automaticamente.
void modos()
{
    int modo = 0;
    printf("Deseja utilizar o sistema no modo prego na areia ou prego na madeira?\n");
    printf("Prego na areia = Dados preenchidos | Prego na madeira = Preencher manualmente os 10 cadastros\n");
    do
    {
        printf("Areia(1), Madeira(2) : ");
        fflush(stdin);
        scanf("%d", &modo);
        if (modo == 2)
        {
            printf("\n");
            preencher_dados();
        }
    } while (modo != 2 && modo != 1);
}

//Imprime a tabela passando parametros
void tabela_pronta()
{

    tabela(0, 10);
    /*
    endereco[10];
    cep[10]
    bairro[10]
    telefone[10]*/
}

//Esta funcao tem a finalidade de imprimir os dados da matriz de acordo com o parametro linha.
void imprimir_dados(int linha)
{
    printf("|");
    printf("%20s", nome[linha]);
    printf("||");
    printf("%20s", endereco[linha]);
    printf("||");
    printf("%20s", cep[linha]);
    printf("||");
    printf("%20s", bairro[linha]);
    printf("||");
    printf("%20s", telefone[linha]);
    printf("||");
    printf("%d", linha + 1);
    printf("\n");
}

//Esta funcao tem a finalidade de preencher os dados das matrizes de acordo com a linha.
void preencher_dados()
{
    for (int linha = 0; linha < LINHAS; linha++)
    {
        fflush(stdin);
        printf("Inserir cadastro %d de 10 cadastros\n", linha + 1);
        printf("Nome : ");
        fflush(stdin);
        gets(nome[linha]);
        printf("\n");
        printf("Endereco : ");
        fflush(stdin);
        gets(endereco[linha]);
        printf("\n");
        printf("cep : ");
        fflush(stdin);
        gets(cep[linha]);
        printf("\n");
        printf("bairro : ");
        fflush(stdin);
        gets(bairro[linha]);
        printf("\n");
        printf("telefone : ");
        fflush(stdin);
        gets(telefone[linha]);
        printf("\n");
    }
}

//Esta funcao tem a finalidade de buscar os dados de acordo com a escolha do tipo de dado informado na funcao Escolha_busca.
void busca_dados(char dados[10][21])
{
    int achou = 0;
    int localizacao;
    char busca[21];
    char opcao;
    int qtd_localizado = 0;
    printf("\n");
    printf("Digite os dados para buscar:");
    fflush(stdin);
    gets(busca);

    for (int linha = 0; linha < LINHAS; linha++)
    {

        if (strcmp(busca, dados[linha]) == 0)
        {
            printf("\n");
            tabela(linha, linha + 1);
            achou = 1;
            qtd_localizado++;
            localizacao = linha;
        }
    }

    if (!achou)
    {
        printf("Nao achou\n");

        busca_dados(dados);
    }

    if (achou)
    {
        do
        {
            printf("\n");
            printf("Deseja editar cadastro?(s/n): ");
            scanf(" %c", &opcao);
            printf("\n");
            if (qtd_localizado > 1 && opcao == 's')
            {
                printf("Qual cadastro deseja editar?\n");
                printf("Digite o ID do cadastro: ");
                scanf("%d", &localizacao);
                printf("\n");
                localizacao--;
            }
            if (opcao == 's')
            {
                atualiza_dados(localizacao);
            }
            else if (opcao == 'n')
            {
                escolha_busca();
            }
            else
            {
                printf("Favor digitar opcao valida!\n ");
            }
        } while (opcao != 's' && opcao != 'n');
    }
}

//Esta funcao tem a finalidade de escolher o tipo de dados a ser localizado. Exemplo : Nome ou Telefone
void escolha_busca()
{
    char tipo_busca;
    char escolha;
    fflush(stdin);
    do
    {
        printf("Gostaria de localizar algum cadastro?(s/n) : ");
        scanf(" %c", &escolha);
        printf("\n");
    } while (escolha != 's' && escolha != 'n');
    if (escolha == 's')
    {
        do
        {
            printf("\n");
            printf("Buscar por NOME(n) ou TELEFONE(t) : ");
            scanf(" %c", &tipo_busca);

            if (tipo_busca == 'n')
            {
                busca_dados(nome);
            }
            else if (tipo_busca == 't')
            {
                busca_dados(telefone);
            }
            else
            {
                printf("Favor digitar opcao valida!\n ");
            }

        } while (tipo_busca != 'n' && tipo_busca != 't');
    }
    return;
}

//Tem a funcao de atualizar os dados de acordo com a localizacao na matriz.
void atualiza_dados(int localizacao)
{
    char campo, opcao;
    do
    {
        do
        {
            printf("Nome(n), Endereco(e), CEP(c), Bairro(b) e telefone(t)\n");
            printf("Qual campo deseja editar ? : ");
            fflush(stdin);
            scanf(" %c", &campo);

        } while (campo != 'n' && campo != 'e' && campo != 'c' && campo != 'b' && campo != 't');
        switch (campo)
        {
        case 'n':
            printf("Nome : ");
            fflush(stdin);
            gets(nome[localizacao]);
            break;
        case 'e':
            printf("Endereco: ");
            fflush(stdin);
            gets(endereco[localizacao]);
            break;
        case 'c':
            printf("CEP: ");
            fflush(stdin);
            gets(cep[localizacao]);
            break;
        case 'b':
            printf("Bairro: ");
            fflush(stdin);
            gets(bairro[localizacao]);
            break;
        case 't':
            printf("Telefone: ");
            fflush(stdin);
            gets(telefone[localizacao]);
            break;
        }

        do
        {
            printf("Deseja editar outro campo? (s/n) : ");
            fflush(stdin);
            scanf(" %c", &opcao);
            if (opcao == 'n')
            {
                return;
            }
            else if (opcao != 's')
            {
                printf("Favor digitar opcao correta!\n");
            }

        } while (opcao != 's');
    } while (opcao == 's');
}

//Esta funcao tem a finalidade de formatar e imprimir os dados da matriz.
void tabela(int linha, int linhas)
{
    printf("_______________________________________________________________________________________________________________\n");
    printf("|                NOME||            ENDERECO||                 CEP||              BAIRRO||            TELEFONE||ID \n");
    printf("|------------------------------------------------------------------------------------------------------------||    \n");
    for (int i = linha; i < linhas; i++)
    {
        imprimir_dados(i);
    }
    printf("|------------------------------------------------------------------------------------------------------------||\n");
}

int main()
{
    abertura();
    modos();
    system("cls");
    tabela_pronta();
    printf("\n");
    escolha_busca();
    system("cls");

    tabela(0, 10);
    system("pause");
}
