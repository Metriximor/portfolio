//Vai buscar as librarias
#include<stdio.h>
#include<string.h>

//Dicionário
#define NUMALUNOS 1

typedef struct st_TAluno 
{
  char nome[50];
  int numMat;/*numMat:numero Matricula*/
  char curso[50];
} TAluno;

void lerAluno(TAluno aluno[])
{
  int i;
  for(i=0; i<NUMALUNOS; i++)
  {
    printf("Introduza o nome do aluno %d\n>:", i+1);
    scanf("%s", aluno[i].nome);
    /*Para debug-> printf("%s", aluno[i].nome);*/
    
    printf("Introduza o curso do aluno %d\n>:", i+1);
    scanf("%s", aluno[i].curso);
    
    printf("Introduza a matricula do aluno %d\n>:", i+1);
    scanf("%d", &aluno[i].numMat);
    
  }
}

void escreverAluno(TAluno aluno[])
{
  int i;
  for(i=0; i<NUMALUNOS; i++)
  {
    printf("-------------------\nAluno %d\nMatricula: %d\nNome: %s\nCurso: %s\n", i+1, aluno[i].numMat, aluno[i].nome, aluno[i].curso);
  }
  printf("-------------------");
}

void main()
{
  TAluno alunos[4];
  lerAluno(alunos);
  escreverAluno(alunos);
}
