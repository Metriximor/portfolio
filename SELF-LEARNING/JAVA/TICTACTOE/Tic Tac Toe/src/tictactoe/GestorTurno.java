package tictactoe;

public class GestorTurno {
    
    public static int turno = 0;
    
    //A função soma um turno
    void proxTurno() {
        turno++;
    }
    
    //Se esta função é chamada quer dizer que um lugar foi escolhido
    public static int returnJogador() {
        //Se o número for par quer dizer que é o jogador 1
        if((turno % 2) == 0) {
            //Salta para o proximo turno e devolve o jogador para o verificador poder usar
            return 1;
        }
        //Senão tem que ser o jogador 2
        else {
            return 2;
        }
    }
    
    public static String returnJogadorLabel() {
        if(returnJogador() == 1) {
            return "X";
        }
        else {
            return "O";
        }
    }
    
    void resetTurnos() {
        turno = 0;
    }
    
}
