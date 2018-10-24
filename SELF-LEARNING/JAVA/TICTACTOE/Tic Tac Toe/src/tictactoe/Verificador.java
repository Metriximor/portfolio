package tictactoe;

//import java.awt.Desktop;
//import java.net.URL;

public class Verificador {
    
    //Implementa o Gestor de Turno
    GestorTurno turno = new GestorTurno();
    
    private final int[][] matriz;
    
    int lastLinha, lastColuna;
    
    boolean vitoria = false;
    boolean undo = false;
    
    public Verificador() {
        this.matriz = new int[3][3];
    }
    
    //Este foi o método que imaginei para poupar o máximo possivel de memória e de cálulos necessários para verificar se o jogador marcou o jogo ou não
    int verificarLinhasColunas(int linha, int coluna, int jogador) {
        int pontos = 0, i;
        //Verifica na linha introduzida
        for(i = 0; i < 3; i++) {
            if(matriz[i][coluna] == jogador) {
                pontos++;
            }
        }
        //O jogador preencheu uma coluna
        if(pontos == 3) {
            GestorLinhas.desenharColuna(linha);
            return 1;
        }
        else {
            pontos = 0;
        }
        
        for(i = 0; i < 3; i++) {
            if(matriz[linha][i] == jogador) {
                pontos++;
            }            
        }
        
        //Quer dizer que preencheu a coluna
        if(pontos == 3) {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    int verificarDiagonal(int jogador) {
        //Se o quadrado do meio não estiver preenchido então nem sequer vale a pena verificar os outros
        if(matriz[1][1] == jogador) {
            //Só temos duas diagonais possiveis, ou a diagonal esquerda ou a direita, por isso este algoritmo verifica cada caso individualmente
            //Numa grelha maior usariamos outro estilo de algoritmo
            if((matriz[0][0] == jogador) && (matriz[2][2] == jogador)) {
                return 1;
            }
            else if((matriz[0][2] == jogador) && (matriz[2][0] == jogador)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    
    //Verifica se alguem ja colocou alguma coisa no quadrado e escreve no quadrado
    boolean verificadorPossibilidade(int linha, int coluna) {
        if(matriz[linha][coluna] == 0) {
            if(vitoria) {
                //Neste caso o jogo ja foi ganho
                GestorMensagens.jaGanho();
                return false;
            }
            else {
                matriz[linha][coluna] = GestorTurno.returnJogador();
                undo = false;
                return true;
            }
        }
        else {
            //Neste caso o quadrado já foi escolhido
            GestorMensagens.jaEscolhido();
            return false;
        }
    }
    
    public void vitoria(int linha, int coluna) {
        int pontos = 0, jogador = GestorTurno.returnJogador();
        if((linha+coluna) % 2 == 0) {
           pontos = pontos + verificarDiagonal(jogador);
        }
        pontos = pontos + verificarLinhasColunas(linha, coluna, jogador);

        if(pontos >= 1) {
            GestorSom.tocarMusica("/sounds/tada.wav");
            GestorMensagens.vitoria(jogador);
            vitoria = true;
//            try {
//                Desktop.getDesktop().browse(new URL("https://www.youtube.com/watch?v=Dd7FixvoKBw").toURI());
//            } catch (Exception e) {}
        }
        else {
            storeLastMoveCoords(linha, coluna);
            //Se isto der quer dizer q o jogo vai dar empate
            if(GestorTurno.checkforEmpate()) {
                vitoria = true;
                GestorMensagens.empate();
            }
            else {
                turno.proxTurno();
            }
        }
    }
    
    void resetMatriz() {
        int x , y;
        for(x = 0; x < 3; x++) {
            for(y = 0; y < 3; y++) {
                matriz[x][y] = 0;
            }
        }
        vitoria = false;
    }
    
    private void storeLastMoveCoords(int linha, int coluna) {
        lastLinha = linha;
        lastColuna = coluna;
    }
    
    void undo() {
        //Se isto correr entao alguem ja fez undo + q uma vez
        if(undo) {
            GestorMensagens.undoUsado();
        }
        else {
            if(GestorTurno.returnTurno() > 0) {
                matriz[lastLinha][lastColuna] = 0; 
                GestorTurno.turno--;
                GestorMensagens.turnoLabel();
                undo = true;
            }
            else{
                GestorMensagens.undoImpossivel();
            }
        }
    }
}
