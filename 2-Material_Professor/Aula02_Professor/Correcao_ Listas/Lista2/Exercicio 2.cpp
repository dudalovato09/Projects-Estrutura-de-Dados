/*Escreva uma função que recebe três parâmetros  A, B e C, 
e devolve o menor deles em A, o maior em C, e o valor do meio em B. 
Caso sejam  passados valores repetidos, a ordem da resposta entre
 eles não importa. Imprima no main os valores de A, B e C.*/

#include<stdio.h>
#include<conio.h>

void le(int *a, int *b, int *c);

main(void)
{
          int a, b, c;
          // a leitura poderia ser aqui neste espaço.
          le(&a, &b, &c);
          printf("Valor de A %d, valor de B %d, valor de C %d.", a, b, c);
          getch();
}
void le(int *a, int *b, int *c)
{
     int max, min, outro;
     printf("\nInforme um valor para A:");
     scanf("%d",&*a);
     printf("\nInforme um valor para B:");
     scanf("%d",&*b);
     printf("\nInforme um valor para C:");
     scanf("%d",&*c);
     max = *a;
     min = *a;
     outro = *a;
     if(*b > max)
     {
               max = *b;
     }
     if(*c > max)
     {
               max = *c;
     }
     if(*b < min)
     {
               min = *b;
     }
     if(*c < min)
     {
               min = *c;
     }
     if(*b > min && *b < max)
     {
               outro = *b;
     }
     if(*c > min && *c < max)
     {
               outro = *c;
     }
     *a = min;
     *b = outro;
     *c = max;
}
