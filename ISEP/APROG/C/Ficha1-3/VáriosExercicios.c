#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /* Exercicio 1
    float kms, custolitro, cons100, valor;
    // Leitura dos dados de entrada
    printf("Quantos Kilometros vais percorrer?");
    scanf("%f",&kms);
    printf("Indica o preco do litro do combustivel: ");
    scanf("%f",&custolitro);
    printf("Indica o consumo aos 100: ");
    scanf("%f",&cons100);
    // Determina o custo do combustível
    valor = cons100*kms/100*custolitro;
    printf("O custo do combustivel = %.2f", valor);
    */

    /* Exercicio 2
    float raio, area, volume;
    printf("Qual o raio do circulo?\n");
    scanf("%f", &raio);
    float pi = 3.14159265358979323846;
    area = 4*pi*pow(raio, 2);
    volume = (4*pi*pow(raio, 3))/3;
    printf("A área é %.2f e o volume e %.2f", area, volume);
    */

    /* Exercicio 1 Pl2
    int idade;
    printf("Digite qual a sua idade:\n");
    scanf("%d", &idade);
    if(idade < 21)
    {
        printf("A sua idade e inferior a 21 anos! \n \n");
    }
    else if (idade > 21)
    {
        printf("A sua idade e superior a 21 anos! \n \n");
    }
    else
    {
        printf("A sua idade e igual a 21 anos! \n \n");
    }
    system("pause");
    */

    /* Exercicio 2 a)
    int NUM, D1, D2, D3, D4;
    printf("Digite um numero inteiro positivo com quatro digitos:\n");
    scanf("%d", &NUM);
    if(NUM < 1000 || NUM > 9999)
    {
        printf("Valor Invalido!\n");
    }
    else
    {
        D4 = NUM % 10;
        D3 = (NUM/10) % 10;
        D2 = (NUM/100) % 10;
        D1 = (NUM/1000) % 10;
        printf("%d-%d-%d-%d", D1, D2, D3, D4);
    }
    */

    /* Exercicio 2 media aluno
    float media, nota1, nota2, nota3;
    char cod[256];
    printf("Notas? Numero aluno?\n");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    scanf("%s", &cod);
    if(nota1>nota3 && nota1>nota2)
    {
        media = (nota1*0.4+nota2*0.3+nota3*0.3);
    }
    else if(nota2>nota3 && nota2>nota1)
    {
        media = (nota1*0.3+nota2*0.4+nota3*0.3);
    }
    else if(nota3>nota2 && nota3>nota1)
    {
        media = (nota3*0.4+nota2*0.3+nota3*0.3);
    }
    if(media >= 10)
    {
        printf("APROVADO, com media de %f, o aluno %s\n", media, cod);
    }
    else if(media < 10)
    {
        printf("REPROVADO, com media de %.2f, o aluno %s\n", media, cod);
    }
    */

    /* Exercicio 2 calculadora
    float oper, num1, num2, total;
    printf("Qual a operacao? 1-Soma 2-Subtracao 3-Multiplicacao 4-Divisao\n");
    scanf("%f", &oper);
    printf("Qual os dois numeros?\n");
    scanf("%f %f", &num1, &num2);
    if(oper = 1)
    {
        //printf("Teste");
        total = num1+num2;
    }
    else if(oper = 2)
    {
        total = num1 - num2;
    }
    else if(oper = 3)
    {
        total = num1*num2;
    }
    else if(oper = 4)
    {
        if(num2 = 0)
        {
            printf("Operador invalido");
        }
        else
        {
            total = num1/num2;
        }
    }
    else
    {
        printf("Valor Operador Invalido");
    }
    printf("Total: %.2f", total);
    */

    /* Exercicio 2 custo hotel
    float dias, custo;
    char nome[256];
    printf("Quantos dias de estadia? Nome do Cliente?\n");
    scanf("%f", &dias);
    scanf("%s", &nome);
    if(dias < 15)
    {
        custo = (dias*5.5)+(60*dias);
    }
    else if(dias == 15)
    {
        custo = (dias*6)+6+(60*dias);
    }
    else if(dias > 15)
    {
        custo = (dias*8)+(60*dias);
    }
    else if(dias < 0)
    {
        printf("Operacao Invalida");
    }
    printf("O sr(a) %s tem de efetuar o pagamento de %.2f", nome, custo);
    */

    /* Exercicio 2 Media Aluno 5
    float media;
    printf("Qual a media do aluno?");
    scanf("%f", &media);
    if(media >= 5.0)
    {
        if(media >= 7.0)
        {
            printf("Aluno Aprovado");
        }
        else
        {
            printf("O aluno necessita de fazer outra avaliacao");
        }
    }
    else
    {
        printf("Aluno reprovado");
    }
    */

    /* Exercicio 2 Classificaçao infantil
    int idade;
    printf("Qual a idade do nadador?");
    scanf("%d", &idade);
    if(idade >= 5)
    {
        if(idade >= 8)
        {
            if(idade >= 12)
            {
                if(idade >= 14)
                {
                    if(idade >= 18)
                    {
                        printf("Adulto");
                    }
                    else
                    {
                        printf("Juvenil B");
                    }
                }
                else
                {
                    printf("Juvenil A");
                }
            }
            else
            {
                printf("Infantil B");
            }
        }
        else
        {
            printf("Infantil A");
        }
    }
    else
    {
        printf("Não tem classificacao");
    }
    */

    ///* Exercicio 2 Gasolina
    float g[i];
    float d[i];
    float custoLitro;
    //*/
}
