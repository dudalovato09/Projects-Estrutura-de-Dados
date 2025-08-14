#include<stdio.h>
#include<conio.h>

int funcao(int *valor);

main(void)
{
          int a;
          printf("Informe um valor: ");
          scanf("%d",&a);
          a=funcao(a);
          printf("O resto da divisao por 10 eh = %d", a);
          getch();
}
int funcao(int valor)
{
    
     valor = (valor % 10);
     return valor;
}
