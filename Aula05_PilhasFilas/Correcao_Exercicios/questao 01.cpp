#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *buf;
  int cap;
  int ini;
  int fim;
  int qtd;
} Queue;

void q_init(Queue *q, int cap)
{
  q->buf = (int *)malloc(sizeof(int) * cap);
  q->cap = cap;
  q->ini = 0;
  q->fim = 0;
  q->qtd = 0;
}
bool q_empty(Queue *q) { return q->qtd == 0; }
bool q_full(Queue *q) { return q->qtd == q->cap; }
int q_size(Queue *q) { return q->qtd; }

bool enqueue(Queue *q, int v)
{
  if (q_full(q))
    return false; // overflow
  q->buf[q->fim] = v;
  q->fim = (q->fim + 1) % q->cap;
  q->qtd++;
  return true;
}
bool dequeue(Queue *q, int *out)
{
  if (q_empty(q))
    return false; // underflow
  *out = q->buf[q->ini];
  q->ini = (q->ini + 1) % q->cap;
  q->qtd--;
  return true;
}
bool peek(Queue *q, int *out)
{
  if (q_empty(q))
    return false;
  *out = q->buf[q->ini];
  return true;
}

int main()
{
  int saida, remove;
  Queue *fila;
  q_init(fila, 10);
  enqueue(fila, 10);
  enqueue(fila, 1);
  enqueue(fila, 3);
  dequeue(fila, &remove);
  peek(fila, &saida);
}
