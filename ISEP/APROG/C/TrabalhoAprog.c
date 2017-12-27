#include<stdio.h>
#include<string.h>

/**TODO
**/

//Defines vão aqui, nota ao criar um array com algum define nao esquecer de subtrair 1
#define MAX_CHARACTERS 50 //50
#define MAX_EQUIPAS 6 //6, nao se pode definir mais de 54 equipas
#define MAX_ALUNOSEQUIPA 8 //8
#define MAX_ATIVIDADESALUNO 5 //5
#define MAX_ATIVIDADESEQUIPA 8 //8

#define MIN_IDADE 16
#define MAX_IDADE 90

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

void escreverAluno(aluno vetAluno[], int *contadorAluno)
{
    int i;
    //Debug: printf("%d %d\n", *contadorAluno, MAX_ALUNOSEQUIPA*MAX_EQUIPAS);
    if(*contadorAluno>=(MAX_ALUNOSEQUIPA*MAX_EQUIPAS))
    {
        printf("Numero maximo de alunos alcancado.Operacao cancelada.");
        voltarAoMenu();
    }
    else
    {
        printf("Qual o nome do aluno %d:\n>:",*contadorAluno+1);
        fgets(vetAluno[*contadorAluno].nome, MAX_CHARACTERS, stdin);
        fflush(stdin);
        //Este loop for verifica que o nome do aluno é unico
        for(i=0; i<*contadorAluno; i++)
        {
            if(strcmp(vetAluno[*contadorAluno].nome, vetAluno[i].nome)==0)
            {
                printf("Ja existe um aluno com este nome. Operacao cancelada.");
                voltarAoMenu();
                //O return sem nada serve para que a função pare e volte ao menu principal;
                return;
            }
        }
        printf("Qual a idade do aluno?\n");
        //Aqui faz uma verificação de sanidade para que ninguem coloque idades absurdas nos estudantes
        do{
            printf(">:");
            scanf("%d", &vetAluno[*contadorAluno].idade);
            //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
            fflush(stdin);
        }while(vetAluno[*contadorAluno].idade<MIN_IDADE || vetAluno[*contadorAluno].idade>MAX_IDADE);
        printf("Qual o genero do aluno?(Introduza M ou m ou F ou f)\n");
        fflush(stdin);
        //Aqui faz uma verificação de sanidade para que ninguem introduza valores diferentes de 'F' 'f' 'M' e 'm'
        do{
            printf(">:");
            scanf("%c", &vetAluno[*contadorAluno].genero);
            //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
            fflush(stdin);
            //printf("%c", vetAluno[*contadorAluno].genero);
        }while(vetAluno[*contadorAluno].genero!='M' && vetAluno[*contadorAluno].genero!='F' && vetAluno[*contadorAluno].genero!='f' && vetAluno[*contadorAluno].genero!='m');

        (*contadorAluno)++;

        //Esta função é dedicada a voltar ao menu principal de forma correta.
        voltarAoMenu();
    }
}
void mostrarAluno(aluno vetAlunos[], int *contadorAlunos)
{
    int numAluno;
    //Verifica se ha alunos para mostrar, se houver 0 alunos registados nao vale a pena tentar mostrar
    if(*contadorAlunos==0)
    {
        printf("Nao ha alunos registados. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        printf("Que aluno pretende mostrar?Escolha um entre o aluno 1 e o aluno %d\n", *contadorAlunos);
        do{
                printf(">:");
                scanf("%d", &numAluno);
                //Aqui subtrai-se 1 porque o indice das matrizes começa no 0, o utilizador escolhe o aluno 1 mas o programa tem que ler o indice 0 para obter o aluno 1
                numAluno--;
                //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
                fflush(stdin);
        }while(numAluno<0 || numAluno>=*contadorAlunos);
        printf("---------Aluno %d---------\nNome: %sIdade: %d\nGenero: %c", numAluno+1, vetAlunos[numAluno].nome, vetAlunos[numAluno].idade, vetAlunos[numAluno].genero);
        //Debug: printf("%d", numAluno);
        voltarAoMenu();
    }
}
void apagarAluno(aluno vetAlunos[], int *contadorAlunos)
{
    //Para apagar tem de se escrever por cima, por isso, quando ha apenas 1 registo e nao ha nada para escrever por cima, tudo o que se faz é diminuir o contador de aluno para 0 de novo, para que ao introduzir os dados escreva em cima
    int numAluno, i;
    //Verifica se pode apagar alunos, se houver 0 alunos registados nao ha alunos para apagar
    if(*contadorAlunos==0)
    {
        printf("Nao ha alunos registados. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        if(*contadorAlunos==1)
        {
            printf("Aluno 1 apagado");
            *contadorAlunos=0;
            voltarAoMenu();
        }
        else
        {
            printf("Que aluno pretende apagar?Escolha um entre o aluno 1 e o aluno %d\n", *contadorAlunos);
            do{
                //Nao esquecer de somar ou subtrair ao contador devido ao indice começar em 0 para as matrizes!(somar quando for printf, subtrair qd for outra coisa
                printf(">:");
                scanf("%d", &numAluno);
                //Aqui subtrai-se 1 porque o indice das matrizes começa no 0, o utilizador escolhe o aluno 1 mas o programa tem que ler o indice 0 para obter o aluno 1
                numAluno--;
                //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
                fflush(stdin);
            }while(numAluno<0 || numAluno>=*contadorAlunos);
            //Debug:printf("%d %d", *contadorAlunos, numAluno);
            //Se esta condição se verificar isso quer dizer que o aluno escolhido foi o ultimo a ser registado, logo basta diminuir o contador de alunos por 1
            if(numAluno==(*contadorAlunos-1))
            {
                printf("Aluno %d apagado.", numAluno+1);
                (*contadorAlunos)--;
                voltarAoMenu();
            }
            //Neste caso vamos apagar um aluno que está no meio do vetor, por isso basta copiar os valores do vetor acima para o vetor em que pretendemos apagar
            else
            {
                for(i= numAluno; i<*contadorAlunos-1; i++)
                {
                    vetAlunos[i]=vetAlunos[i+1];
                    (*contadorAlunos)--;
                }
                printf("O aluno %d foi apagado.", numAluno+1);
                voltarAoMenu();
            }
        }
    }
}

void escreverAtividade(aluno vetAluno[], int matriz[][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1])
{
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

/**Funções adicionais não exigidas no enunciado**/
void criarEquipa()
{
    voltarAoMenu();
}

void voltarAoMenu()
{
    printf("\nPrima ENTER para voltar ao menu principal...\n");
    getchar();
}

void debug(int *contadorAlunos)
{
    printf("Pode ser registado um numero maximo de %d equipas", MAX_EQUIPAS);[MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1][MAX_EQUIPAS-1]
    printf("\nPode ser registados um numero maximo de %d alunos", (MAX_ALUNOSEQUIPA*MAX_EQUIPAS));
    printf("\nPode haver %d atividades diferentes", (MAX_EQUIPAS*MAX_ATIVIDADESEQUIPA));
    printf("\nHa %d aluno(s) registado(s).", *contadorAlunos);
    voltarAoMenu();
}

void mostrarAlunosTodos(aluno vetAlunos[], int *contadorAlunos)
{
    int i;
    if(*contadorAlunos==0)
    {
        printf("Nao ha alunos registados. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        for(i=0; i<*contadorAlunos; i++)
        {
            printf("---------Aluno %d---------\nNome: %sIdade: %d\nGenero: %c\n", i+1, vetAlunos[i].nome, vetAlunos[i].idade, vetAlunos[i].genero);
        }
        voltarAoMenu();
    }
}

void main()
{
    short int menu;
    int contadorAlunos=0;
    //Aqui criamos uma matriz de 1's e 0's que vai guardar a informação de que equipa e que atividade é que um dado aluno está registado
    //O tamanho maximo de X é o numero maximo de atividades, como cada equipa tem no maximo 8 atividades diferentes, o maximo de atividades diferentes sera max equipas * maximo de atividades por equipas(de acordo com o enunciado:6*8=48)
    //O tamanho de Y é o maximo de alunos, logo é igual ao valor previamente definido para o vetor de alunos
    //O tamanho de Z é o maximo de equipas que há(de acordo com o enunciado, 6)
    int matrizAtividadesEquipaAluno[MAX_ALUNOSEQUIPA*MAX_ATIVIDADESEQUIPA-1][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1];
    //Declaração do vetor das 6 equipas e 48 alunos(numero max de equipas*numero maximo de alunos por equipa)
    equipa vetEquipas[MAX_EQUIPAS-1];
    aluno vetAlunos[(MAX_ALUNOSEQUIPA*MAX_EQUIPAS)-1];
    do{
        //Este fflush serve para limpar no caso de enquanto havia a mensagem "Enter para voltar ao menu" ter sido introduzido algo para alem do enter.
        fflush(stdin);
        //Este printf está dividido em 2: o primeiro printf são as funções requesitadas no enunciado e o segundo são funcões ou comandos extra para o caso de alguma necessidade nao especificada no enunciado.
        printf("------Gestao Equipas------\nEscolha a opcao introduzindo o valor indicado\n1- Escrever um novo aluno\n2- Mostrar um aluno\n3- Apagar um aluno\n4- Escrever uma nova atividade\n5- Mostrar uma atividade\n6- Apagar uma atividade\n7- Mostrar os alunos de uma determinada equipa\n8- Total de respostas certas de uma equipa\n9- Media de respostas certas de uma equipa\n10- Media de idades de uma equipa\n11- Mostrar a equipa com menos tempo gasto numa determinada atividade\n12- Listar as equipas alfabeticamente\n");
        printf("13- Criar uma nova equipa[So funciona %d vezes no inicio do programa]\n14- Debug\n15- Mostrar todos os alunos\n16- Sair do programa\n--------------------------\n", MAX_EQUIPAS);
        do{
            printf(">:");
            scanf("%d", &menu);
            //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
            fflush(stdin);
        }while(menu<=0 || menu>=17);
        switch(menu)
        {
            //Nota, os break são necessários senão o programa corre todos os comandos que há, depois de cada comando correr há necessidade de dar reset de menu para = 0 senão se fosse introduzido algum caracter o programa assumiria o valor que tinha previamente e correria essa opção de novo
            case 1: escreverAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 2: mostrarAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 3: apagarAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 4: escreverAtividade(vetAlunos); menu=0; break;
            case 5: mostrarAtividade(); menu=0; break;
            case 6: apagarAtividade(); menu=0; break;
            case 7: mostrarAlunosEquipa(); menu=0; break;
            case 8: totalRespostasCerta(); menu=0; break;
            case 9: mediaRespostasCerta(); menu=0; break;
            case 10: mediaIdadesEquipa(); menu=0; break;
            case 11: menosTempo(); menu=0; break;
            case 12: listarAlfabeticamente(); menu=0; break;
            case 13: criarEquipa(); menu=0; break;
            case 14: debug(&contadorAlunos); menu=0; break;
            case 15: mostrarAlunosTodos(vetAlunos, &contadorAlunos); menu=0; break;
            case 16: menu=15; break;
            //O default está aqui se por alguma razão alguma coisa de mal acontecer ao int i o programa voltar ao menu, mas em teoria isto nunca deve correr.
            default: menu=0;
        }
    }while(menu!=15);
}
