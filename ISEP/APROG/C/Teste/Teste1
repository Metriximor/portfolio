#include <stdio.h>

int main()
{
  int num, soma, v, alg;
  printf("Insira um numero: ");
  scanf("%d", &num);
  soma=1;
  v=0;
  if(num < 0) printf("Valor invalido");
  else
  {
    while(num > 0)
    {
      alg=num%10;
      if(alg%2==0)
      {
        soma=soma*alg;
        alg=0;
        v=1;
      }
      else alg=0;
      num=num/10;
    }
    if(v != 1) soma=0;
    printf("\nO valor dos produtos dos algarismos é %d", soma);
  }
}
