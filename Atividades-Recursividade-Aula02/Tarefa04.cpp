/*Crie um programa que calcula o máximo divisor comum entre dois números usando a recursão.
Observação : Dois números naturais sempre têm divisores comuns. Assim, o máximo divisor comum entre os dois é o maior de seus divisores.
Exemplificando...os divisores comuns de 12 e 18 são 1,2,3 e 6. Dentre eles, 6 é o maior. Então, chamamos o 6 de máximo divisor comum de 12 e 18 e indicamos m.d.c.(12,18) = 6.*/

#include <stdio.h>
#include <locale.h>

int Maximo_div(int num1, int num2)
{

    if (num2 != 0)
    {
        return Maximo_div(num2, num1 % num2);
    }
    else
    {
        return num1;
    }
}

int main(void)
{

    int n1, n2, calculo;

    printf("Digite dois números inteiros positivos: \n");
    scanf("%d %d", &n1, &n2);

    calculo = Maximo_div(n1, n2);

    printf("\n O máximo divisor comum entre %d e %d é: %d", n1, n2, calculo);

    return 0;
}