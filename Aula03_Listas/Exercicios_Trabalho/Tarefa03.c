/*3. Escreva um algoritmo que inverta a ordem dos elementos de uma lista simplesmente encadeada. 
A inversão deve ser realizada de forma a não alterar a ordem física dos elementos na lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*===== Definição da Struct =====*/
typedef struct no
{
    int valor;
    struct no *proximo; // Cada nó precisa de um ponteiro para o nó seguinte
} No;

/*===== Prototipagem =====*/
void inserir_ordenado(No **lista, int num);
No *inverte(No *lista);
void imprimir(No *no);
void liberar_lista(No **lista);

/*===== Main =====*/
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor, anterior;
    No *lista = NULL, *removido, *busca;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir  \n\t2- Inverter \n\t3- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 2:
            lista = inverte(lista);
            printf("Lista invertida com sucesso!\n");
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

void inserir_ordenado(No **lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        // A lista está vazia?
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        } // Se a lista não está vazia o num é o menor?
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memória");
    }
}

// Função para inverter a lista
No *inverte(No *lista)
{
    No *ant = NULL;
    No *atual = lista;
    No *prox = NULL;

    while (atual != NULL)
    {
        prox = atual->proximo; // guarda o próximo nó
        atual->proximo = ant;  // inverte a seta
        ant = atual;           // avança 'ant'
        atual = prox;          // avança 'atual'
    }
    return ant; // novo início da lista
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