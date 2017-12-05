#include<stdio.h>

void maiorMenor(float *ma, float *mn) 
{
 float num;
 printf("Digite um número real (0-termina):");
 scanf("%f",&num);
 *mn=*ma=num;
 while(num!=0.0f) 
 {
   if(*ma < num)
   {
     *ma=num;
   }
   else if(*mn > num)
   {
     *mn=num;
   }
   printf("Digite um número real (0-termina):");
   scanf("%f",&num);
 }
}

void main() 
{
 float maior, menor;
 maiorMenor(&maior, &menor);
 printf("\nMaior valor lido %.2f",maior);
 printf("\nMenor valor lido %.2f\n",menor);
}
