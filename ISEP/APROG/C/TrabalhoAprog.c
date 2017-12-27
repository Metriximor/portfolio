#include<stdio.h>
#include<string.h>

//Defines vão aqui, nota ao criar um array com algum define nao esquecer de subtrair 1
#define MAX_CHARACTERS 50
#define MAX_EQUIPAS 6
#define MAX_ALUNOSEQUIPA 8
#define MAX_ATIVIDADESALUNO 5

//Structs vão aqui, todas as structs começam com o nome st_ para indicar que é o nome da struct sem typedef
typedef struct st_atividade{
    int idAtividade;
    int contadorCorreto;
    //Assumindo que este é o tempo que todos os alunos demoraram a completar a atividade
    int tempo;
}atividade;

typedef struct st_aluno{
    char nome[MAX_CHARACTERS+1];
    //Têm que ser restrita a valores realistas mais tarde.
    int idade;
    char genero;
    atividade ativ[MAX_ATIVIDADESALUNO-1][MAX_EQUIPAS];
}aluno;

typedef struct st_equipa{
    char sigla[MAX_CHARACTERS+1];
    char localidade[MAX_CHARACTERS+1];
    aluno alu[MAX_ALUNOSEQUIPA-1];
}equipa;

//Funções vão aqui

void escreverAluno()
{
    printf("Qual o nome do aluno;");
    //fgets();

    //Esta função é dedicada a voltar ao menu principal de forma correta.
    voltarAoMenu();
}
void mostrarAluno()
{
    voltarAoMenu();
}
void apagarAluno()
{
    voltarAoMenu();
}

void escreverAtividade()
{
    printf("Nova atividade criada, ID: %d");
    voltarAoMenu();
}
void mostrarAtividade()
{
    voltarAoMenu();
}
void apagarAtividade()
{
    voltarAoMenu();
}

void mostrarAlunosEquipa(/*sigla equipa*/)
{
    voltarAoMenu();
}

void totalRespostasCerta()
{
    voltarAoMenu();
}
void mediaRespostasCerta()//media por cada atividade
{
    voltarAoMenu();
}

void mediaIdadesEquipa()
{
    voltarAoMenu();
}

void menosTempo()
{
    voltarAoMenu();
}

void listarAlfabeticamente()
{
    voltarAoMenu();
}

void menu()
{
    //Este fflush serve para limpar no caso de enquanto havia a mensagem "Enter para voltar ao menu" ter sido introduzido algo para alem do enter.
    fflush(stdin);
    short int i;
    //Este printf está dividido em 2: o primeiro printf são as funções requesitadas no enunciado e o segundo são funcões ou comandos extra para o caso de alguma necessidade nao especificada no enunciado.
    printf("------Gestao Equipas------\nEscolha a opcao introduzindo o valor indicado\n1- Escrever um novo aluno\n2- Mostrar um aluno\n3- Apagar um aluno\n4- Escrever uma nova atividade\n5- Mostrar uma atividade\n6- Apagar uma atividade\n7- Mostrar os alunos de uma determinada equipa\n8- Total de respostas certas de uma equipa\n9- Media de respostas certas de uma equipa\n10- Media de idades de uma equipa\n11- Mostrar a equipa com menos tempo gasto numa determinada atividade\n12- Listar as equipas alfabeticamente\n");
    printf("13- Criar uma nova equipa[So funciona %d vezes no inicio do programa]\n14- Debug\n15- Sair do programa\n--------------------------\n", MAX_EQUIPAS);
    do{
        printf(">:");
        scanf("%d", &i);
        //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
        fflush(stdin);
    }while(i<=0 || i>=16);
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
        case 14: debug();
        case 15: exit(0);
        //O default está aqui se por alguma razão alguma coisa de mal acontecer ao int i o programa voltar ao menu, mas em teoria isto nunca deve correr.
        default: menu();
    }
    //Está aqui para "limpar" o i para da proxima vez que a função correr, mas tal como o default na prática é desnecessário.
    i=0;
}

//Funções adicionais não exigidas no enunciado
void criarEquipa()
{
    voltarAoMenu();
}

void voltarAoMenu()
{
    printf("\nPrima ENTER para voltar ao menu principal...\n");
    getchar();
    menu();
}

void debug()
{
    printf("Pode ser registado um numero maximo de %d equipas\n", MAX_EQUIPAS);
    printf("Pode ser registados um numero maximo de %d alunos", (MAX_ALUNOSEQUIPA*MAX_EQUIPAS));
    voltarAoMenu();
}

int main()
{
    //Declaração do vetor das 6 equipas e 48 alunos(numero max de equipas*numero maximo de alunos por equipa)
    equipa vetEquipas[MAX_EQUIPAS-1];
    aluno vetAlunos[(MAX_ALUNOSEQUIPA*MAX_EQUIPAS)-1];
    menu();
    return 0;
}
