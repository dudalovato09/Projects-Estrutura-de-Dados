/*1. Faça um programa que chame uma função que envia como parâmetros três valores inteiros (utilizar passagem por valor )  a, b e c e retorna a
posição do maior(utilizar passagem por referência para os retornos das 2 posições) e a posição do menor valor. Exemplo: Se a = 7, b = 1 e c = 5,
o procedimento deve retornar 2 como a posição do menor e 1 como a posição do maior.*/

#include <stdio.h>
#include <locale.h>

// Encontra as psoições de amior e menor
void encontraPosicoes(int v1, int v2, int v3, int *posicaoMaior, int *posicaoMenor)
{

    // Consideramos que o primeiro elemento será o menor e o maior para que depois seja feita a comparação
    int maior = v1, menor = v1;

    *posicaoMaior = 1;
    *posicaoMenor = 1;

    // If para verificar maior

    if (v2 > maior)
    {
        maior = v2;
        *posicaoMaior = 2;
    }
    if (v3 > maior)
    {
        maior = v3;
        *posicaoMaior = 3;
    }

    // If para verificar menor
    if (v2 < menor)
    {
        menor = v2;
        *posicaoMenor = 2;
    }
    if (v3 < menor)
    {
        menor = v3;
        *posicaoMenor = 3;
    }
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int v1, v2, v3, posicaoMaior, posicaoMenor; // Sempre defirnir variáveis para receber o valor dos ponteiros

    printf("Digite o valor 1: ");
    scanf("%d", &v1);

    printf("\nDigite o valor 2: ");
    scanf("%d", &v2);

    printf("\nDigite o valor 3: ");
    scanf("%d", &v3);

    encontraPosicoes(v1, v2, v3, &posicaoMaior, &posicaoMenor);

    printf("Posição do maior valor: %d\n", posicaoMaior);
    printf("Posição do menor valor: %d\n", posicaoMenor);

    return 0;
}