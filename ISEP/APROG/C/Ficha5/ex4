#include<stdio.h>
#define SIZE 20

void lerNum(int vetor[])
{
  int n, i;
  for(i=0; i<SIZE; i++)
  {
      printf("%d->Introduza um numero inteiro\n>:", i+1);
      scanf("%d", &n);
      vetor[i]=n;
      n=0;
  }
}

void troca(int vetor[])
{
  int temp, i;
  for(i=0;i<(SIZE/2);i++)
  {
    temp=vetor[i];
    vetor[i]=vetor[SIZE-i-1];
    vetor[SIZE-i-1]=temp;
  }
}

void main()
{
  int vetor[SIZE], i;
  lerNum(vetor);
  troca(vetor);
  for(i=0; i<SIZE;i++)
  {
    printf("%d-", vetor[i]);
  }
}
