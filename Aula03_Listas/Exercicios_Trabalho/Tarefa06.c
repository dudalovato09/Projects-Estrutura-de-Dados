/*6. Implemente uma função que receba como parâmetro uma lista encadeada e um valor inteiro n, e retire da lista todas as ocorrências de n,
e retorne a lista resultante. Imprima a lista atualizada. Essa função deve obedecer ao protótipo:
Lista* retira_n (Lista* l, int n);*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    int valor;
    struct no *proximo; // Cada nó aponta para o próximo
} Lista;

/*===== Prototipagem =====*/
Lista *cria_lista();
void inserir_no_inicio(Lista **lista, int valor);
void imprimir(Lista *lista);
Lista *retira_n(Lista *lista, int n);
void liberar_lista(Lista **lista);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista *lista = cria_lista();

    // Inserindo elementos
    inserir_no_inicio(&lista, 3);
    inserir_no_inicio(&lista, 2);
    inserir_no_inicio(&lista, 3);
    inserir_no_inicio(&lista, 1);
    inserir_no_inicio(&lista, 3);
    inserir_no_inicio(&lista, 4);

    printf("Lista original:\n");
    imprimir(lista);

    lista = retira_n(lista, 3);

    printf("Lista após retirar todas ocorrências de 3:\n");
    imprimir(lista);

    liberar_lista(&lista);

    return 0;
}

/*===== Procedimentos e Funções =====*/

// Cria lista vazia
Lista *cria_lista()
{
    return NULL;
}

// Inserção no início
void inserir_no_inicio(Lista **lista, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memória\n");
    }
}

// Imprimir lista
void imprimir(Lista *lista)
{
    printf("\n\tLista: ");
    while (lista != NULL)
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n");
}

// Retira todas as ocorrências de n
Lista *retira_n(Lista *lista, int n)
{
    Lista *ant = NULL;
    Lista *p = lista;

    while (p != NULL)
    {
        if (p->valor == n)
        {
            if (ant == NULL) // Remoção do primeiro nó
            {
                lista = p->proximo;
                free(p);
                p = lista;
            }
            else // Remoção no meio ou fim
            {
                ant->proximo = p->proximo;
                free(p);
                p = ant->proximo;
            }
        }
        else
        {
            ant = p;
            p = p->proximo;
        }
    }
    return lista;
}

// Liberar lista
void liberar_lista(Lista **lista)
{
    Lista *atual = *lista;
    Lista *proxNo;

    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL;
}
