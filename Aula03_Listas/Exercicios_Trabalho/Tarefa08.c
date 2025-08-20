/*8. Duas listas com valores int, não ordenados, simplesmente encadeados, solicite para o usuário informar o numero de
elementos das listas para que possa ser utilizado para saber quantos elementos devem ser lidos pelo usuário.
Apresente um programa que intercale as duas listas, de forma que a lista resultante contenha todos os elementos das duas listas.*/

#include <stdio.h>
#include <stdlib.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

/*===== Prototipagem =====*/
No *cria_lista();
No *inserir_no_fim(No *lista, int valor);
void imprimir(No *lista);
No *intercala(No *l1, No *l2);
void liberar_lista(No **lista);

/*===== Main =====*/
int main(void)
{
    No *l1 = cria_lista();
    No *l2 = cria_lista();
    No *resultado;
    int n1, n2, valor;

    // Lista 1
    printf("Quantos elementos na lista 1? ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Digite o elemento %d da lista 1: ", i + 1);
        scanf("%d", &valor);
        l1 = inserir_no_fim(l1, valor);
    }

    // Lista 2
    printf("Quantos elementos na lista 2? ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Digite o elemento %d da lista 2: ", i + 1);
        scanf("%d", &valor);
        l2 = inserir_no_fim(l2, valor);
    }

    // Imprimir listas originais
    printf("\nLista 1: ");
    imprimir(l1);
    printf("Lista 2: ");
    imprimir(l2);

    // Intercala listas
    resultado = intercala(l1, l2);
    printf("\nLista intercalada: ");
    imprimir(resultado);

    // Liberar memória
    liberar_lista(&l1);
    liberar_lista(&l2);
    liberar_lista(&resultado);

    return 0;
}

/*===== Procedimentos e Funções =====*/

// Cria lista vazia
No *cria_lista()
{
    return NULL;
}

// Inserção no final
No *inserir_no_fim(No *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro ao alocar memória\n");
        return lista;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (lista == NULL)
    {
        return novo;
    }

    No *p = lista;
    while (p->proximo != NULL)
    {
        p = p->proximo;
    }
    p->proximo = novo;
    return lista;
}

// Imprimir lista
void imprimir(No *lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

// Intercala duas listas
No *intercala(No *l1, No *l2)
{
    No *resultado = NULL;
    No *fim = NULL;

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            No *novo = (No *)malloc(sizeof(No));
            novo->valor = l1->valor;
            novo->proximo = NULL;

            if (resultado == NULL)
            {
                resultado = novo;
                fim = novo;
            }
            else
            {
                fim->proximo = novo;
                fim = novo;
            }

            l1 = l1->proximo;
        }

        if (l2 != NULL)
        {
            No *novo = (No *)malloc(sizeof(No));
            novo->valor = l2->valor;
            novo->proximo = NULL;

            if (resultado == NULL)
            {
                resultado = novo;
                fim = novo;
            }
            else
            {
                fim->proximo = novo;
                fim = novo;
            }

            l2 = l2->proximo;
        }
    }

    return resultado;
}

// Liberar lista
void liberar_lista(No **lista)
{
    No *atual = *lista;
    No *proxNo;

    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL;
}
