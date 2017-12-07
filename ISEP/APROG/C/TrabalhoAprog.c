#include<stdlib.h>
#include<stdio.h>

  //Define a estrutura da atividade que é praticada pelos alunos
typedef struct st_atividade
{
  int id;
  int nc;
  int sec;
} atividade;

//Define a estrutura do vetor aluno, que contem informaçao para mais tarde ser usada pela estrutura da equipa
typedef struct st_alunos
{
  char nome[100];
  int idade;
  char gen;
  
  //Estes dois vetores servem para dizer se 
  int equipa[5];
  //Soma das atividades nao pode ser maior que 5
  int atividade[7];
} alunos;

typedef struct st_equipa
{
  char escola[10];
  char localidade[50];
} equipa;

/**Um jogador pode jogar em mais do
que uma equipa (num mesmo campeonato) dentro do seu género (masculino ou feminino) desde que seja
em atividades diferentes, máximo em 5 atividades **/

void main()
{
  
  for(int i = 0; i < 47; i++)
  {
    scanf("%d", )
  }
}
