#include <stdio.h>

typedef struct 
{
    float Peso;   
    int Idade;    
    float Altura; 
} Pessoa; 

void ImprimePessoa(Pessoa P) 
{
  printf("Idade: %d  Peso: %f Altura: %f\n", P.Idade, P.Peso, P.Altura);
}

int main()
{
    Pessoa Joao, P2;
    Pessoa Povo[10];

    Joao.Idade = 15;
    Joao.Peso = 60.5;
    Joao.Altura = 1.75;

    Povo[4].Idade = 23;
    Povo[4].Peso = 75.3;
    Povo[4].Altura = 1.89;
    
    printf("Informe o peso da pessoa 2:");
    scanf("%f", &Povo[2].Peso);
    printf("Informe a idade da pessoa 2:");
    scanf("%i", &Povo[2].Idade);
    printf("Informe a altura da pessoa 2:");
    scanf("%f", &Povo[2].Altura);

    P2 = Povo[4];
    P2.Idade++;

    // chama a fun��o que recebe a struct como par�metro
    ImprimePessoa(Joao);
    ImprimePessoa(Povo[4]);
    ImprimePessoa(P2);
    ImprimePessoa(Povo[2]);
   return 0;
}
