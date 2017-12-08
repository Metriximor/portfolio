//COM APONTADORES
#include <stdio.h>
#include <stdlib.h>

void condo(float orc, float perm, float *quota)
{
  *quota=(orc*(perm/1000))/12;
}

void main()
{
  float orc, perm, quota;
  printf("Orçamento anual? Permilagem?\n");
  scanf("%f%f", &orc, &perm);
  condo(orc, perm, &quota);
  printf("\n Quota de condominio(mensal): %.2f \n", quota);
}
//POR RETORNO
#include <stdio.h>

float quotaMensal(float a,float b)
{
  float res;
  res= (a*(b/1000))/12;
  return res;
}

void main()
{
  float orc, perm;
  printf("Qual o orçamento anual e a permilagem?");
  scanf("%f%f", &orc, &perm);
  printf("\nO valor da quota mensal: %.2f euros", quotaMensal(orc, perm));
}
