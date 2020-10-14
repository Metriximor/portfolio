#include<stdio.h>

int lerInteiro1(int linf)
{
  int num;
  do
  {
    printf("Introduza um valor superior ou igual a %d >:", linf);
    scanf("%d", &num);
  }
  while(num<linf);
  return num;
  //Debug: printf("NUM: %d", num);
}

int lerInteiro2(int linf, int lsup)
{
  int num=0;
  do
  {
    printf("Introduza um valor superior a %d e inferior a %d >:", linf, lsup);
    scanf("%d", &num);
  }
  while(num<(linf+1) || num>(lsup-1));
  //printf("NUM: %d", num);
  return num;
}

float lerReal(float linf)
{
  float num=0;
  do
  {
    printf("Introduza um valor superior ou igual a %.2f >:", linf);
    scanf("%f", &num);
  }
  while(num<linf);
  return num;
  //Debug: printf("NUM: %f", num);
}

char lerFM()
{
  char gen;
  do 
  {
    //as proximas duas linhas servem para limpar o stdin
    fflush(stdin);
    __fpurge(stdin);
    
    //Aqui é q verifica
    printf("Introduza o genero >:");
    scanf("%c", &gen);
  }
  //aqui tem que ser && para que as condições se verifiquem
  while(gen!='F' && gen!='f' && gen!='M' && gen!='m');
  return gen;
}
void verificacao1(char sexo,int idade, int *cnt)
{
  if((sexo=='f' || sexo=='F') && idade > 10) (*cnt)++;
}

void main()
{
  //Isto seria feito muito melhor com estruturas
  int n;
  printf("Quantos funcionarios?");
  scanf("%d", &n);
  int i, cod[n], ano[n], cnt, ind[n];
  char gen[n];
  float sal[n], res1, salMin;
  printf("Introduza um salário minimo>:");
  scanf("%f", &salMin);
  for(i= 0; i < n; i++)
  {
    printf("------- Funcionario %d -------\n", i+1);
    cod[i]=lerInteiro2(0,9999);
    ano[i]=lerInteiro2(0,50);
    sal[i]=lerReal(250.50);
    gen[i]=lerFM();
    verificacao1(gen[i], ano[i], &cnt);
    if((gen[i]=='m' || gen[i]=='M') && sal[i]>salMin)
    {
      ind[i]=1;
    }
    else ind[i]=0;
  }
  res1=(cnt/n)*100.0f;
  for(i=0;i<n;i++)
  {
    printf("------- Funcionario %d -------\n", i+1);
    printf("O codigo do trabalhador e: %d\n",cod[i]);
    printf("O trabalhador esta na empresa a: %d anos\n",ano[i]);
    printf("O salario e: %.2f\n",sal[i]);
    printf("O sexo do trabalhador e: %c\n",gen[i]);
  }
  printf("-------- Fim de lista --------\n");
  printf("%.2f por cento de trabalhadores são mulheres e têm mais de 10 anos na empresa", res1);
  for(i=0;i<n;i++)
  {
    //Debug: printf("\n%d:%d", ind[i], i);
    if(ind[i]==1) printf("\nO trabalhador %d faz mais que o salário minimo establecido", cod[i]);
  }
}
