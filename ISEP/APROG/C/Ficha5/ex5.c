/* Escreva um algoritmo que leia um vetor de 80 elementos inteiros. Este deve procurar e mostrar o
menor elemento e sua posição no vetor. */
//Libraria
#include<stdio.h>

//Dicionário
#define MAX 80

//Funções
void lerVetor(int vet[])
{
  int i;
  for(i=0;i<MAX;i++)
  {
    printf("Indique qual o valor para a posição %d do vetor\n>:", i+1);
    scanf("%d", &vet[i]);
  }
}

void menorValor(int vet[],int *pos,int *min)
{
  int i, j;
  *pos=0;
  *min=vet[0];
  for(i=0;i<MAX;i++)
  {
    for(j=0;j<MAX;j++)
    {
      if(*min>vet[j])
      {
        *min=vet[j];
        *pos=j;
        printf("Teste %d\n", j);
      }
    }
  }
}

void main()
{
  int vet[MAX-1], pos, min;
  lerVetor(vet);
  menorValor(vet, &pos, &min);
  printf("O menor elemento deste vetor:%d e a sua posicao: %d", min, pos);
}
