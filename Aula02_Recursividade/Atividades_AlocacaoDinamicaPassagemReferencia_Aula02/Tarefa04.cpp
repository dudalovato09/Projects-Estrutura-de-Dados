/*4. Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar o resultado de seus cálculos.
  Escreva uma função hm que converta minutos em horas-e-minutos.
  A função recebe um inteiro mnts e os endereços de duas variáveis inteiras, digamos h e m, e atribui valores a
  essas variáveis de modo que m seja menor que 60 e que 60*h + m seja igual a mnts.
  Escreva também uma função main que use a função hm.*/

#include <stdio.h>
#include <locale.h>

// Função que irá converter hora em minutos
void horarMinutos(int minutos, int *horas, int *minRestantes)
{

  *horas = minutos / 60;        // Calcula as horas
  *minRestantes = minutos % 60; // Calula os minutos
}

int main(void)
{

  setlocale(LC_ALL, "Portuguese");

  int minutos, horas, minRestantes;

  printf("Digite o total de minutos: ");
  scanf("%d", &minutos);

  horarMinutos(minutos, &horas, &minRestantes);

  printf("%d minutos equivalem a %d horas(s) e %d minutos(s)\n", minutos, horas, minRestantes);

  return 0;
}