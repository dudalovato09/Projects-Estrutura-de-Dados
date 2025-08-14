/*2. Escreva uma função que recebe três parâmetros  A, B e C, e devolve o menor deles em A, o maior em C, e o valor do meio em B.
Caso sejam  passados valores repetidos, a ordem da resposta entre eles não importa. Imprima no main os valores de A, B e C.*/

#include <stdio.h>
#include <locale.h>

// Fução para ordenar os números
void ordenaABC(int *a, int *b, int *c)
{

    int temporaria; // variáve temporária usada para a troca de valores entre duas váriaveis para que nã se perca nenhum deles

    // *a <= *b
    if (*a > *b)
    {
        temporaria = *a;
        *a = *b;
        *b = temporaria;
    }

    // *a <= *c
    if (*a > *c)
    {
        temporaria = *a;
        *a = *c;
        *c = temporaria;
    }

    // *b <= *c
    if (*b > *c)
    {
        temporaria = *b;
        *b = *c;
        *c = temporaria;
    }
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de C: ");
    scanf("%d", &c);

    ordenaABC(&a, &b, &c);

    printf("\n Menor (A): %d \n", a);
    printf("\n Do meio (B): %d \n", b);
    printf("\n Maior (C): %d \n", c);

    return 0;
}