/*Dividir uma lista em duas uma com elementos pares e outra com os elementos ímpares*/

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

// Função para dividir uma lista para criar uma lista par e uma ímpar
void dividir(No **lista, No **par, No **impar)
{
    No *aux = *lista;
    while (aux)
    {
        if (aux->valor > 0)
        {
            if (aux->valor % 2 == 0)
            {
                inserir_no_inicio(par, aux->valor);
            }
            else
            {
                inserir_no_inicio(impar, aux->valor);
            }
        }

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
    No *lista, *par, *impar;

    lista = NULL;
    par = NULL;
    impar = NULL;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- Dividir \n\t3- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            dividir(&lista, &par, &impar);
            printf("\nDivisão realizada com sucesso!!\n");
            break;
        case 3:
            printf("Lista principal: \n");
            imprimir(lista);
            printf("\nLista par: \n");
            imprimir(par);
            printf("\nLista impar: \n");
            imprimir(impar);
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