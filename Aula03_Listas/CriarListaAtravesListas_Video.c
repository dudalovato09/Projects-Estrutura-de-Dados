/*Como criar uma lista através de duas outras listas
Gerar lista C com elementos da lista A e B*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserir_no_inicio(No **lista, int num)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

void inserir_no_fim(No **lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

void inserir_no_meio(No **lista, int num, int anterior)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != anterior && aux->proximo)
            {
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

// Procedimento que copia uma lista para outra
void copiar_lista(No **lista, No **C)
{
    No *aux = *lista;
    while (aux)
    {
        inserir_no_inicio(C, aux->valor);
        aux = aux->proximo;
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

    int opcao, valor, anterior;
    No *listaA, *listaB, *listaC;

    listaA = NULL;
    listaB = NULL;
    listaC = NULL;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- inserir no fim \n\t3- Inserir no meio \n\t4- Imprimir \n\t5- Copiar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&listaA, valor);
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&listaB, valor);
            break;
        case 2:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&listaA, valor);
            break;
        case 3:
            printf("Digite um valore o valor de referência: \n");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&listaA, valor, anterior);
            break;
        case 4:
            printf("Lista A: \n");
            imprimir(listaA);
            printf("\nLista B: \n");
            imprimir(listaB);
            printf("\nLista C: \n");
            imprimir(listaC);
            break;
        case 5:
            copiar_lista(&listaA, &listaC);
            copiar_lista (&listaB, &listaC);
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
