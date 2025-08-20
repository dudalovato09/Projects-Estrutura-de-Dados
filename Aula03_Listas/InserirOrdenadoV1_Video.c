/*Inserção de forma ordenada sem a estrutura lista*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserir_ordenado(No **lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        // A lista está vazia?
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        } // Se a lista não está vazia o num é o menor?
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memória");
    }
}

void imprimir(No *no)
{
    printf("\n\tLista: ");

    while (no != NULL)
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
    No *lista = NULL;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir ordenado \n\t2- Imprimir");
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
