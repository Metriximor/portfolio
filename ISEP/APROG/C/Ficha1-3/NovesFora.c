#include <stdio.h>

int main()
{
  int soma, resto, n;
  printf("Introduza n: ");
  scanf("%d", &n);
  while(n > 9)
  {
    while(n > 0)
    {
      resto = n%10;
      soma=resto+soma;
      n=n/10;
    }
    n=soma;
    soma=0;
  }
  printf("\nNoves fora: %d", n);
}
