package trabalhoAprog;

import java.util.Scanner;

/**
 *
 * @author Pedro Ivo
 */
public class LeitorConsola {
    Scanner teclado = new Scanner(System.in);

    public LeitorConsola() {
    }
    
    public int lerInt() {
        int Inteiro;
        try {
            Inteiro = Integer.parseInt(teclado.nextLine());
            return Inteiro;
        }
        catch (NumberFormatException e){
            return -1;
        }
    }
}
