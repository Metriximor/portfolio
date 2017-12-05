#include <stdio.h>

int conversao(int h, int m, int s)
{
  int seg;
  seg= h*360+m*60+s;
  return seg;
}

int leitura(int li, int ls)
{
  int valor;
  scanf("%d", &valor);
  while(valor<li||valor>ls)
  {
    printf("Valor invalido, introduza um valido: ");
    scanf("%d", &valor);
    //printf("Temp: %d", tmp);
  }
  return valor;
}

int main()
{
  int hor, min, seg, segundos, li, ls;
  printf("Introduza um limite inferior e limite superior: ");
  scanf("%d%d", &li, &ls);
  while(li>ls)
  {
    printf("Valor inválido, limite inferior deve ser inferior a limite superior: ");
    scanf("%d%d", &li, &ls);
  }
  printf("Introduza as horas: ");
  hor = leitura(li, ls);
  printf("Introduza os minutos: ");
  min = leitura(li, ls);
  printf("Introduza os segundos: ");
  seg = leitura(li, ls);
  segundos=conversao(hor, min, seg);
  printf("\nTotal em segundos %d", segundos);
}
