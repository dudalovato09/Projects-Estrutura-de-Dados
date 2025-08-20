/*4. Implemente uma função que receba como parâmetros uma lista encadeada e dois caracteres (original e novo) e troque 
todas as ocorrências do caractere original pelo caractere novo. Essa função deve obedecer ao protótipo:
	void troca (Lista2* l, char original, char novo);
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    char valor;
    struct no *proximo; 
} Lista2;

/*===== Prototipagem =====*/
void inserir_no_inicio(Lista2 **lista, char valor);
void imprimir(Lista2 *no);
void troca(Lista2 *lista, char original, char novo);
void liberar_lista(Lista2 **lista);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista2 *lista = NULL;

    inserir_no_inicio(&lista, 'a');
    inserir_no_inicio(&lista, 'b');
    inserir_no_inicio(&lista, 'a');
    inserir_no_inicio(&lista, 'c');
    inserir_no_inicio(&lista, 'a');

    printf("Lista original:\n");
    imprimir(lista);

    troca(lista, 'a', 'x');

    printf("Lista após troca:\n");
    imprimir(lista);

    liberar_lista(&lista);

    return 0;
}

/*===== Procedimentos e Funções =====*/

// Inserção no início
void inserir_no_inicio(Lista2 **lista, char valor)
{
    Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

// Imprimir lista
void imprimir(Lista2 *no)
{
    printf("\n\tLista: ");
    while (no != NULL)
    {
        printf("%c ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

// Função de troca de caracteres
void troca(Lista2 *lista, char original, char novo)
{
    while (lista != NULL)
    {
        if (lista->valor == original)
        {
            lista->valor = novo;
        }
        lista = lista->proximo;
    }
}

// Liberar lista
void liberar_lista(Lista2 **lista)
{
    Lista2 *atual = *lista;
    Lista2 *proxNo;

    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL;
}
