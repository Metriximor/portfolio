#include <stdio.h>

//NÃO ESTÁ ACABADO NEM DE PERTO

int main()
{
  /** Parte 2 **/
  exercicio22();
}

int exercicio22()
{
  int oper, valor, i , j, saldo;
  char despesas, contribuinte;
  oper=3;
  while(oper!=0)
  {
    printf("Qual a operacao que deseja realizar?(1-Despesas)(2-Donativo)(0-Encerrar)\n>:");
    scanf("%d", &oper);
    if(oper==1)
    {
      printf("Qual a despesa?");
      scanf("%s", &despesas);
      printf("Qual o seu valor?");
      scanf("%d", &valor);
      i++;
      saldo= saldo-valor;
      printf("%s.....- %d €", despesas, valor);
      valor=0;
    }
    else if(oper==2)
    {
      printf("Qual o numero de contribuinte?");
      scanf("%s", &contribuinte);
      printf("Qual o valor da doacao?");
      scanf("%d", &valor);
      j++;
      saldo=saldo+valor;
      printf("\n%s.....+ %d €", contribuinte, valor);
      valor=0;
    }
    else
    {
      printf("Erro 404");
      oper=0;
    }
    printf("\nSaldo: %d", saldo);
  }
}
