/*1. Crie um programa “lse.cpp” contendo as seguintes funções:
a) Inserção no início;
b) Inserção no final;
c) Remoção de um elemento v passado como parâmetro;
d) Busca de um elemento v;
e) Listagem dos elementos contidos na lista;
f) Liberar a memória alocada.*/

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
void inserir_no_inicio(No **lista, int num);
void inserir_no_fim(No **lista, int num);
No* remover(No **lista, int num);
No* buscar(No **lista, int num);
void imprimir(No *no);
void liberar_lista(No **lista);

/*===== Main =====*/
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao, valor, anterior;
    No *lista = NULL, *removido, *busca; // Pois no início a nossa lista está vazia

    // Menu para opções ao usuário
    do
    {
        printf("\n\t0- Sair \n\t1- Inserir no início \n\t2- inserir no fim \n\t3- Remover elemento \n\t4- Imprimir \n\t5- Buscar elemento\n");
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
            printf("Digite um valor a ser removido: \n");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido) // se remover é diferente de nulo
            {
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
            {
                printf("Elemento não existente");
            }
            break;
            break;
        case 4:
            imprimir(lista); // Não passar o enderço da lista apenas o endereço para o primeiro nó
            break;
        case 5:
            printf("Digite o valor que deseja buscar: \n");
            scanf("%d", &valor);
            busca = buscar(&lista, valor); // Poderia ser reutilizado o removido no lugar de "busca"
            if (busca)
            {
                printf("O elemento que você deseja é: %d\n", busca->valor);
            }
            else
            {
                printf("O elemento que você digitou não foi econtrado\n");
            }
            break;
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

// Procedimento para inserir no início
void inserir_no_inicio(No **lista, int num)
{ // ponteiro pra pronteiro
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

// Procedimento para inserir no final
void inserir_no_fim(No **lista, int num)
{
    No *aux, *novo = (No *)malloc(sizeof(No)); // Alocação de memória para um novo nó

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

// Função para remover elemento
No *remover(No **lista, int num)
{
    No *aux, *remover = NULL;

    if (*lista != NULL)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo; // O conteúdo da minha lsita será o próximonó após o remover
        }
        else
        {
            aux = *lista;                                      // Ponteiro auxiliar para o primeiro nó da nossa lista
            while (aux->proximo && aux->proximo->valor != num) // aux->proximo é o mesmo que aux->proximo != NULL
            {
                aux = aux->proximo;
            }
            if (aux->proximo) // se aux->proximo existie achamos o nó que queremos remover
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo; // Criando um ponteiro para esse proximo e agora estou dizendo que o aux->proximo será o que está depois dele, ao fazer isso estou mantendo minha lista ligada e criei esse ponteiro para o nó que queremos remover.
            }
        }
    }

    return remover;
}

// Função De busca de elemento
No *buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;

    while (aux && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if (aux) // aux diferente de nulo
    {
        no = aux;
    }

    return no;
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

// Função para liberar toda a memória da lista
void liberar_lista(No **lista) {
    No *atual = *lista;
    No *proxNo;

    while (atual != NULL) {
        proxNo = atual->proximo; // guarda referência para o próximo
        free(atual);             // libera o nó atual
        atual = proxNo;          // avança para o próximo
    }

    *lista = NULL; // garante que a cabeça da lista volte a NULL
}