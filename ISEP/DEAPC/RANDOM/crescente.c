#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* formata(int *vals, int dim) {
  char* str = malloc(sizeof(int)*dim);
  for(int i = 0; i < dim; i++){
    if(str[0] == '\0') { //Para o caso da string estar vazia
      sprintf(str, "%d", vals[i]);
    }
    else {
      sprintf(str, "%s<%d",str , vals[i]);
    }
  }
  return str;
}

int main(int argc, char *argv[]) {
  //Lê os argumentos
  int max=atoi(argv[1]);
  int min=atoi(argv[2]);

  int dim=(max-min)+1;

  //Cria uma array ordenada
  int vals[dim];

  //Prenche a array com valores
  for(int i = 0; i < dim; i++){
    vals[i] = min;
    min++;
  }

  //Chama o formata e imprime
  printf("%s", formata(vals, dim));

  return 0;
} 
