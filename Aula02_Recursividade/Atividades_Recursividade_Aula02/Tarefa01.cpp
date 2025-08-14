/*Faça uma rotina recursiva para calcular a somatória de todos os números de 1 a N (N será lido do teclado).
Observação: se N é igual a 5 por exemplo, A somatória dos números será igual a 15, ou seja, 1+2+3+4+5 = 15 .*/

#include <stdio.h>
#include <locale.h>

int resultado;

int Somatoria_num(int num)
{

    if (num == 1)
    {
        return (1);
    }
    else
    {
        resultado = num + Somatoria_num(num - 1);
    }

    return (resultado);
}

int main(void)
{
    int num_N;
    int somatorio;

    printf("Programa para calcula a soma dos números de 1 a N:\n");

    printf("\nDigite um número:");
    scanf("%d", &num_N);

    somatorio = Somatoria_num(num_N);

    printf("\n O somatório dos números de 1 até %d = %d \n", num_N, somatorio);

    return 0;

    setlocale(LC_ALL, "portuguese");
}