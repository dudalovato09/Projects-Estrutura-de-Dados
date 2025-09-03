/*1) Fila circular (array fixo) com enqueue, dequeue, peek, size
Enunciado. Implemente uma fila circular com capacidade fixa N e funções: q_init, q_empty, q_full, q_size, enqueue, dequeue, peek.
Trate overflow (não inserir se cheia) e underflow (não remover se vazia). (Base: inserção no fim e remoção no início; vetor tem tamanho pré-definido.)*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5 // Capacidade fixa da fila

/*===== Definição da Struct =====*/
// Estrutura da fila circular
typedef struct
{
    int dados[MAX]; // Vetor fixo que armazena os elementos
    int inicio;     // Índice do início da fila
    int fim;        // Índice do fim da fila
    int tamanho;    // Quantos elementos estão atualmente na fila
} Fila;

/*===== Prototipagem =====*/
void q_init(Fila *f);
int q_empty(Fila *f);
int q_full(Fila *f);
int q_size(Fila *f);
void enqueue(Fila *f, int valor);
int dequeue(Fila *f);
int peek(Fila *f);
void imprimir(Fila *f);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila fila;
    int opcao, valor;

    q_init(&fila); // Inicializa a fila

    do
    {
        printf("\n--- Menu da Fila Circular ---\n");
        printf("0 - Sair\n");
        printf("1 - Enqueue (inserir)\n");
        printf("2 - Dequeue (remover)\n");
        printf("3 - Peek (primeiro elemento)\n");
        printf("4 - Tamanho da fila\n");
        printf("5 - Imprimir fila\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            enqueue(&fila, valor);
            break;
        case 2:
            valor = dequeue(&fila);
            if (valor != -1)
                printf("Removido: %d\n", valor);
            break;
        case 3:
            valor = peek(&fila);
            if (valor != -1)
                printf("Primeiro da fila: %d\n", valor);
            break;
        case 4:
            printf("Tamanho atual: %d\n", q_size(&fila));
            break;
        case 5:
            imprimir(&fila);
            break;
        default:
            if (opcao != 0)
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

/*===== Funções =====*/

// Inicializa a fila vazia
void q_init(Fila *f)
{
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Verifica se a fila está vazia
int q_empty(Fila *f)
{
    return (f->tamanho == 0);
}

// Verifica se a fila está cheia
int q_full(Fila *f)
{
    return (f->tamanho == MAX);
}

// Retorna o tamanho atual da fila
int q_size(Fila *f)
{
    return f->tamanho;
}

// Insere elemento no fim da fila (enqueue)
void enqueue(Fila *f, int valor)
{
    if (q_full(f))
    {
        printf("Erro: fila cheia (overflow)\n");
        return;
    }
    // Atualiza o índice de fim de forma circular
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
}

// Remove elemento do início da fila (dequeue)
int dequeue(Fila *f)
{
    if (q_empty(f))
    {
        printf("Erro: fila vazia (underflow)\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return valor;
}

// Retorna o primeiro elemento da fila sem remover (peek)
int peek(Fila *f)
{
    if (q_empty(f))
    {
        printf("Erro: fila vazia (underflow)\n");
        return -1;
    }
    return f->dados[f->inicio];
}

// Imprime os elementos da fila
void imprimir(Fila *f)
{
    printf("\nFila: ");
    if (q_empty(f))
    {
        printf("vazia\n");
        return;
    }
    int i, idx;
    for (i = 0; i < f->tamanho; i++)
    {
        idx = (f->inicio + i) % MAX;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}
