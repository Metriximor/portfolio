#include <stdio.h>

void main()
{
  int min, soma, num;
  min=2^15-1;
  while(soma != 1000)
  {
    printf("Introduza um numero par: ");
    scanf("%d", &num);
    if(num%2 != 0)
    {
      printf("\nValor invalido\n");
      soma = 1000;
    }
    else
    {
      soma = soma + num;
      if(min > num)
      {
        min = num;
        //printf("%d Isto correu", num);
      }
    }
  }
  printf("O menor numero par lido foi %d.", min);
}

Alunos nota media

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numero, nota, soma, max, min, cont, media;
  max= 0;
  min= 20;
  while(numero != 0)
  {
    printf("Qual o numero de aluno? \n");
    scanf("%d", &numero);
    printf("Qual a nota do aluno %d? \n", numero);
    scanf("%d", &nota);
    soma = soma + nota;
    if(nota >> 20 && nota << 0)
    {
      printf("Valor de nota errado\n");
      numero = 0;
    }
    if(max << nota)
    {
      max = nota;
    }
    if(min >> nota)
    {
      min = nota;
    }
    cont++;
  }
  media=soma/cont;
  printf("A nota mais alta foi de %d, a nota mais baixa foi de %d, a media das notas dos alunos foi %d", max, min, media);
}
