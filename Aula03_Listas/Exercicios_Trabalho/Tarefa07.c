/*7. Escreva um algoritmo que forneça o maior elemento, o menor elemento, e a média aritmética dos elementos de uma lista simplesmente encadeada.*/

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
void imprimir(No *no);
void estatisticas(No *lista);
void liberar_lista(No **lista);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int opcao, valor;
    No *lista = NULL;

    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- Imprimir \n\t3- Estatísticas\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            imprimir(lista);
            break;
        case 3:
            estatisticas(lista);
            break;
        default:
            if (opcao != 0)
                printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);

    liberar_lista(&lista);
    return 0;
}

/*===== Procedimentos e Funções =====*/

// Inserção no início
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
        printf("Erro ao alocar memória\n");
    }
}

// Imprimir lista
void imprimir(No *no)
{
    printf("\nLista: ");
    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

// Estatísticas: maior, menor e média
void estatisticas(No *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    int maior = lista->valor;
    int menor = lista->valor;
    int soma = 0, qtd = 0;

    No *p = lista;
    while (p != NULL)
    {
        if (p->valor > maior)
            maior = p->valor;
        if (p->valor < menor)
            menor = p->valor;
        soma += p->valor;
        qtd++;
        p = p->proximo;
    }

    float media = (float)soma / qtd;

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Média aritmética: %.2f\n", media);
}

// Liberar lista
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
