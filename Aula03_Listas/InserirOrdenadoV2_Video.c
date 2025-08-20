/*Inserção de forma ordenada com a estrutura lista*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ordenado(Lista *lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memória");
    }
}

void imprimir(Lista lista)
{

    No *no = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);

    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor;
    Lista lista;

    criar_lista(&lista);

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir ordenado \n\t2- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 2:
            imprimir(lista);
            break;
        default:
            if (opcao != 0)
            {
                printf("Opção inválida! \n");
            }
            break;
        }

    } while (opcao != 0);

    return 0;
}