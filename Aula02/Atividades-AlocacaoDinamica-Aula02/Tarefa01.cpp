/*1.Crie uma estrutura utilizando um vetor inteiro onde será realizada as operações de leitura, escrita, encontrar o maior valor, encontrar o menor valor, a média.
Imprimir os resultados encontrados.(utilizar módulos e alocação dinâmica). Utilizar os seguinte módulos: alocar memória, leitura do vetor, escrita do vetor,
encontrar elementos maior e menor, desalocar memória.*/

/*ANOTAÇÕES

> malloc
O malloc vem de memory allocation (“alocação de memória”) e serve para reservar espaço na memória RAM durante a execução do programa (alocação dinâmica).
Ele é usado quando não sabemos o tamanho exato da variável ou estrutura na hora de escrever o código, mas só vamos descobrir em tempo de execução.
Quando usamos malloc, o programa pede ao sistema operacional um pedaço de memória.
O malloc retorna o endereço do primeiro byte dessa área — ou seja, retorna um ponteiro para onde essa memória começa.

SINTAXE:
ponteiro = (tipo*) malloc(quantidade_de_bytes);

EX:
int *vetor;
vetor = (int*) malloc(5 * sizeof(int)); 


> sizeof
O sizeof serve para descobrir automaticamente quantos bytes um tipo ou variável ocupa na memória.
Isso é importante porque o tamanho de um int, float ou double pode mudar de máquina para máquina.
Usar sizeof garante que nosso código seja portável entre sistemas.

EX: 
printf("%zu\n", sizeof(int));   // Em geral, imprime 4
printf("%zu\n", sizeof(char));  // Sempre 1
printf("%zu\n", sizeof(double));// Em geral, 8
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Alocar memória do vetor
int *alocarMemoria(int tamanho)
{
    return (int *)malloc(tamanho * sizeof(int));
}

// Leitura do vetor
void lerVetor(int *vetor, int tamanho)
{

    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o valor [%d]: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

// Imprimir vetor
void escreverVetor(int *vetor, int tamanho)
{

    int i;

    printf("\n Valores do vetor:");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d", vetor[i]);
    }

    printf("\n");
}

// Encontra maior valor
int encontraMaior(int *vetor, int tamanho)
{
    int i, maior = vetor[0];
    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}

// Encontra menor valor
int encontraMenor(int *vetor, int tamanho)
{
    int i, menor = vetor[0];
    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    return menor;
}

// Calcula média
int calculaMedia(int *vetor, int tamanho)
{
    int i, soma = 0;
    for (i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    return (float)soma / tamanho;
}

// Descola memória
void deslocaMemoria(int *vetor)
{
    free(vetor);
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int tamanho;
    int *vetor;
    int maior, menor, media;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    // Aloca memória
    vetor = alocarMemoria(tamanho);
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória! \n");
        return 1;
    }

    // Leitura/Escrita
    lerVetor(vetor, tamanho);
    escreverVetor(vetor, tamanho);

    // Cálculos
    maior = encontraMaior(vetor, tamanho);
    menor = encontraMenor(vetor, tamanho);
    media = calculaMedia(vetor, tamanho);

    // Resultados
    printf("\n Maior valor: %d", maior);
    printf("\n Menor valor: %d", menor);
    printf("\n Média: %d", media);

    // Desalocar a memória
    deslocaMemoria(vetor);

    return 0;
}