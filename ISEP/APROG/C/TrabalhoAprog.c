#include<stdio.h>
#include<string.h>

//Defines vão aqui, nota ao criar um array com algum define nao esquecer de subtrair 1
#define MAX_CHARACTERS 50
#define MAX_EQUIPAS 6
#define MAX_ATIVIDADESALUNO 5

//Structs vão aqui, todas as structs começam com o nome st_ para indicar que é o nome da struct sem typedef
typedef struct st_atividade{
    int idAtividade;
    int contadorCorreto;
    //Assumindo que este é o tempo que todos os alunos demoraram a completar a atividade
    int tempo;
    //Cada atividade têm uma array com 6 espaços que ou vão ser true ou false(1 ou 0), dps ao perguntar ao aluno que equipas quer participar este pode escolher um maximo de 5 atividades diferentes, e escolher tambem que equipa de que atividade quer participar(desde que respeite ás regras do enunciado)
    //Um for loop na criação
    int verificadorEquipa[MAX_EQUIPAS-1];
}atividade;

typedef struct st_aluno{
    char nome[MAX_CHARACTERS+1];
    //Têm que ser restrita a valores realistas mais tarde.
    int idade;
    char genero;
    //Cada Aluno têm direito a participar em 5 atividades diferentes, é criado um vetor que armazena o ID das 5 atividades, em caso de não pertencer a nenhuma, ou ser apagado é substituido por -1
    int atividadeAluno[MAX_ATIVIDADESALUNO-1];
}aluno;

typedef struct st_equipa{
    char nome[MAX_CHARACTERS+1];
    char localidade[MAX_CHARACTERS+1];

}equipa;

//Funções vão aqui

void escreverAluno()
{
    printf("Qual o nome do aluno;");
    //fgets();

    printf("\nPrima ENTER para voltar ao menu principal...\n");
    fflush(stdin);
    getchar();
    menu();
}
void mostrarAluno()
{

}
void apagarAluno()
{

}

void escreverAtividade()
{

}
void mostrarAtividade()
{

}
void apagarAtividade()
{

}

void mostrarAlunosEquipa(/*sigla equipa*/)
{

}

void totalRespostasCerta()
{

}
void mediaRespostasCerta()//media por cada atividade
{

}

void mediaIdadesEquipa()
{

}

void menosTempo()
{

}

void listarAlfabeticamente()
{

}

void menu()
{
    short int i;
    //Este printf está dividido em 2: o primeiro printf são as funções requesitadas no enunciado e o segundo são funcões ou comandos extra para o caso de alguma necessidade nao especificada no enunciado.
    printf("------Gestao Equipas------\nEscolha a opcao introduzindo o valor indicado\n1- Escrever um novo aluno\n2- Mostrar um aluno\n3- Apagar um aluno\n4- Escrever uma nova atividade\n5- Mostrar uma atividade\n6- Apagar uma atividade\n7- Mostrar os alunos de uma determinada equipa\n8- Total de respostas certas de uma equipa\n9- Media de respostas certas de uma equipa\n10- Media de idades de uma equipa\n11- Mostrar a equipa com menos tempo gasto numa determinada atividade\n12- Listar as equipas alfabeticamente\n");
    printf("13- Criar uma nova equipa[So funciona %d vezes no inicio do programa]\n14- Sair do programa\n--------------------------\n>:", MAX_EQUIPAS);
    do{
        scanf("%d", &i);
        //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao do valor correto
        fflush(stdin);
    }while(i<=0 || i>=15);
    switch(i)
    {
        case 1: escreverAluno();
        case 2: mostrarAluno();
        case 3: apagarAluno();
        case 4: escreverAtividade();
        case 5: mostrarAtividade();
        case 6: apagarAtividade();
        case 7: mostrarAlunosEquipa();
        case 8: totalRespostasCerta();
        case 9: mediaRespostasCerta();
        case 10: mediaIdadesEquipa();
        case 11: menosTempo();
        case 12: listarAlfabeticamente();
        case 13: criarEquipa();
        case 14: exit(0);
        //O default está aqui se por alguma razão alguma coisa de mal acontecer ao int i o programa voltar ao menu, mas em teoria isto nunca deve correr.
        default: menu();
    }
    //Está aqui para "limpar" o i para da proxima vez que a função correr, mas tal como o default na prática é desnecessário.
    i=0;
}

//Funções adicionais
void criarEquipa()
{

}

int main()
{
    menu();
    return 0;
}
