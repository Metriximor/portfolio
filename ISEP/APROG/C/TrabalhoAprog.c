#include<stdio.h>
#include<string.h>

/**TODO
    Adicionar a matriz na funcao apagar
    acabar a atividade
**/

//Defines vão aqui, nota ao criar um array com algum define nao esquecer de subtrair 1
#define MAX_CHARACTERS 50 //50
#define MAX_EQUIPAS 6 //6, nao se pode definir mais de 29 ou menos de 2
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

void escreverAtividade(aluno vetAluno[], int matriz[][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1], int *contadorAlunos, int *contadorAtividades, int *contadorEquipas)
{
    //Primeiro verifica-se se todas as regras são seguidas e depois é que se escreve para as estruturas
    //Primeiro escolhe-se em que aluno vamos escrever
    int numAluno, numEquipa, erro;
    //Verifica se ha alunos para mostrar, se houver 0 alunos registados nao vale a pena tentar mostrar
    if(*contadorAlunos==0)
    {
        printf("Nao ha alunos registados. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        //Debug: *contadorEquipas=1;
        if(*contadorEquipas==0)
        {
            printf("Nao ha equipas registadas. Operacao cancelada");
            voltarAoMenu();
        }
        else
        {
            printf("Pretende escrever uma atividade a que aluno?Escolha um entre o aluno 1 e o aluno %d\n", *contadorAlunos);
            do{
                    printf(">:");
                    scanf("%d", &numAluno);
                    //Aqui subtrai-se 1 porque o indice das matrizes começa no 0, o utilizador escolhe o aluno 1 mas o programa tem que ler o indice 0 para obter o aluno 1
                    numAluno--;
                    //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
                    fflush(stdin);
            }while(numAluno<0 || numAluno>=*contadorAlunos);
            //Debug: printf("%d %d", *contadorAtividades, MAX_EQUIPAS*MAX_ATIVIDADESEQUIPA);
            //Aqui verifica se há mais atividades do que há atividades disponiveis
            if(*contadorAtividades>MAX_EQUIPAS*MAX_ATIVIDADESEQUIPA)
            {
                printf("Atingido o valor maximo de atividades tendo em conta o numero de equipas e o numero maximo de atividades por equipa.\nOperacao Cancelada.");
                voltarAoMenu();
            }
            else
            {
                //Pergunta-se em que equipa se pretende registar a nova atividadde.
                printf("Em que equipa pretende registar a atividade?(Escolha entre a equipa 1 e a equipa %d)\n", *contadorEquipas);
                do{
                    //Nao esquecer de somar ou subtrair ao contador devido ao indice começar em 0 para as matrizes!
                    printf(">:");
                    scanf("%d", &numEquipa);
                    //Aqui subtrai-se 1 porque o indice das matrizes começa no 0, o utilizador escolhe o aluno 1 mas o programa tem que ler o indice 0 para obter o aluno 1
                    numEquipa--;
                    //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
                    fflush(stdin);
                }while(numEquipa<0 || numEquipa>=*contadorEquipas);

                (*contadorAtividades)++;
                //Aqui o contador de atividades conta como o numero da atividade porque a verificaçao acontece na nova atividade que está a ser criada
                erro=verificacao(matriz, &*contadorAlunos, &*contadorEquipas, &*contadorAtividades, &numAluno, &numEquipa, &*contadorAtividades);
                Debug: printf("\nErro:%d", erro);
                voltarAoMenu();
            }
        }
    }
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
void criarEquipa(equipa vetEquipas[], int *contadorEquipas)
{
    if(*contadorEquipas>=MAX_EQUIPAS)
    {
        printf("Maximo de equipas registadas. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        int i;
        printf("Qual a sigla da equipa %d?\n", *contadorEquipas+1);
        fgets(vetEquipas[*contadorEquipas].sigla, MAX_CHARACTERS, stdin);
        //Este loop for verifica que o nome da equipa é unico
        for(i=0; i<*contadorEquipas; i++)
        {
            if(strcmp(vetEquipas[*contadorEquipas].sigla, vetEquipas[i].sigla)==0)
            {
                printf("Ja existe uma equipa com este nome. Operacao cancelada.");
                voltarAoMenu();
                //O return sem nada serve para que a função pare e volte ao menu principal;
                return;
            }
        }

        printf("Qual a localidade da equipa %d?\n", *contadorEquipas+1);
        fgets(vetEquipas[*contadorEquipas].localidade, MAX_CHARACTERS, stdin);
        (*contadorEquipas)++;
        voltarAoMenu();
    }
}

void voltarAoMenu()
{
    printf("\nPrima ENTER para voltar ao menu principal...\n");
    getchar();
}

void debug(int *contadorAlunos, int *contadorEquipas)
{
    printf("Pode ser registado um numero maximo de %d equipas", MAX_EQUIPAS);
    printf("\nPode ser registados um numero maximo de %d alunos", (MAX_ALUNOSEQUIPA*MAX_EQUIPAS));
    printf("\nPode haver %d atividades diferentes", (*contadorEquipas*MAX_ATIVIDADESEQUIPA));
    printf("\nHa %d aluno(s) registado(s).", *contadorAlunos);
    printf("\nHa %d equipa(s) registada(s).", *contadorEquipas);
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

/*Esta funcao verifica:
1- Não há a mesma atividade em equipas diferentes para o mesmo aluno
2- Não há mais de 5 atividades diferentes no mesmo aluno
3- Na mesma equipa a soma de todas as atividades de todos os alunos não é <= a 8
4- Na mesma equipa há <= de 8 alunos*/
int verificacao(int matriz[][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1], int *contadorAlunos, int *contadorEquipas, int *contadorAtividades, int *numAluno, int *numEquipa, int *numAtividade)
{
    int x, y, z, contador=0;
    //A primeira verificação: No mesmo x(atividade) e z(aluno) a soma de todos os y(equipas) é <=1, se a soma for superior significa que a mesma atividade estaria a ser adicionada em equipas diferentes
    for(y=0; y<*contadorEquipas;y++)
    {
        if(matriz[*numAtividade][y][*numAluno]) contador++;
    }
    if(contador>1)
    {
        printf("Erro, o aluno ja esta registado numa equipa diferente com a mesma atividade.");
        //retorna o codigo de erro "1", a funcao mais tarde lida com este codigo de erro apropriadamente.
        return 1;
    }
    //Aqui é importante o contador dar reset a 0 para que nas outras verificações nao haja mais problemas
    contador=0;
    //A segunda verificação: No mesmo z(aluno) a soma de todos os valores em x(atividades) e y(equipas) nao pode ser superior a 5, isso implicaria que o mesmo aluno estaria registado em mais de 5 atividades diferentes
    for(x=0; x<*contadorAtividades; x++)
    {
        for(y=0; y<*contadorEquipas; y++)
        {
            if(matriz[x][y][*numAluno]) contador++;
        }
    }
    if(contador>5)
    {
        printf("Erro, o aluno ja esta registado em 5 atividades diferentes, nao pode ser registado em mais nenhuma atividade");
        //Este vai ser o codigo de erro 2;
        return 2;
    }
    contador=0;
    //A terceira verificação: No mesmo y todos os valores em x e z não são superiores a 8, assim, ou seja, na mesma equipa, a soma de todos os alunos e atividades nao é superior a 8
    //Com a pequena alteração de que se encontra um valor em um aluno, nao precisa de contar se os outros alunos(em z's diferentes) tb o teem, logo salta para a proxima atividade(o proximo x)
    for(x=0; x<*contadorAtividades; x++)
    {
        for(z=0; z<*contadorAlunos; z++)
        {
            if(matriz[x][*numEquipa][z])
            {
                contador++;
                //Definimos o z como o sendo igual ao contador de alunos para saltar para o proximo x, e depois damos reset para 0 de novo.
                z=*contadorAlunos;
            }
        }
    }
    if(contador>8)
    {
        printf("Erro, a equipa ja tem mais de 8 atividades diferentes, nao pode ser registada mais nenhuma atividade");
        return 3;
    }
    contador=0;
    //A 4 verificação é semelhante á terceira mas com os loops ao contrário
    for(z=0; z<*contadorAlunos; z++)
    {
        for(x=0; x<*contadorAtividades; x++)
        {
            if(matriz[x][*numEquipa][z])
            {
                contador++;
                x=*contadorAtividades;
            }
        }
    }
    if(contador>8)
    {
        printf("Erro, a equipa ja tem mais de 8 alunos diferentes, nao pode ser registada mais nenhuma atividade");
        return 4;
    }
    contador=0;
    //Debug: printf("Isto nao crashou!!");
    //Se não houver erros esta função retorna 0.
    return 0;
}

//Esta função vai servir para ver as equipas e atividades do aluno individualmente
void visualizadorMatriz(int matriz[][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1], int *contadorAlunos, int *contadorEquipas, int *contadorAtividades)
{
    int numAluno=0, x, y;
    char letra;
    //Verifica se ha alunos para mostrar, se houver 0 alunos registados nao vale a pena tentar mostrar
    if(*contadorAlunos==0)
    {
        printf("Nao ha alunos registados. Operacao cancelada");
        voltarAoMenu();
    }
    else
    {
        //Debug: *contadorEquipas=1;
        if(*contadorEquipas==0)
        {
            printf("Nao ha equipas registadas. Operacao cancelada");
            voltarAoMenu();
        }
        else
        {
            if(*contadorAtividades==0)
            {
                printf("Nao ha atividades registadas. Operacao cancelada.");
                voltarAoMenu();
            }
            else
            {
                printf("Pretende visualizar a atividade de que aluno?Escolha um entre o aluno 1 e o aluno %d\n", *contadorAlunos);
                do{
                printf(">:");
                scanf("%d", &numAluno);
                //Aqui subtrai-se 1 porque o indice das matrizes começa no 0, o utilizador escolhe o aluno 1 mas o programa tem que ler o indice 0 para obter o aluno 1
                numAluno--;
                //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
                fflush(stdin);
                }while(numAluno<0 || numAluno>=*contadorAlunos);

                //O codigo atras foi para perguntar que aluno queremos visualizar e fazer as verificaçoes necessarias.
                for(y=0;y<*contadorEquipas;y++)
                {
                    for(x=0;x<*contadorAtividades;x++) printf("   |");
                    printf("\n");
                    for(x=0;x<*contadorAtividades;x++)
                    {
                        if(matriz[x][y][numAluno]==1)
                        {
                            letra='X';
                        }
                        else
                        {
                            letra='O';
                        }
                        printf(" %c |", letra);
                    }
                    printf("\n");
                    for(x=0;x<*contadorAtividades;x++) printf("   |");
                    printf("\n");
                    for(x=0;x<*contadorAtividades;x++) printf("---+");
                    printf("\n");
                }
                printf("\nAs colunas representam a mesma atividade e as linhas representam a mesma equipa.X siginifica que participa, O nao esta inscrito.");
                voltarAoMenu();
            }
        }
    }
}

void main()
{
    short int menu;
    int contadorAlunos=0, contadorAtividades=0, contadorEquipas=0;
    //Aqui criamos uma matriz de 1's e 0's que vai guardar a informação de que equipa e que atividade é que um dado aluno está registado
    //O tamanho de X é o numero de atividades que há. No caso do enunciado são 6 equipas vezes 8 atividades diferentes por equipa logo 48 atividades diferentes
    //O tamanho de Y é o maximo de equipas que há. No caso do enunciado são 6 equipas
    //O tamanho de Z é o maximo de alunos que há. No caso do enunciado, 6 equipas vezes o maximo de 8 alunos por equipa, logo 48 alunos diferentes
    int matrizAtividadesEquipaAluno[MAX_EQUIPAS*MAX_ATIVIDADESEQUIPA-1][MAX_EQUIPAS-1][MAX_EQUIPAS*MAX_ALUNOSEQUIPA-1];
    //Declaração do vetor das 6 equipas e 48 alunos(numero max de equipas*numero maximo de alunos por equipa)
    equipa vetEquipas[MAX_EQUIPAS-1];
    aluno vetAlunos[(MAX_ALUNOSEQUIPA*MAX_EQUIPAS)-1];
    do{
        //Este fflush serve para limpar no caso de enquanto havia a mensagem "Enter para voltar ao menu" ter sido introduzido algo para alem do enter.
        fflush(stdin);
        //Este printf está dividido em 2: o primeiro printf são as funções requesitadas no enunciado e o segundo são funcões ou comandos extra para o caso de alguma necessidade nao especificada no enunciado.
        printf("------Gestao Equipas------\nEscolha a opcao introduzindo o valor indicado\n1- Escrever um novo aluno\n2- Mostrar um aluno\n3- Apagar um aluno\n4- Escrever uma nova atividade\n5- Mostrar uma atividade\n6- Apagar uma atividade\n7- Mostrar os alunos de uma determinada equipa\n8- Total de respostas certas de uma equipa\n9- Media de respostas certas de uma equipa\n10- Media de idades de uma equipa\n11- Mostrar a equipa com menos tempo gasto numa determinada atividade\n12- Listar as equipas alfabeticamente\n");
        printf("13- Criar uma nova equipa[Podem ser criadas mais %d equipas]\n14- Debug\n15- Mostrar todos os alunos\n16- Visualizar as atividades e equipas de um aluno\n17- Sair do programa\n--------------------------\n", MAX_EQUIPAS-contadorEquipas);
        do{
            printf(">:");
            scanf("%d", &menu);
            //O fflush está aqui para o caso de ser introduzido em acidente(ou nao) um caracter, permitindo assim a introduçao de um integer
            fflush(stdin);
        }while(menu<=0 || menu>=18);
        switch(menu)
        {
            //Nota, os break são necessários senão o programa corre todos os comandos que há, depois de cada comando correr há necessidade de dar reset de menu para = 0 senão se fosse introduzido algum caracter o programa assumiria o valor que tinha previamente e correria essa opção de novo
            case 1: escreverAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 2: mostrarAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 3: apagarAluno(vetAlunos, &contadorAlunos); menu=0; break;
            case 4: escreverAtividade(vetAlunos, matrizAtividadesEquipaAluno, &contadorAlunos, &contadorAtividades, &contadorEquipas); menu=0; break;
            case 5: mostrarAtividade(); menu=0; break;
            case 6: apagarAtividade(); menu=0; break;
            case 7: mostrarAlunosEquipa(); menu=0; break;
            case 8: totalRespostasCerta(); menu=0; break;
            case 9: mediaRespostasCerta(); menu=0; break;
            case 10: mediaIdadesEquipa(); menu=0; break;
            case 11: menosTempo(); menu=0; break;
            case 12: listarAlfabeticamente(); menu=0; break;
            case 13: criarEquipa(vetEquipas, &contadorEquipas); menu=0; break;
            case 14: debug(&contadorAlunos, &contadorEquipas); menu=0; break;
            case 15: mostrarAlunosTodos(vetAlunos, &contadorAlunos); menu=0; break;
            case 16: visualizadorMatriz(matrizAtividadesEquipaAluno, &contadorAlunos, &contadorEquipas, &contadorAtividades); menu=0; break;
            case 17: menu=15; break;
            //O default está aqui se por alguma razão alguma coisa de mal acontecer ao int i o programa voltar ao menu, mas em teoria isto nunca deve correr.
            default: menu=0;
        }
    }while(menu!=15);
}
