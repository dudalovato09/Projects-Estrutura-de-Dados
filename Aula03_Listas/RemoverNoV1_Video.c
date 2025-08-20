/*Como remover um nó da estrutura de lista simplismente encadeada SEM a estrutura lista*/

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

// Função para remover elemento
No *remover(No **lista, int num)
{
    No *aux, *remover = NULL;

    if (*lista != NULL)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo; // O conteúdo da minha lsita será o próximonó após o remover
        }
        else
        {
            aux = *lista;                                      // Ponteiro auxiliar para o primeiro nó da nossa lista
            while (aux->proximo && aux->proximo->valor != num) // aux->proximo é o mesmo que aux->proximo != NULL
            {
                aux = aux->proximo;
            }
            if (aux->proximo) // se aux->proximo existie achamos o nó que queremos remover
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo; // Criando um ponteiro para esse proximo e agora estou dizendo que o aux->proximo será o que está depois dele, ao fazer isso estou mantendo minha lista ligada e criei esse ponteiro para o nó que queremos remover.
            }
        }
    }

    return remover;
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
    No *lista = NULL, *removido = NULL;
    do
    {
        printf("\n\t0- Sair \n\t1- Inserir ordenado \n\t2- Remover \n\t3- Imprimir\n");
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
