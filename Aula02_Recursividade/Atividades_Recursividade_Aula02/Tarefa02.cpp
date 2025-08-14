/*Crie um programa em Linguagem C que conte os dígitos de um determinado número usando recursão.
Observação: se o usuário inserir o número 250, a saída esperada deve ser : o número digitado tem 3 dígitos.*/

#include <stdio.h>
#include <locale.h>

int Digitos_num(int num)
{
    if (num < 0) // tratar números negativos
        num = -num;

    if (num < 10) // caso base: só tem um dígito
        return 1;
    else
        return 1 + Digitos_num(num / 10); // recursão
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int numero, contador;

    printf("Programa para contar o número de dígitos:\n");
    printf("Insira o número: ");
    scanf("%d", &numero);

    contador = Digitos_num(numero);

    printf("\nQuantidade de dígitos = %d\n\n", contador);

    return 0;
}
