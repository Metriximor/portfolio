package calculadora;

import java.util.Scanner;
import javax.swing.*;
import java.awt.*;

public class Calculadora {

    public static void main(String[] args) {        
        int var1;
        
        //Chama o GUI
        Gui janela = new Gui();
        
        janela.gui_criar();
        
//        Scanner questao = new Scanner(System.in);
//        System.out.println("Introduza o número: ");
//        
//        var1 = questao.nextInt();
//        
//        parImpar(var1);
//        fatorial(var1);
    }

    private static void parImpar(int var1) {
        //int var1;
        int resultado;
        JTextField textfield = new JTextField(20);
        //Scanner questao = new Scanner(System.in);

        //System.out.println("Introduza o valor que pretende descobrir se é par ou impar");
        //var1 = questao.nextInt();
        if ((var1 % 2) == 0) {
            System.out.println("O número é par");
        } 
        else {
            System.err.println("O número é impar");
        }
    }

    private static void fatorial(int var1) {
        int cnt, res = 1;
        //Scanner questao = new Scanner(System.in);
        //System.out.println("Qual o numero que pretende fatorizar?");
        //var1 = questao.nextInt();

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
    
    private static void somar(int var1, int var2) {
        var2 = var1 + var2;
        System.out.println("O valor da soma é " + var2);
    }
    
    private static void subtrair(int var1, int var2) {
        var2 = var1 - var2;
        System.out.println("O valor da subtração é " + var2);
    }
}
