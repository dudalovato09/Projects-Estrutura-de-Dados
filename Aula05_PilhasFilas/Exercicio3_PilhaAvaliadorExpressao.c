/*3) Avaliador de expressão pós‑fixa
Enunciado. Implemente a avaliação de expressões posfixas com inteiros e + - * /.
Cada número empilha; um operador desempilha dois operandos, aplica, empilha o resultado.
(Base: Top/Push/Pop no topo; política LIFO.)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/*===== Definição da Struct =====*/
// Nó da pilha
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

/*===== Prototipagem =====*/
void push(No **topo, int valor);
int pop(No **topo);
int isEmpty(No *topo);
int avaliarPosfixa(char expr[]);
int aplicarOperador(int a, int b, char op);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char expr[100];
    int resultado;

    printf("Digite a expressão pós-fixa (tokens separados por espaço):\n");
    fgets(expr, sizeof(expr), stdin);

    resultado = avaliarPosfixa(expr);
    printf("Resultado da expressão: %d\n", resultado);

    return 0;
}

/*===== Funções =====*/

// Empilha elemento no topo
void push(No **topo, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *topo;
        *topo = novo;
    }
    else
    {
        printf("Erro ao alocar memória.\n");
    }
}

// Desempilha elemento do topo
int pop(No **topo)
{
    if (isEmpty(*topo))
    {
        printf("Erro: pilha vazia.\n");
        return -1;
    }
    No *remover = *topo;
    int valor = remover->valor;
    *topo = remover->proximo;
    free(remover);
    return valor;
}

// Verifica se a pilha está vazia
int isEmpty(No *topo)
{
    return (topo == NULL);
}

// Avalia expressão pós-fixa
int avaliarPosfixa(char expr[])
{
    No *pilha = NULL;
    char *token = strtok(expr, " "); // Divide a string por espaços

    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            // Se for número, empilha
            push(&pilha, atoi(token));
        }
        else
        {
            // Se for operador, desempilha dois operandos
            int b = pop(&pilha);
            int a = pop(&pilha);
            int res = aplicarOperador(a, b, token[0]);
            push(&pilha, res);
        }
        token = strtok(NULL, " ");
    }

    return pop(&pilha); // Resultado final
}

// Aplica operador sobre dois operandos
int aplicarOperador(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Erro: divisão por zero!\n");
            exit(1);
        }
        return a / b;
    default:
        printf("Operador inválido: %c\n", op);
        exit(1);
    }
}
