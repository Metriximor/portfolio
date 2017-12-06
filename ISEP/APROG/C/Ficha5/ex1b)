/* 
Algoritmo mistério
 ED: S, VEC[] inteiro
Inicio
 S ← 0
 Para I ← 1 até 10 Passo 1 Fazer
  Escrever(‘Digite um valor:’)
  Ler(VEC[I])
  S ← S + VEC [I]* VEC[I]
 FimPara
 Escrever(‘Resultado =’,S)
 Para I ← 1 até 10 Passo 1 Fazer
  Escrever(‘Valor na posição:’, i, ’=’, VEC[I])
 FimPara
Fim
*/
//Librarias
#include<stdio.h>

//Dicionário
#define MAX 10

//Funções
void quadrado(int VEC[])
{
  int i;
  for(i=0;i<MAX;i++)
  {
    VEC[i]= VEC[i]*VEC[i];
  }
}

int main()
{
  int s=0, i, VEC[MAX-1];
  for(i=1;i<=MAX;i++)
  {
    printf("Digite um valor:\n>:");
    scanf("%d", &VEC[i]);
    s += VEC[i]*VEC[i];
  }
  printf("Resultado = %d\n", s);
  quadrado(VEC);
  for(i=1;i<=MAX;i++)
  {
    printf("Valor na posição: %d = %d\n", i, VEC[i]);
  }
}
