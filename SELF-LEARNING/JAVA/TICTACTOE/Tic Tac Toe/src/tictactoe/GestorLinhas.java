package tictactoe;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.geom.Line2D;

public class GestorLinhas {
    
    //Vai buscar duas coordenadas que depois podem ser calculadas para outra coisa
    static Point p1 = GUI.topLeft.getLocation(), p2 = GUI.midMid.getLocation();
    
    //Calcula a distancia entre os quadrados
    static int distanceX = p2.x - p1.x, distanceY = p2.y - p2.x;
    
    GUI gui = new GUI();   
    
    static Graphics2D grafico;
    
    GestorLinhas() {
        
    }
    
    static void desenharColuna(int coluna) {
        Point pInicial = new Point((p1.x + (distanceX * (coluna + 1))), p1.y), pFinal = new Point(pInicial.x, p1.y + (distanceY*3));
        grafico.draw(new Line2D.Double(pInicial.x, pInicial.y, pFinal.x, pFinal.y));
        System.out.println(pInicial +""+ pFinal);
    }
}
