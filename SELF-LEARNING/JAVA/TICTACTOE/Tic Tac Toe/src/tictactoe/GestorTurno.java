package tictactoe;

public class GestorTurno {
    
    public static int turno = 0;
    
    //A função soma um turno
    static void proxTurno() {
        turno++;
        GestorMensagens.turnoLabel();
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
    
    static int returnTurno() {
        return turno;
    }
    
    static void resetTurnos() {
        turno = 0;
    }
    
    static boolean checkforEmpate() {
        //Nao esquecer q os turnos tem indice 0 por isso um turno 8 aqui é na realidade um turno 9
        if(turno == 8) {
            return true;
        }
        else {
            return false;
        }
    }
    
}
