/*4. Escreva um programa em linguagem C que solicita ao usuário a quantidade de elementos inteiros que deseja ordenar.
Depois de ler os valores em uma função, ordene em ordem crescente(em outra função). Desenvolva um módulo para imprimir o vetor ordenado.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Leitura do vetor
void lerVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor [%d]: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

// Função para ordenar o vetor em ordem crescente (Bubble Sort)
void ordenarVetor(int *vetor, int tamanho) {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Imprimir vetor
void escreverVetor(const int *vetor, int tamanho) {
    printf("\nValores do vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int n;
    int *vetor;

    printf("Quantos elementos deseja ordenar? ");
    scanf("%d", &n);

    // Alocação dinâmica (com cast para C++)
    vetor = (int *) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    lerVetor(vetor, n);
    ordenarVetor(vetor, n);
    escreverVetor(vetor, n);

    free(vetor); // Libera memória

    return 0;
}