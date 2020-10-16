#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct produto
{
    char nome[50];
    char descricao[50];
    int estoque;
    float valor;
} Produto;

void printMenu()
{
    printf("\nOla! o que deseja fazer?:\n\n");
    printf("1) Adicionar Produto\n");
    printf("2) Remover Produto\n");
    printf("3) Ver Produtos\n");
    printf("4) Sair\n");
}

void printProduto(Produto p)
{
    printf("Nome: %s | Descricao: %s | Estoque: %d | Valor : %.2f\n", p.nome, p.descricao, p.estoque, p.valor);
}

void lerProduto(Produto *p)
{
    char nome[50], descricao[50];
    printf("\nDigite o nome: ");
    gets(nome);
    strcpy(p->nome, nome);

    printf("\nDigite a descricao: ");
    gets(descricao);
    strcpy(p->descricao, descricao);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->estoque);

    printf("Digite o valor: ");
    scanf("%f", &p->valor);
}

int main()
{
    int operacao = 0;
    int countProdutos = 0;

    Produto produtos[MAX_SIZE];
    Produto *pProdutos;
    pProdutos = (Produto *)calloc(0, sizeof(Produto));

    do
    {
        printMenu();
        scanf("%d", &operacao);
        getchar();

        switch (operacao)
        {
        case 1:
            countProdutos++;
            pProdutos = realloc(pProdutos, countProdutos * sizeof(Produto));
            lerProduto(&produtos[countProdutos - 1]);
            printf("\nProduto adicionado\n\n");
            break;
        case 2:
        case 3:
            printf("\n\nProdutos Cadastrados:\n\n");

            for (size_t i = 0; i < countProdutos; i++)
            {
                printProduto(produtos[i]);
            }
            break;
        case 4:
            break;
        default:
            printf("Comando Invalido.\n\n\n");
            break;
        }
    }

    while (operacao != 4);

    printf("\nAdeus!\n");

    return 0;
}

