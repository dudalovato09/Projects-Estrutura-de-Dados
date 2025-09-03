/*5) Undo/Redo com duas pilhas
Enunciado. Implemente do(x), undo(), redo() usando duas pilhas: U (ações feitas) e R (ações desfeitas).
do(x) limpa R. Mostre uma simulação no main. (Base: empilhar/desempilhar no topo, política LIFO.)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*===== Definição da Struct =====*/
// Nó da pilha que guarda cada ação (string)
typedef struct no
{
    char acao[50];      // A ação executada (exemplo: "Escrever A")
    struct no *proximo; // Ponteiro para o próximo nó
} No;

/*===== Prototipagem =====*/
void push(No **topo, char *acao);
No *pop(No **topo);
void imprimir_pilha(No *topo);
void liberar_pilha(No **topo);

void do_action(No **pilhaUndo, No **pilhaRedo, char *acao);
void undo(No **pilhaUndo, No **pilhaRedo);
void redo(No **pilhaUndo, No **pilhaRedo);

/*===== Main =====*/
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *pilhaUndo = NULL; // Pilha U - ações feitas
    No *pilhaRedo = NULL; // Pilha R - ações desfeitas
    int opcao;
    char acao[50];

    do
    {
        printf("\n===== MENU =====\n");
        printf("0 - Sair\n");
        printf("1 - Fazer ação (do)\n");
        printf("2 - Undo\n");
        printf("3 - Redo\n");
        printf("4 - Mostrar pilhas\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao)
        {
        case 1:
            printf("Digite a ação: ");
            fgets(acao, sizeof(acao), stdin);
            acao[strcspn(acao, "\n")] = '\0'; // remover '\n'
            do_action(&pilhaUndo, &pilhaRedo, acao);
            break;
        case 2:
            undo(&pilhaUndo, &pilhaRedo);
            break;
        case 3:
            redo(&pilhaUndo, &pilhaRedo);
            break;
        case 4:
            printf("\nPilha Undo (ações feitas): ");
            imprimir_pilha(pilhaUndo);
            printf("Pilha Redo (ações desfeitas): ");
            imprimir_pilha(pilhaRedo);
            break;
        default:
            if (opcao != 0)
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    liberar_pilha(&pilhaUndo);
    liberar_pilha(&pilhaRedo);

    return 0;
}

/*===== Procedimentos e Funções =====*/

// Empilhar ação (push)
void push(No **topo, char *acao)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        strcpy(novo->acao, acao);
        novo->proximo = *topo;
        *topo = novo;
    }
    else
    {
        printf("Erro ao alocar memória!\n");
    }
}

// Desempilhar ação (pop)
No *pop(No **topo)
{
    if (*topo != NULL)
    {
        No *removido = *topo;
        *topo = removido->proximo;
        return removido;
    }
    return NULL;
}

// Mostrar elementos da pilha
void imprimir_pilha(No *topo)
{
    if (topo == NULL)
    {
        printf("vazia\n");
    }
    else
    {
        No *aux = topo;
        while (aux != NULL)
        {
            printf("%s -> ", aux->acao);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

// Liberar toda memória da pilha
void liberar_pilha(No **topo)
{
    No *atual = *topo;
    No *proxNo;
    while (atual != NULL)
    {
        proxNo = atual->proximo;
        free(atual);
        atual = proxNo;
    }
    *topo = NULL;
}

/*===== Funções específicas de Undo/Redo =====*/

// Fazer ação: adiciona na pilha U e limpa pilha R
void do_action(No **pilhaUndo, No **pilhaRedo, char *acao)
{
    // Limpamos a pilha Redo pois toda nova ação invalida as anteriores
    liberar_pilha(pilhaRedo);
    push(pilhaUndo, acao);
    printf("Ação '%s' executada!\n", acao);
}

// Undo: tira do Undo e coloca no Redo
void undo(No **pilhaUndo, No **pilhaRedo)
{
    No *removido = pop(pilhaUndo);
    if (removido)
    {
        push(pilhaRedo, removido->acao);
        printf("Undo: desfazendo '%s'\n", removido->acao);
        free(removido);
    }
    else
    {
        printf("Nada para desfazer!\n");
    }
}

// Redo: tira do Redo e coloca de volta no Undo
void redo(No **pilhaUndo, No **pilhaRedo)
{
    No *removido = pop(pilhaRedo);
    if (removido)
    {
        push(pilhaUndo, removido->acao);
        printf("Redo: refazendo '%s'\n", removido->acao);
        free(removido);
    }
    else
    {
        printf("Nada para refazer!\n");
    }
}
