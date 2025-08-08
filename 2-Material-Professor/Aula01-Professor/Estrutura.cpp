#include <stdio.h>

int main()
{
    int Idade[10];
    float Peso[10];

    printf("Informe o peso da pessoa 1:");
    scanf("%f", &Peso[0]);
    printf("Informe a idade da pessoa 1:");
    scanf("%i", &Idade[0]);

    printf("Informe o peso da pessoa 2:");
    scanf("%f", &Peso[1]);
    printf("Informe a idade da pessoa 2:");
    scanf("%i", &Idade[0]);

    // chama a fun��o que recebe a struct como par�metro
    printf("%d", Idade[0]);
    printf("%.2f", Peso[0]);
    return 0;
}
