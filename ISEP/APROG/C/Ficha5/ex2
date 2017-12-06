/* Escreva um algoritmo que leia e mostre um vetor de n elementos inteiros. A seguir, conte quantos
valores pares existem no vetor. O valor de n deve ser validado por forma a garantir que seja sempre
positivo e esteja no intervalo 1<n<=100. */

//Libraria
#include<stdio.h>

//Funçoes
int perguntarN()
{
  int n;
  printf("Quantos numeros inteiros tem o vetor?\n>:");
  do{
    scanf("%d", &n);
  }while(n<=1 || n>100);
  return n;
}

void preencherVetor(int vet[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Valor %d do vetor\n>:", i+1);
    scanf("%d", &vet[i]);
  }
}

int contarPares(int vet[],int n)
{
  int i,cnt=0;
  for(i=0;i<n;i++)
  {
    if(vet[i]%2==0)
    {
      cnt++; 
    }
  }
}

void main()
{
  int n=perguntarN(), vetor[n-1];
  preencherVetor(vetor, n);
  printf("O vetor tem %d numeros pares", contarPares(vetor, n));
}
