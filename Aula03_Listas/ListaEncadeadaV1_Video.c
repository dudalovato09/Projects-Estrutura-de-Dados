/*Inserção no início, meio, fim e impressão de uma lista encadeada*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int valor;
    struct no *proximo; // Cada nó precisa de um ponteiro para o nó seguinte
} No;

// Procedimento para inserir no início
void inserir_no_inicio(No **lista, int num)
{ // ponteiro pra pronteiro
    No *novo = (No*) malloc(sizeof(No));

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

// Procedimento para inserir no final
void inserir_no_fim(No **lista, int num)
{
    No *aux, *novo = (No*) malloc(sizeof(No)); // Alocação de memória para um novo nó

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL; // Já podemos dizer que o próximo é nulo pois será onserido no final

        // é o primeiro?
        if (*lista == NULL) // Verificar se nossa fila é vazia
        {
            *lista = novo; // Se for vazia o conteúdo ou primeiro nó da nossa fila será o novo nó
        }
        else // Caso tenha pelo menos um nó a gente cria um ponteiro auxiliar para o primeiro nó
        {
            aux = *lista;
            while (aux->proximo) // Você percorre a lista com o ponteiro auxiliar enquanto o próximo for diferente de nulo
            {
                aux = aux->proximo;
            }

            aux->proximo = novo; // Quando o próximo for nulo o aux seta próximo recebrá o novo nó
        }
    }
    else
    {
        printf("Erro ao alocar mamória \n");
    }
}

// Procedimento para insersis no meio
void inserir_no_meio(No **lista, int num, int anterior /*Valor para guiar inserção no meio*/)
{ // Anterior seria uma referência para conseguirmos inserir no meio
    No *aux, *novo = (No*) malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        // é o primeiro?
        if (*lista == NULL) // Quando a lista estiver vazia
        {
            novo->proximo = NULL;
            *lista = novo; // SE NÃO FOR O PRIMEIRO NÓ NÃO PODEMOS ALTERAR O CONTEÚDO DA VARIÁVEL *LISTA
        }
        else
        {
            aux = *lista;                                  // Auxiiliar aponta para o início da nossa lista
            while (aux->valor != anterior && aux->proximo) // While pois precisaremos percorrer a lista para achar o elemento
            {
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memória \n");
    }
}

// Imprimir lista
void imprimir(No *no)
{ // Como não vamos fazer uma modificação na lista não precisamos de um ponteiro para ponteiro, apenas um parâmetro que aponte para o primeiro Nó

    printf("\n\tLista: "); //\t tabulação

    while (no != NULL) // Como não sabemos qual o tamanha dessa lista precisamos do while
    {
        printf("%d ", no->valor);
        no = no->proximo; // Como é lista encadeada preciso opercorrer ela e pra isso aponto para o proximo, pois assim quando ele for nulo quebra o looping
    }
    printf("\n\n");
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor, anterior;
    No *lista = NULL; // Pois no início a nossa lista está vazia

    // Menu para opções ao usuário
    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- inserir no fim \n\t3- Inserir no meio \n\t4- Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: \n");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3: // Se atentar para inserir no meio
            printf("Digite um valore o valor dereferência: \n");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior); // Passar 3 parâmetros
            break;
        case 4:
            imprimir(lista); // Não passar o enderço da lista apenas o endereço para o primeiro nó
            break;
        default:
            if (opcao != 0)
            {
                printf("Opção inválida! \n");
            }
            break;
        }

    } while (opcao != 0);

    return 0;
}
