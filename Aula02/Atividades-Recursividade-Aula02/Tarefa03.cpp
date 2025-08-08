/*Faça uma rotina recursiva em C para encontrar o fatorial de um número.
Por exemplo :
>> Digite o número: 5!
>> Saída do dado : 5*4*3*2*1 = 120  */

#include <stdio.h>
#include <locale.h>

int Fatorial(int numero)
{

    if (numero == 1)
    {
        return 1;
    }
    else
    {
        return (numero * Fatorial(numero - 1));
    }
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");
    
    int fat, num;

    printf("Fatorial de número: \n");
    printf("Insira o número: ");
    scanf("%d", &num);

    fat = Fatorial(num);

    printf("\n O fatorial de %d = %d\n", num, fat);

    return 0;
}