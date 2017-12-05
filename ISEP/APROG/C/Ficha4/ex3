#include <stdio.h>
#include <math.h>

int sinal(int valor)
{
  if(valor>0) /*printf("O valor e positivo\n");*/ return 1;
  else if(valor<0) /*printf("O valor e negativo\n");*/ return 0;
}

int nulo(int valor)
{
  if(valor != 0) /*printf("O valor nao e nulo\n");*/ return 1;
  else if(valor == 0) /*printf("O valor e nulo\n");*/ return 0;
}

int delta(int dados[2])
{
  //printf("1-%d 2-%d 3-%d", dados[0], dados[1], dados[2]);
  double res= dados[1]*dados[1]-4*dados[0]*dados[2];
  return res;
}

void equacao(int dados[2],int delta)
{
  float a, b;
  if(nulo(dados[0])==0)
  {
    printf("Valor de a tem de ser diferente de 0");
  }
  else
  {
    if(sinal(delta)==1)
    {
      a=(-dados[1]+sqrt(delta))/(2*dados[0]);
      b=(-dados[1]-sqrt(delta))/(2*dados[0]);
      printf("Raiz A: %f \nRaiz B: %f", a, b);
    }
    else if(sinal(delta)==0)
    {
      delta=-delta;
      float x= dados[1], y= dados[0];
      a=-x/(y*2);
      b=sqrt(delta)/(2*dados[0]);
      printf("Raiz A:%.2f+%fi\nRaiz B:%.2f-%fi", a, b, a, b);
    }
  }
}

void prompt(char pergunta[], int dado[], char tipo[], int qtd)
{
  int i;
  printf("%s", pergunta);
  if(qtd > 0)
  {
    for(i = 0; i < qtd; i++)
    {
      if     (tipo=="%d") {scanf("%d", &dado[i]);}
      else if(tipo=="%f") {scanf("%f", &dado[i]);}
      else if(tipo=="%s") {scanf("%s", &dado[i]);}
      else if(tipo=="%e") {scanf("%e", &dado[i]);}
    }
  }
  else if(qtd==1)
  {
      if     (tipo=="%d") {scanf("%d", &dado);}
      else if(tipo=="%f") {scanf("%f", &dado);}
      else if(tipo=="%s") {scanf("%s", &dado);}
      else if(tipo=="%e") {scanf("%e", &dado);}
  }
}

int main()
{
  float valor[2];
  prompt("Introduza a, b, c: ", &valor, "%d", 3);
  //printf("Delta: %d\n", delta(valor));
  equacao(valor, delta(valor));
  printf("\nEncerrando...");
}
