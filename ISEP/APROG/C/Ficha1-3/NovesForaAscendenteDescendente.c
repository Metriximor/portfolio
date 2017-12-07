 int valorN, somaDigitos, contador;
    printf("Qual o numero: ");
    scanf("%d", &valorN);
    somaDigitos = 0;
    contador = 0;
    if(valorN >= 10)
    {
        //Calcula a soma dos digitos na primeira vez
        while(valorN > 0)
        {
            somaDigitos = somaDigitos + valorN%10;
            valorN=valorN/10;
            //printf("%d %d\n", valorN, somaDigitos);
        }
        //Vefifica que a soma dos digitos é menor que 9, se for ele soma a soma de digitos
        while(somaDigitos > 9)
        {
            //Soma a soma dos digitos
            //printf("%d ab ", somaDigitos);
            while(somaDigitos > 0)
            {
                contador = contador + somaDigitos%10;
                somaDigitos=somaDigitos/10;
                //printf("%d\n", contador);
            }
            //Iguala a nova soma ao contador
            somaDigitos = contador;
            contador= 0;
            //printf("%d lel", somaDigitos);
        }
    }
    else
    {
        somaDigitos = valorN;
    }

    printf("Noves fora da %d", somaDigitos);
    //*/

    /*Autoavaliação Algoritmia
    int valorN, digito1, digito2, isAscendente;
    printf("Introduza o numero: ");
    scanf("%d", &valorN);
    isAscendente=1;
    while(valorN>0)
    {
        digito1 = valorN%10;
        digito2 = (valorN/10)%10;
        //Isto é para debug : printf("%d %d \n", digito1, digito2);
        if(digito1 < digito2)
        {
            isAscendente = 0;
            printf("O numero nao e ascendente\n");
            valorN = 0;
        }
        valorN=valorN/10;
    }
    if(isAscendente !=0)
    {
        printf("O numero e ascendente\n ");
    }

    //*/
}
