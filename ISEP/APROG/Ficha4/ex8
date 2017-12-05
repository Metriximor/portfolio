#include<stdio.h>

void troca(int *x, int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

void main()
{
  int a, b, c;
  printf("Qual o primeiro, segundo e terceiro numero?");
  scanf("%d%d%d", &a, &b, &c);
   if(a>b)
  {
    troca(&a, &b);
  }
  if(b>c)
  {
    troca(&b, &c);
  }
  if(a>b)
  {
    troca(&a, &b);
  }
  printf("\nOrdem crescente: 1- %d, 2- %d, 3- %d", a, b, c);
}
