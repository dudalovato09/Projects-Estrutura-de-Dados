/*2. Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é,
calcule o número de nós da lista. Esta função deve obedecer ao protótipo:
    int comprimento (lista* l);
.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    int valor;
    struct no *proximo; 
} No;

/*===== Prototipagem =====*/
void inserir_no_inicio(No **lista, int num);
void inserir_no_fim(No **lista, int num);
No *remover(No **lista, int num);
No *buscar(No **lista, int num);
void imprimir(No *no);
int comprimento(No *lista);
void liberar_lista(No **lista);

/*===== Main =====*/
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor, anterior;
    No *lista = NULL, *removido, *busca;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- Mostrar o comprimento da lista\n\t3- Imprimir \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("O comprimento da lista é: %d\n", comprimento(lista));
            break;
        case 3:
            imprimir(lista);
            break;

        default:
            if (opcao != 0)
            {
                printf("Opção inválida! \n");
            }
            break;
        }

    } while (opcao != 0);

    liberar_lista(&lista);

    return 0;
}

/*===== Procedimentos e Funções =====*/

void inserir_no_inicio(No **lista, int num)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

// Função para calcular o comprimento da lista
int comprimento(No *lista)
{
    int cont = 0;
    No *aux = lista;

    while (aux != NULL)
    { // percorre até o final
        cont++;
        aux = aux->proximo;
    }

    return cont;
}

void imprimir(No *no)
{

    printf("\n\tLista: ");

    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

void liberar_lista(No **lista)
{
    No *atual = *lista;
    No *proxNo;

    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }

    *lista = NULL;
}