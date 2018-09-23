package primeiropasso;

import java.util.Scanner;

public class Primeiropasso {
    
    public static void main(String[] args) {
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
}
