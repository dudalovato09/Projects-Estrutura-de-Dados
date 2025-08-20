/*Estrutura de dados Simplismente encadeada com a estrutura lista outra forma de trabalhar com listas */

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

// Procedimento para inicializar a lista
void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int num)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++; // Incrementar o tamanho
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

void inserir_no_fim(Lista *lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar mamória \n");
    }
}

void inserir_no_meio(Lista *lista, int num, int anterior)
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
        else
        {
            aux = lista->inicio;
            while (aux->valor != anterior && aux->proximo)
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
        printf("Erro ao alocar memória \n");
    }
}

void imprimir(Lista lista) // mais fácil
{

    No *no = lista.inicio; // Quando estamos acessando um ponteiro utilizamos a -> porém quando não é utilizamos o ponto
    printf("\n\tLista tam %d: ", lista.tam);

    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

/*Pode continuar assim porém aqui não tem acesso ao tamanho

void imprimir(No *no)
{

    printf("\n\tLista: ");

    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}*/

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor, anterior;
    Lista lista;

    criar_lista(&lista);

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- inserir no fim \n\t3- Inserir no meio \n\t4- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valore o valor dereferência: \n");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
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