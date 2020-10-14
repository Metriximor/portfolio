package primeiropasso;

import java.util.Scanner;

public class Primeiropasso {

    public static void main(String[] args) {
        parImpar();
        fatorial();
    }

    public static void parImpar() {
        int var1;
        int resultado;

        Scanner questao = new Scanner(System.in);

        System.out.println("Introduza o valor que pretende descobrir se é par ou impar");
        var1 = questao.nextInt();
        if ((var1 % 2) == 0) {
            System.out.println("O número é par");
        } 
        else {
            System.err.println("O número é impar");
        }
    }

    public static void fatorial() {
        int var1, cnt, res = 1;
        Scanner questao = new Scanner(System.in);
        System.out.println("Qual o numero que pretende fatorizar?");
        var1 = questao.nextInt();

        if (var1 < 0) {
            System.err.println("Não há numeros fatoriais negativos");
        } 
        else {
            for (cnt = 1; cnt <= var1; cnt++) {
                res = res * cnt;
            }
            System.out.println("O valor fatorial de " + var1 + " é " + res);
        }
    }
}
