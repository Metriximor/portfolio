#include <stdio.h>

int nesimo(int n, int x)
{
  int i=0, j=1, soma, tmp, alg, res;
  while(j <= n)
  {
    tmp=i;
    while(tmp>0)
    {
      alg=tmp % 10;
      soma=soma+alg;
      tmp=tmp/10;
    }
    if(soma==x)
    {
      j++;
      printf("Numero %d e: %d\n", j-1, i);
      res = i;
    }
    soma=0;
    tmp=0;
    i++;
    //printf("Teste soma: %d", soma);
    //printf("\nTeste j: %d", j);
  }
  return res;
}

int main()
{
  int n, x;
  printf("Introduza o valor N e X:");
  scanf("%d%d", &n, &x);
  printf("O n-esimo de x e %d", nesimo(n, x));
}
