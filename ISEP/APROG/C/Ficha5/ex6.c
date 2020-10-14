/** Construa um algoritmo que leia um vetor A de 100 posições. Em seguida, compacte o vetor, retirando
os valores nulos e negativos. Coloque o resultado no vetor B. **/

//FORMA COMPLICADA, APAGANDO NUMEROS DO VETOR
#include<stdio.h>

#define MAX 100

escreverVetor(int vet[])
{
  int i;
  for(i=0;i<MAX;i++)
  {
    printf("Introduza um numero inteiro(indice %d)\n>:", i+1);
    scanf("%d", &vet[i]);
  }
}

verPositivo(int num)
{
  if(num>0) return 1;
  else return 0;
}

compactarVetor(int vet[], int *cnt)
{
  int i,j;
  for(i=0;i<MAX;i++)
  {
    if(verPositivo(vet[i])==0)
    {
      for(j=i;j<(MAX-1);j++)
      {
        vet[j]=vet[j+1];
      }
      i--;
      //Debug: printf("Cnt adicionado em %d:%d\n", i, *cnt);
      (*cnt)++;
    }
  }
}

void main()
{
  int vet[MAX-1], i, cnt=0;
  escreverVetor(vet);
  compactarVetor(vet, &cnt);
  //Debug: printf("%d",cnt);
  for(i=0;i<(MAX-cnt);i++)
  {
    printf("Indice %d: %d\n", i+1, vet[i]);
  }
}
