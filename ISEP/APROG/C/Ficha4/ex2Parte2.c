/** Construa um programa em C que leia um número inteiro positivo e determine se esse número é
perfeito (um número diz-se perfeito se a soma dos seus divisores, exceto ele próprio, é igual ao
número introduzido).
Para a construção deste programa, utilize funções com as seguintes assinaturas:
int lerInteiro() //Esta função lê números do tipo inteiro até ser digitado um número inteiro positivo.
int numeroPerfeito(int num)
//Esta função recebe um número por parâmetro e determina se é nº perfeito. Retorna 0 ou 1.
int main() // Função principal **/
#include<stdio.h>

lerInteiro()
{
  int num;
  do{
    printf("Introduza o numero que pretende verificar se é perfeito\n>:");
    scanf("%d",&num);
  }while(num<0);
  return num;
}

verificarPerfeito(int num)
{
  int i,cnt;
  for(i=1;i<num;i++)
  {
    if(num%i==0) cnt+=i;
  }
  if(cnt==num) return 1;
  else return 0;
}

void main()
{
  int num=lerInteiro();
  if(verificarPerfeito(num)) printf("O número é perfeito.");
  else printf("O número não é perfeito");
}
