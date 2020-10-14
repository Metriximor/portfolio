#include<stdio.h>
#define SIZE 10

void lerNum(int vetor[])
{
  int n, i;
  for(i=0; i<SIZE; i++)
  {
    while(n<1 || n>50)
    {
      printf("%d->Introduza um numero inteiro(entre 1 e 50)\n>:", i+1);
      scanf("%d", &n);
    }
    vetor[i]=n;
    n=0;
  }
}

int max(int vetor[])
{
  int max=vetor[0], i;
  for(i=0; i<SIZE; i++)
  {
    if(vetor[i]>max)
    {
      max=vetor[i];
    }
  }
  return max;
}

int min(int vetor[])
{
  int min=vetor[0], i;
  for(i=0; i<SIZE; i++)
  {
    if(vetor[i]<min)
    {
      min=vetor[i];
    }
  }
  return min;
}

void main()
{
  int vetor[SIZE];  
  lerNum(vetor);
  printf("O maior numero dos numeros inseridos foi %d e o menor foi %d", max(vetor), min(vetor));
}
