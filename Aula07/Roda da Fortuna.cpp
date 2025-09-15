#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>

#define TAMANHO 15

typedef struct No {
    float valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *frente;
    No *tras;
} Deque;


Deque* criar() {
    Deque* novoDeque = (Deque*)malloc(sizeof(Deque));
    if (novoDeque == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novoDeque->frente = NULL;
    novoDeque->tras = NULL;
    return novoDeque;
}

void inserir_no_tras(Deque* deque, float valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    novoNo->ant = deque->tras;

    if (deque->tras != NULL) {
        deque->tras->prox = novoNo;
    }
    deque->tras = novoNo;

    if (deque->frente == NULL) {
        deque->frente = novoNo;
    }
}

void rotacionar(Deque* deque) {
    if (deque->frente == NULL || deque->frente->prox == NULL) {
        return;
    }

    No* noFrente = deque->frente;
    deque->frente = noFrente->prox;
    deque->frente->ant = NULL;

    noFrente->prox = NULL;
    noFrente->ant = deque->tras;
    deque->tras->prox = noFrente;
    deque->tras = noFrente;
}

void criar_roda(Deque* roda) {
    for (int i = 0; i < TAMANHO; i++) {
        float valor = 5.00 + (float)rand() / (float)(RAND_MAX / 95.00);
        inserir_no_tras(roda, valor);
    }
}

void girar(Deque* roda, int forca) {
    for (int i = 0; i < forca; i++) {
        rotacionar(roda);
    }
}

void exibir_resultado(Deque* roda) {
    if (roda->frente != NULL) {
        printf("\n\n-- RESULTADO --\n");
        printf("A roda parou! O valor da fatia sorteada é: R$ %.2f\n", roda->frente->valor);
    } else {
        printf("\nA roda esta vazia!\n");
    }
}

void imprimir(Deque* roda) {
    if (roda == NULL || roda->frente == NULL) {
        printf("A roda esta vazia.\n");
        return;
    }
    
    printf("\n--- ESTADO ATUAL DA RODA ---\n");
    printf("(O primeiro item é a fatia onde a roda parou na ultima jogada)\n\n");
    
    No* atual = roda->frente;
    int i = 0;
    while (atual != NULL) {
        printf("Fatia %d: R$ %.2f\n", i + 1, atual->valor);
        atual = atual->prox;
        i++;
    }
    printf("-------------------------------\n");
}

void limpar_console() {
        system("cls");
        system("clear");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Deque* roda_da_fortuna = criar();
    criar_roda(roda_da_fortuna);

    char escolha;
    int forca_da_girada;
    int primeira_jogada = 1;

    do {
        limpar_console();
        printf("--- Roda da Fortuna ---\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                printf("\nPreparando para girar a roda...\n");

                imprimir(roda_da_fortuna);
                
                if (primeira_jogada) {
                    printf("Esta é a primeira jogada. A roda inicia no primeiro elemento.\n");
                    primeira_jogada = 0;
                } else {
                    printf("A roda irá girar a partir da ultima posicao sorteada (primeiro item da lista).\n");
                }
                
                forca_da_girada = rand() % TAMANHO + 1;
                
                girar(roda_da_fortuna, forca_da_girada);
                exibir_resultado(roda_da_fortuna);
                
                printf("\nPressione Enter para ver a nova posicao da roda...");
                while(getchar() != '\n');
                getchar();
                
                imprimir(roda_da_fortuna);
                
                printf("\nPressione Enter para continuar...");
                while(getchar() != '\n');
                getchar();
                break;
            
            case '2':
                printf("\nObrigado por jogar! Ate a proxima.\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                while(getchar() != '\n');
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

    } while (escolha != '2');

    
    No* atual = roda_da_fortuna->frente;
    No* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(roda_da_fortuna);

    return 0;
}
