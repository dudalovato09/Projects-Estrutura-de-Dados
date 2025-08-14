#include<stdio.h>
#include<conio.h>

void funcao(int *valor);

main(void)
{
          int a;
          printf("Informe um valor: ");
          scanf("%d",&a);
          funcao(&a);//leva como passagem por referencia
          printf("O resto da divisao por 10 eh = %d", a);
          getch();
}
void funcao(int *valor)
{
    
     *valor = (*valor % 10);
}
