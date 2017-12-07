#include<stdio.h>
#include<string.h>

//NAO ESTA ACABADO

int lerInteiro1(int linf)
{
  int num;
  do
  {
    printf("Introduza um valor superior ou igual a %d >:", linf);
    scanf("%d", &num);
  }
  while(num<linf);
  return num;
  //Debug: printf("NUM: %d", num);
}

int lerInteiro2(int linf, int lsup)
{
  int num;
  do
  {
    printf("Introduza um valor superior a %d e inferior a %d >:", linf, lsup);
    scanf("%d", &num);
  }
  while(num<linf || num>lsup);
  return num;
  //Debug: printf("NUM: %d", num);
}

float lerReal(float linf)
{
  float num;
  do
  {
    printf("Introduza um valor superior ou igual a %.2f >:", linf);
    scanf("%f", &num);
  }
  while(num<linf);
  return num;
  Debug: printf("NUM: %f", num);
}

char lerFM()
{
  char gen;
  do 
  {
    printf("Introduza o genero >:");
    scanf("%c", &gen);
  }
  while(gen!='F' || gen!='f' || gen!='M' || gen!='m');
  return gen;
}

void main()
{
  int n, cod[n], ano[n];
  char gen[n];
  float sal[n];
  printf("Quantos funcionarios?");
  scanf("%d", &n);
  for(int i= 0; i < n; i++)
  {
    printf("------- Funcionario %d -------\n", i+1);
    ano[i]=lerInteiro2(0, 50);
    cod[i]=lerInteiro2(0, 9999);
    sal[i]=lerReal(250.50);
    gen[i]=lerFM();
  }
}
