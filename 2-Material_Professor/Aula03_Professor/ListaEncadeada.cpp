#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *inicializa(void);
Lista *insere(Lista *l, int valor);
void imprime(Lista *l);
int vazia(Lista *l);
Lista *busca(Lista *l, int v);
Lista *retira(Lista *l, int v);
void libera(Lista *l);

int main()
{
    Lista *listaNumeros;
    Lista *tmp;

    // Inicializa a lista;
    listaNumeros = inicializa();

    // Verifica se a lista esta vazia
    if (vazia(listaNumeros) == 1)
        printf("A lista esta vazia\n");
    else
        printf("A lista nao esta vazia\n");

    // Insere 5 valores
    listaNumeros = insere(listaNumeros, 10);
    listaNumeros = insere(listaNumeros, 15);
    listaNumeros = insere(listaNumeros, 20);
    listaNumeros = insere(listaNumeros, 23);
    listaNumeros = insere(listaNumeros, 34);

    // Imprime toda a lista
    imprime(listaNumeros);

    // Busca o valor 20
    tmp = busca(listaNumeros, 20);

    if (tmp != NULL)
        printf("O valor foi encontrado: %d\n", tmp->info);
    else
        printf("Valor nao encontrado\n");

    // Busca um elemento que nao existe
    tmp = busca(listaNumeros, 22);
    if (tmp != NULL)
        printf("O valor foi encontrado: %d\n", tmp->info);
    else
        printf("Valor nao encontrado\n");

    // Retira o valor 20
    listaNumeros = retira(listaNumeros, 20);

    // Imprime novamente se o valor 20
    imprime(listaNumeros);

    // Limpa a lista
    libera(listaNumeros);

    system("pause");
}

Lista *busca(Lista *l, int v)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;

    return NULL; /* n�o achou o elemento */
}

int vazia(Lista *l)

{
    if (l == NULL)
        return 1;
    else
        return 0;
}

void imprime(Lista *l)
{
    Lista *p; /* vari�vel auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

Lista *insere(Lista *l, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

Lista *inicializa(void)
{
    return NULL;
}

Lista *retira(Lista *l, int v)
{
    Lista *ant = NULL; /* ponteiro para elemento anterior */
    Lista *p = l;      /* ponteiro para percorrer a lista*/

    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }

    /* verifica se achou elemento */
    if (p == NULL)
        return l; /* n�o achou: retorna lista original */

    /* retira elemento */
    if (ant == NULL)
    {
        /* retira elemento do inicio */
        l = p->prox;
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void libera(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
        free(p);            /* libera a mem�ria apontada por p */
        p = t;              /* faz p apontar para o pr�ximo */
    }
}
