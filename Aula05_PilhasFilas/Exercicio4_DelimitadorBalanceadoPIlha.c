/*4) Delimitadores balanceados ()[]{} com pilha
Enunciado. Verifique se uma string tem parênteses/colchetes/chaves balanceados. Ao ler um abridor, empilhe;
ao ler um fechador, verifique o topo e desempilhe. (Último aberto fecha primeiro — LIFO.)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*===== Definição da Struct =====*/
// Nó da pilha
typedef struct no
{
    char simbolo;
    struct no *proximo;
} No;

/*===== Prototipagem =====*/
void push(No **topo, char c);
char pop(No **topo);
int isEmpty(No *topo);
int delimitadoresBalanceados(char expr[]);
int corresponde(char abertura, char fechamento);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char expr[100];
    printf("Digite a expressão para verificar delimitadores:\n");
    fgets(expr, sizeof(expr), stdin);

    if (delimitadoresBalanceados(expr))
    {
        printf("Delimitadores balanceados!\n");
    }
    else
    {
        printf("Delimitadores NÃO estão balanceados.\n");
    }

    return 0;
}

/*===== Funções =====*/

// Empilha caractere
void push(No **topo, char c)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->simbolo = c;
        novo->proximo = *topo;
        *topo = novo;
    }
    else
    {
        printf("Erro ao alocar memória.\n");
    }
}

// Desempilha caractere
char pop(No **topo)
{
    if (isEmpty(*topo))
    {
        return '\0'; // Retorna nulo se pilha vazia
    }
    No *remover = *topo;
    char c = remover->simbolo;
    *topo = remover->proximo;
    free(remover);
    return c;
}

// Verifica se a pilha está vazia
int isEmpty(No *topo)
{
    return (topo == NULL);
}

// Verifica se delimitadores estão balanceados
int delimitadoresBalanceados(char expr[])
{
    No *pilha = NULL;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(&pilha, c); // Empilha abridor
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            char topo = pop(&pilha); // Desempilha último abridor
            if (!corresponde(topo, c))
            {
                return 0; // Não corresponde → desbalanceado
            }
        }
    }
    return isEmpty(pilha); // Só é balanceado se a pilha ficar vazia
}

// Confere se o fechamento corresponde ao abridor
int corresponde(char abertura, char fechamento)
{
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}
