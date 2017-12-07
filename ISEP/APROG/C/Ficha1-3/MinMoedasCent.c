#include <stdio.h>

int main() 
{
  int moeda2euros=0, moeda1euro=0, moeda50cent=0, moeda20cent=0, moeda10cent=0, moeda5cent=0, moeda2cent=0, cent;
  printf("Quantos centimos sao? ");
  scanf("%d", &cent);
  while(cent >= 200)
  {
    moeda2euros++;
    cent=cent-200;
  }
  while(cent >= 100 && cent < 200)
  {
    moeda1euro++;
    cent=cent-100;
  }
  while(cent >= 50 && cent < 100)
  {
    moeda50cent++;
    cent=cent-50;
  }
  while(cent >= 20 && cent < 50)
  {
    moeda20cent++;
    cent=cent-20;
  }
  while(cent >= 10 && cent < 20)
  {
    moeda10cent++;
    cent=cent-10;
  }
  while(cent >= 5 && cent < 10)
  {
    moeda5cent++;
    cent=cent-5;
  }
  while(cent >= 2 && cent < 5)
  {
    moeda2cent++;
    cent=cent-2;
  }
  printf("Vais precisar de %d de dois euros, %d de um euro, %d de 50 cents, %d de 20 cents, %d de 10 cents, %d de 5 cents, %d de 2 cent e %d de 1 cent", moeda2euros, moeda1euro, moeda50cent, moeda20cent, moeda10cent, moeda5cent, moeda2cent, cent);
}
