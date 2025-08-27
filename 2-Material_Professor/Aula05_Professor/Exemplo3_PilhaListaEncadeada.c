#include <stdlib.h>
#include <stdio.h>
// #include <stdlib.h>
struct no
{
    float info;
    struct no *prox;
};

typedef struct no No;

struct pilha
{
    No *prim;
};

typedef struct pilha Pilha;
// A fun��o cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.

Pilha *cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

/* fun��o auxiliar: insere no in�cio */
No *ins_ini(No *l, float v)
{
    No *p = (No *)malloc(sizeof(No));
    p->info = v;
    p->prox = l;
    return p;
}

/* fun��o auxiliar: retira do in�cio */
No *ret_ini(No *l)
{
    No *p = l->prox;
    free(l);
    return p;
}

// As fun��es que manipulam a pilha fazem uso dessas fun��es de lista:

void push(Pilha *p, float v)
{
    p->prim = ins_ini(p->prim, v);
}

// A pilha estar� vazia se a lista estiver vazia:
int vazia(Pilha *p)
{
    return (p->prim == NULL);
}

float pop(Pilha *p)
{
    float v;
    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        system("pause");
        exit(1); /* aborta programa */
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

// fun��o que libera a pilha deve antes liberar todos os elementos da lista.
void libera(Pilha *p)
{
    No *q = p->prim;
    while (q != NULL)
    {
        No *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

/* imprime: vers�o com lista */
void imprime(Pilha *p)
{
    No *q;
    for (q = p->prim; q != NULL; q = q->prox)
        printf("%f\n", q->info);
}

main(void)
{
    Pilha *pil;
    float val;
    pil = cria();
    printf("\n digite o primeiro elemento para inserir na pilha: ");
    scanf("%f", &val);
    push(pil, val);
    printf("\n digite o segundo elemento para inserir na pilha: ");
    scanf("%f", &val);
    push(pil, val);
    printf("\n digite o terceiro elemento para inserir na pilha: ");
    scanf("%f", &val);
    push(pil, val);
    printf("\n\n relatorio dos Elementos da pilha: \n\n");
    imprime(pil);
    val = pop(pil);
    printf("\n o valor %f foi retirado do topo da pilha\n", val);
    imprime(pil);
    val = pop(pil);
    printf("\n o valor %f foi retirado do topo da pilha\n", val);
    imprime(pil);
    val = pop(pil);
    printf("\n o valor %f foi retirado do topo da pilha\n", val);
    imprime(pil);
    // para testar se est� vazia
    /*
      val=pop(pil);
      printf("\n o valor %f foi retirado do topo da pilha\n",val);
      imprime(pil); */
    libera(pil);
    system("pause");
}