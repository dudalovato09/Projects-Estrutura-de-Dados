/*Como buscar um elemento da estrutura de lista simplismente encadeada SEM a estrutura lista*/

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

No *remover(No **lista, int num)
{
    No *aux, *remover = NULL;

    if (*lista != NULL)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }

    return remover;
}

// Função De busca de elemento
No *buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;

    while (aux && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if (aux) // aux diferente de nulo
    {
        no = aux;
    }

    return no;
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
    No *lista = NULL, *removido = NULL, *busca = NULL;
    do
    {
        printf("\n\t0- Sair \n\t1- Inserir ordenado \n\t2- Remover \n\t3- Imprimir \n\t4- Buscar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 2:
            printf("Digite um valor a ser removido: \n");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido) // se remover é diferente de nulo
            {
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
            {
                printf("Elemento não existente");
            }
            break;
        case 3:
            imprimir(lista);
            break;
        case 4:
            printf("Digite o valor que deseja buscar: \n");
            scanf("%d", &valor);
            busca = buscar(&lista, valor); // Poderia ser reutilizado o removido no lugar de "busca"
            if (busca)
            {
                printf("O elemento que você deseja é: %d\n", busca->valor);
            }
            else
            {
                printf("O elemento que você digitou não foi econtrado\n");
            }
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
