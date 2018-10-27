package tictactoe;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.geom.Line2D;

public class GestorLinhas{
    
    public GestorLinhas() {
        //setOpaque(false);
    }
    
    private static Point p1 = GUI.topLeft.getLocation(), p2 = GUI.midMid.getLocation();
    private static Point pInicial, pFinal;
    private static int distance = p2.x - p1.x;
    private static boolean calculado = false;
    
    //Calcula os pontos inciais e finais para os 3 métodos de desenhar: coluna, linha ou diagonal
    static void calcularColuna(int coluna) {
        //Calcula os pontos iniciais e finais
        pInicial = new Point((p1.x + (distance / 2)) + (distance * coluna), p1.y + (distance / 2));
        pFinal = new Point(pInicial.x, (p1.y + (distance / 2)) + (distance * 2));
        calculado = true;
    }    
    
    static void calcularLinha(int linha) {
        //Igual ao de calcular a coluna, mas invertido
        pInicial = new Point(p1.x + (distance / 2), (p1.y + (distance/2)) + (linha * distance));
        pFinal = new Point(pInicial.x + (distance * 2), pInicial.y);
        calculado = true;
    }
    
    static void calcularDiagonal(int diagonal) {
        switch (diagonal){
            case 1:
                pInicial = new Point(p1.x + (distance / 2), p1.y + (distance / 2));
                pFinal = new Point((p1.x + (distance / 2)) + (distance * 2), (p1.y + (distance / 2)) + (distance * 2));
                break;
            case 2:
                pInicial = new Point(p1.x + (distance / 2) + (distance * 2), p1.y + (distance / 2));
                pFinal = new Point((p1.x + (distance / 2)), (p1.y + (distance / 2)) + (distance * 2));
                break;
        }
        calculado = true;
    }
    
    static void desenharLinha() {
        if(calculado) {
            Graphics2D g2D = (Graphics2D) GUI.painelButoes.getGraphics();
            g2D.draw(new Line2D.Float(pInicial, pFinal));
        }
        else{
            System.err.println("A tentar desenhar a linha sem ter os pontos calculdos. Algo deu mal");
        }
    }
}
