/*5. Implemente uma função que tenha como valor de retorno um ponteiro para o último n de uma lista encadeada que contém um determinado valor inteiro x.
Imprima o último elemento. Essa função deve obedecer ao protótipo:
Lista2* ultimo_x (Lista2* l, int x);*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    int valor;
    struct no *proximo; 
} Lista2;

/*===== Prototipagem =====*/
void inserir_no_inicio(Lista2 **lista, int valor);
void imprimir(Lista2 *lista);
Lista2 *ultimo_x(Lista2 *lista, int x);
void liberar_lista(Lista2 **lista);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista2 *lista = NULL;

    // Construindo a lista
    inserir_no_inicio(&lista, 5);
    inserir_no_inicio(&lista, 3);
    inserir_no_inicio(&lista, 7);
    inserir_no_inicio(&lista, 3);
    inserir_no_inicio(&lista, 9);
    inserir_no_inicio(&lista, 3);

    printf("Lista original:\n");
    imprimir(lista);

    int x = 3;
    Lista2 *ult = ultimo_x(lista, x);
    if (ult != NULL)
        printf("Último elemento com valor %d: %d\n", x, ult->valor);
    else
        printf("Valor %d não encontrado na lista\n", x);

    liberar_lista(&lista);

    return 0;
}

/*===== Procedimentos e Funções =====*/

void inserir_no_inicio(Lista2 **lista, int valor)
{
    Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memória\n");
    }
}

// Imprimir lista
void imprimir(Lista2 *lista)
{
    printf("\n\tLista: ");
    while (lista != NULL)
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n");
}

// Função que retorna o último nó com valor x
Lista2 *ultimo_x(Lista2 *lista, int x)
{
    Lista2 *ultimo = NULL;

    while (lista != NULL)
    {
        if (lista->valor == x)
        {
            ultimo = lista; 
        }
        lista = lista->proximo;
    }
    return ultimo;
}

// Liberar lista
void liberar_lista(Lista2 **lista)
{
    Lista2 *atual = *lista;
    Lista2 *proxNo;

    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL;
}
