#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo
{
  int x;
  struct nodo *prox;
} Nodo;
typedef struct
{
  int tam;
  Nodo *ini, *fim;
} Fila;

void f_init(Fila *f)
{
  f->tam = 0;
  f->ini = f->fim = NULL;
}
bool f_vazia(Fila *f) { return f->ini == NULL; }

void f_insere(Fila *f, int v)
{
  Nodo *n = (Nodo *)malloc(sizeof(Nodo));
  n->x = v;
  n->prox = NULL;
  if (f_vazia(f))
    f->ini = f->fim = n;
  else
  {
    f->fim->prox = n;
    f->fim = n;
  }
  f->tam++;
}
bool f_remove(Fila *f, int *out)
{
  if (f_vazia(f))
    return false;
  Nodo *p = f->ini;
  *out = p->x;
  f->ini = p->prox;
  if (!f->ini)
    f->fim = NULL;
  free(p);
  f->tam--;
  return true;
}
/* Concatena B ao fim de A. B fica vazia. */
void concatena(Fila *A, Fila *B)
{
  if (f_vazia(B))
    return;
  if (f_vazia(A))
  {
    *A = *B;
  }
  else
  {
    A->fim->prox = B->ini;
    A->fim = B->fim;
    A->tam += B->tam;
  }
  B->ini = B->fim = NULL;
  B->tam = 0;
}

int main()
{
  Fila *fila, *fila2;
  f_insere(fila, 10);
  f_insere(fila, 1);
  f_insere(fila, 3);
  f_insere(fila2, 3);
  concatena(fila, fila2);
}
