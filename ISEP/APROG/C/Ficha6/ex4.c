//Librarias
#include<stdio.h>
#include<string.h>

//Dicionário
#define NUMALUNOS 1 //Nota:Ao definir arrays com este valor, nao esquecer de subtrair 1

//Estruturas
typedef struct disciplina
{
  int nota;
  char nome[10];
} tipo_disciplina;

typedef struct aluno
{
  char nome[10];
  char apelido[10];
  int idade;
  tipo_disciplina disc;//Diminutivo de disciplina
} aluno_tipo;

//Funções
void preencherStruct(aluno_tipo aluno[])
{
  int i=0;
  for(i=0; i<NUMALUNOS; i++)
  {
    //Vou precisar de nome, apelido, idade, disc.nome, disc.nota
    
    printf("Introduza o nome do aluno %d\n>:", i+1);
    fgets(aluno[i].nome, 10, stdin);
    //Para Debug- printf("%s", aluno->nome);
    __fpurge(stdin);
    
    printf("Introduza o apelido do aluno %d\n>:", i+1);
    fgets(aluno[i].apelido, 10, stdin);
    __fpurge(stdin);
    
    printf("Introduza a idade do aluno %d\n>:", i+1);
    scanf("%d", &aluno[i].idade);
    //Precisamos destas duas linhas para limpar o buffer do teclado
    __fpurge(stdin);
    
    printf("Introduza o nome da disciplina %d\n>:", i+1);
    fgets(aluno[i].disc.nome, 10, stdin);
    __fpurge(stdin);
    
    printf("Introduza a nota na disciplina %d\n>:", i+1);
    scanf("%d", &aluno[i].disc.nota);
    __fpurge(stdin);
  }
}

void mostrarAluno(aluno_tipo aluno[])
{
  int i;
  for(i=0; i<NUMALUNOS; i++)
  {
    printf("-------------------\nAluno %d\nNome: %sApelido: %sIdade: %d\nNome Disciplina: %sNota na disciplina: %d\n", i+1, aluno[i].nome, aluno[i].apelido, aluno[i].idade, aluno[i].disc.nome, aluno[i].disc.nota);
  }
  printf("-------------------");
}

//Função Inicial
void main()
{
  aluno_tipo alunos[NUMALUNOS-1];
  preencherStruct(alunos);
  mostrarAluno(alunos);
}
