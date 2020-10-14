/* Nome: Pedro Ivo Carneiro Macieira Número: 1170554 Turma: 1DB */

/*
 2º Teste Prático de Algoritmia e Programação
 Dezembro de 2017 - Turma 1??
 Código parcial para a resolução da sua prova
*/
//Libraria
#include <stdio.h>
//Dicionário
#define MAX 30

//Funções
void mostrarVetor(int v[], int n)
{
 int i;
 for (i=0;i<n;i++)
 printf("\t%d",v[i]);
 printf("\n");
}

int lerVetor(int v[])
{
 int n, i;
 printf("Quantos valores : ");
 do scanf("%d",&n); while(n<1 || n>MAX);

 for(i=0; i<n; i++) {
 printf("Valor %d : ", i);
 scanf("%d", &v[i]);
 }
 return n;
}

/* a) */
int verificarVetor(int v[],int n)
{
  int cnt=0, i;
  for(i=0;i<n;i++)
  {
    if(v[i]%2==1 && v[i]%5==0)
    {
      cnt++;
    }
  }
  return cnt;
}
/* b) */
int verificarOrdem(int v[], int n)
{
  int i;
  for(i=0;i<n-1;i++)
  {
    if(v[i]>v[i+1])
    {
      return 0;
    }
  }
  return 1;
}
/* c) */
void compararVetores(int v1[], int n1, int v2[],int n2, int *cnt)
{
  *cnt=0;
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
      if (v1[i]==v2[j]) 
      {
        (*cnt)++;
      }
    }
  }
}

int main()
{
 int n1, n2, comp; /* mumero ... */
 int v1[MAX]; /* vetor ... */
 int v2[MAX]; /* vetor ... */
 n1=lerVetor(v1);
 mostrarVetor(v1, n1);
 printf("Há %d que verificam criterios\n", verificarVetor(v1, n1));
 if(verificarOrdem)
 {
   printf("O vetor esta ordenado\n");
 }
 else
 {
   printf("O vetor nao esta ordenado\n");
 }
 
 n2=lerVetor(v2);
 mostrarVetor(v2,n2);
 
 compararVetores(v1, n1, v2, n2, &comp);
 
 printf("Há %d numeros iguais", comp);
}
