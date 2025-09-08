/*O programa deve gerenciar duas listas (uma principal e outra auxiliar), as duas devem ser criadas no início do programa (main).
    As informações de cada nodo da lista devem ser:
int codigo;
char nome[50];
int diaAniversario;
int mesAniversario;
O critério de ordenação da lista é o campo codigo (chave de ordenação)
Construir um menu com as seguintes opções:
1 - Inserir elemento na lista. (Onde o usuário irá digitar os dados do elemento e depois chama-se a função para incluí-lo a lista) -> Na lista Principal
2 - Mostrar a lista. (Onde serão mostrados todos os elementos da lista, cada um com todas as suas informações) ->
solicitar que o usuário informe qual lista mostrar (principal ou auxiliar)
3 - Remover elemento da lista. (Onde deverá ser informado um código e chamada a função para remover o elemento da lista) ->
Da lista principal
4 - Mostrar Tamanho. (onde deve ser mostrado a quantidade de elementos que há na lista) -> mostrar o tamanho das 2 listas
(principal e auxiliar)
5- Copia (deve duplicar a lista principal, copiá-la, gerando uma nova lista igual (lista auxiliar)
6- Transfere (deve retirar os elementos de uma lista (principal) e colocá-los em outra (lista auxiliar), mantendo a mesma ordem
7- Divide (a primeira metade da lista deve ficar em uma lista (principal) e a outra metade em outra lista (auxiliar).
0 - Finalizar*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct No
{
    int codigo;
    char nome[50];
    int diaAniversario;
    int mesAniversario;
    struct No *proximo;
} No;

// Função inserir ordenado adaptada para sua estrutura
void inserir_ordenado(No **lista, int codigo, char nome[], int dia, int mes)
{
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo)
    {
        novo->codigo = codigo;
        strcpy(novo->nome, nome);
        novo->diaAniversario = dia;
        novo->mesAniversario = mes;

        // A lista está vazia?
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        // Se o código é menor que o primeiro elemento
        else if (novo->codigo < (*lista)->codigo)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->codigo > aux->proximo->codigo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        printf("Elemento inserido com sucesso!\n");
    }
    else
    {
        printf("Erro ao alocar memória!\n");
    }
}

// Função para mostrar a lista
void mostrar_lista(No *lista, const char *tipo)
{
    printf("\n=== Lista %s ===\n", tipo);
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    No *aux = lista;
    while (aux != NULL)
    {
        printf("Código: %d | Nome: %s | Aniversário: %02d/%02d\n",
               aux->codigo, aux->nome, aux->diaAniversario, aux->mesAniversario);
        aux = aux->proximo;
    }
    printf("\n");
}

// Função para remover elemento
void remover_elemento(No **lista, int codigo)
{
    if (*lista == NULL)
    {
        printf("Lista vazia! Não há elementos para remover.\n");
        return;
    }

    No *aux = *lista;

    // Se o elemento a ser removido é o primeiro
    if (aux->codigo == codigo)
    {
        *lista = aux->proximo;
        free(aux);
        printf("Elemento removido com sucesso!\n");
        return;
    }

    // Procura o elemento na lista
    while (aux->proximo != NULL && aux->proximo->codigo != codigo)
    {
        aux = aux->proximo;
    }

    if (aux->proximo == NULL)
    {
        printf("Elemento com código %d não encontrado!\n", codigo);
    }
    else
    {
        No *temp = aux->proximo;
        aux->proximo = temp->proximo;
        free(temp);
        printf("Elemento removido com sucesso!\n");
    }
}

// Função para contar elementos da lista
int contar_elementos(No *lista)
{
    int count = 0;
    No *aux = lista;
    while (aux != NULL)
    {
        count++;
        aux = aux->proximo;
    }
    return count;
}

// Função para copiar lista (opção 5)
void copiar_lista(No *origem, No **destino)
{
    // Limpa a lista destino primeiro
    while (*destino != NULL)
    {
        No *temp = *destino;
        *destino = (*destino)->proximo;
        free(temp);
    }

    // Copia elementos da origem
    No *aux = origem;
    while (aux != NULL)
    {
        inserir_ordenado(destino, aux->codigo, aux->nome, aux->diaAniversario, aux->mesAniversario);
        aux = aux->proximo;
    }
    printf("Lista copiada com sucesso!\n");
}

// Função para transferir lista (opção 6)
void transferir_lista(No **origem, No **destino)
{
    // Limpa a lista destino
    while (*destino != NULL)
    {
        No *temp = *destino;
        *destino = (*destino)->proximo;
        free(temp);
    }

    // Move todos os elementos
    *destino = *origem;
    *origem = NULL;
    printf("Lista transferida com sucesso!\n");
}

// Função para dividir lista (opção 7)
void dividir_lista(No **principal, No **auxiliar)
{
    if (*principal == NULL)
    {
        printf("Lista principal vazia! Não há elementos para dividir.\n");
        return;
    }

    int tamanho = contar_elementos(*principal);
    int metade = (tamanho + 1) / 2; // Primeira metade fica na principal

    // Limpa lista auxiliar
    while (*auxiliar != NULL)
    {
        No *temp = *auxiliar;
        *auxiliar = (*auxiliar)->proximo;
        free(temp);
    }

    // Encontra o ponto de divisão
    No *aux = *principal;
    for (int i = 1; i < metade && aux != NULL; i++)
    {
        aux = aux->proximo;
    }

    if (aux != NULL)
    {
        *auxiliar = aux->proximo;
        aux->proximo = NULL;
    }

    printf("Lista dividida com sucesso!\n");
    printf("Primeira metade (%d elementos) na lista principal\n", metade);
    printf("Segunda metade (%d elementos) na lista auxiliar\n", tamanho - metade);
}

// Função para liberar memória da lista
void liberar_lista(No **lista)
{
    while (*lista != NULL)
    {
        No *temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);
    }
}

int main()
{
    No *listaPrincipal = NULL;
    No *listaAuxiliar = NULL;
    int opcao, codigo, dia, mes;
    char nome[50];

    do
    {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir elemento na lista principal\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Remover elemento da lista principal\n");
        printf("4 - Mostrar tamanho das listas\n");
        printf("5 - Copiar lista principal para auxiliar\n");
        printf("6 - Transferir lista principal para auxiliar\n");
        printf("7 - Dividir lista principal\n");
        printf("0 - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n=== INSERIR ELEMENTO ===\n");
            printf("Digite o código: ");
            scanf("%d", &codigo);
            printf("Digite o nome: ");
            scanf(" %49[^\n]", nome);
            printf("Digite o dia do aniversário: ");
            scanf("%d", &dia);
            printf("Digite o mês do aniversário: ");
            scanf("%d", &mes);

            inserir_ordenado(&listaPrincipal, codigo, nome, dia, mes);
            break;

        case 2:
            printf("\nQual lista deseja mostrar?\n");
            printf("1 - Principal\n");
            printf("2 - Auxiliar\n");
            printf("Escolha: ");
            int escolha;
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                mostrar_lista(listaPrincipal, "Principal");
            }
            else if (escolha == 2)
            {
                mostrar_lista(listaAuxiliar, "Auxiliar");
            }
            else
            {
                printf("Opção inválida!\n");
            }
            break;

        case 3:
            printf("\n=== REMOVER ELEMENTO ===\n");
            printf("Digite o código do elemento a ser removido: ");
            scanf("%d", &codigo);
            remover_elemento(&listaPrincipal, codigo);
            break;

        case 4:
            printf("\n=== TAMANHO DAS LISTAS ===\n");
            printf("Lista Principal: %d elementos\n", contar_elementos(listaPrincipal));
            printf("Lista Auxiliar: %d elementos\n", contar_elementos(listaAuxiliar));
            break;

        case 5:
            copiar_lista(listaPrincipal, &listaAuxiliar);
            break;

        case 6:
            transferir_lista(&listaPrincipal, &listaAuxiliar);
            break;

        case 7:
            dividir_lista(&listaPrincipal, &listaAuxiliar);
            break;

        case 0:
            printf("Finalizando programa...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera memória antes de sair
    liberar_lista(&listaPrincipal);
    liberar_lista(&listaAuxiliar);

    return 0;
}