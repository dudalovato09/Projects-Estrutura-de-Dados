#include <stdio.h>
typedef struct
{
  int a[1000];
  int top;
} Stack;
void s_init(Stack *s) { s->top = -1; }
int empty(Stack *s) { return s->top < 0; }
void push(Stack *s, int v) { s->a[++s->top] = v; }
int pop(Stack *s) { return s->a[s->top--]; }

Stack U, R;
void do_action(int x)
{
  push(&U, x);
  while (!empty(&R))
    pop(&R);
}
int undo()
{
  if (empty(&U))
    return 0;
  int x = pop(&U);
  push(&R, x);
  return 1;
}
int redo()
{
  if (empty(&R))
    return 0;
  int x = pop(&R);
  push(&U, x);
  return 1;
}

int main()
{
  s_init(&U);
  s_init(&R);
  do_action(1);
  do_action(2);
  do_action(3);
  undo();
  undo();                              // desfaz 3 e 2
  redo();                              // refaz 2
  printf("Topo U = %d\n", U.a[U.top]); // esperado: 2
}
