/*2) Fila encadeada + concatenação O(1)
Enunciado. Implemente uma fila encadeada com insere e remove. Em seguida, escreva concatena(A,B) que anexa
todos os elementos de B ao fim de A em O(1), ajustando apenas ponteiros. (Dica: ao esvaziar, mantenha inicio e fim coerentes.) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
// Nó da fila encadeada
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// Estrutura da fila
typedef struct
{
    No *inicio;
    No *fim;
} Fila;

/*===== Prototipagem =====*/
void f_init(Fila *f);
int f_empty(Fila *f);
void enqueue(Fila *f, int valor);
int dequeue(Fila *f);
void imprimir(Fila *f);
void concatena(Fila *a, Fila *b);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila A, B;
    int opcao, valor;

    f_init(&A);
    f_init(&B);

    do
    {
        printf("\n--- Menu Filas Encadeadas + Concatenação ---\n");
        printf("0 - Sair\n");
        printf("1 - Inserir em A\n");
        printf("2 - Inserir em B\n");
        printf("3 - Remover de A\n");
        printf("4 - Remover de B\n");
        printf("5 - Imprimir A\n");
        printf("6 - Imprimir B\n");
        printf("7 - Concatenar B em A\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite valor: ");
            scanf("%d", &valor);
            enqueue(&A, valor);
            break;
        case 2:
            printf("Digite valor: ");
            scanf("%d", &valor);
            enqueue(&B, valor);
            break;
        case 3:
            valor = dequeue(&A);
            if (valor != -1)
                printf("Removido de A: %d\n", valor);
            break;
        case 4:
            valor = dequeue(&B);
            if (valor != -1)
                printf("Removido de B: %d\n", valor);
            break;
        case 5:
            imprimir(&A);
            break;
        case 6:
            imprimir(&B);
            break;
        case 7:
            concatena(&A, &B);
            printf("Filas concatenadas (B anexada em A).\n");
            break;
        default:
            if (opcao != 0)
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

/*===== Funções =====*/

// Inicializa fila vazia
void f_init(Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

// Verifica se a fila está vazia
int f_empty(Fila *f)
{
    return (f->inicio == NULL);
}

// Insere no fim da fila
void enqueue(Fila *f, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = NULL;
        if (f_empty(f))
        {
            f->inicio = novo;
        }
        else
        {
            f->fim->proximo = novo;
        }
        f->fim = novo;
    }
    else
    {
        printf("Erro ao alocar memória.\n");
    }
}

// Remove do início da fila
int dequeue(Fila *f)
{
    if (f_empty(f))
    {
        printf("Erro: fila vazia.\n");
        return -1;
    }
    No *remover = f->inicio;
    int valor = remover->valor;
    f->inicio = remover->proximo;
    if (f->inicio == NULL)
    { // Se fila ficou vazia
        f->fim = NULL;
    }
    free(remover);
    return valor;
}

// Imprime fila
void imprimir(Fila *f)
{
    printf("\nFila: ");
    if (f_empty(f))
    {
        printf("vazia\n");
        return;
    }
    No *aux = f->inicio;
    while (aux)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

// Concatena B em A em O(1)
void concatena(Fila *a, Fila *b)
{
    if (f_empty(b))
        return; // Nada a fazer se B está vazia

    if (f_empty(a))
    {
        // Se A está vazia, apenas aponta para B
        a->inicio = b->inicio;
        a->fim = b->fim;
    }
    else
    {
        // Liga fim de A ao início de B
        a->fim->proximo = b->inicio;
        a->fim = b->fim;
    }

    // Esvazia B
    b->inicio = NULL;
    b->fim = NULL;
}
