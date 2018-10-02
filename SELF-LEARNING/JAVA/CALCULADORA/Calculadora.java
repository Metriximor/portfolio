package calculadora;

import javax.swing.*;

public class Calculadora {

    //É necessário para poder chamar isto de outras funções
    double var1, var2;
    
    public static String parImpar(Double var1) {
        //int var1;
        int resultado;
        //Scanner questao = new Scanner(System.in);

        //System.out.println("Introduza o valor que pretende descobrir se é par ou impar");
        //var1 = questao.nextInt();
        
        if(var1 == 0) {
            return String.format("não é par nem impar");
        }
        else if ((var1 % 2) == 0) {
            //System.out.println("O número é par");
            return String.format("é par");
        } 
        else {
            //System.err.println("O número é impar");
            return String.format("é impar");
        }
    }

    public static String fatorial(Double var1) {
        int cnt;
        double res = 1;
        //Scanner questao = new Scanner(System.in);
        //System.out.println("Qual o numero que pretende fatorizar?");
        //var1 = questao.nextInt();

        if (var1 < 0) {
            return String.format("Não há numeros fatoriais negativos");
        } 
        else {
            for (cnt = 1; cnt <= var1; cnt++) {
                res = res * cnt;
            }
            return String.format("%.0f",res);
        }
    }
    
    public static String somar(double var1, double var2) {
        var2 = var1 + var2;
        return String.format("%.0f", var2);
    }
    
    public static String subtrair(double var1, double var2) {
        var2 = var1 - var2;
        return String.format("%.0f", var2);
    }
    
    public static String multiplicar(double var1, double var2) {
        var2 = var1 * var2;
        return String.format("%.0f", var2);
    }
    
    public static String dividir(double var1, double var2) {
        if(var2 == 0) {
            return String.format("O divisor não pode ser 0");
        }
        else {
            var2 = var1 / var2;
            return String.format("%.0f", var2);
        }
    }
}
