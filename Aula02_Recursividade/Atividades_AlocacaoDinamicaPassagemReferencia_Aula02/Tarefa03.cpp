/*3. Faça um programa que tenha  uma função que receba um valor inteiro do main como referência e retorne o resto da divisão deste número por 10.
Imprima o resultado no main.*/

#include <stdio.h>
#include <locale.h>

int restoPor10(int *num)
{

    return *num % 10;
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int valor, resto;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    resto = restoPor10(&valor); // Passagem por referência, recebe o valor de *num

    printf("O resto da divisão de %d por 10 é: %d", valor, resto);

    return 0;
}