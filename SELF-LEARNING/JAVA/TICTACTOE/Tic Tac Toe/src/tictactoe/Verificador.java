package tictactoe;

//import java.awt.Desktop;
//import java.net.URL;

public class Verificador{
    
    private final static int[][] matriz = new int[3][3];
    
    static int lastLinha, lastColuna;
    
    public static boolean jogoAcabado = false;
    static boolean undo = false;
    
    public Verificador(){
        
    }
    
    //Este foi o método que imaginei para poupar o máximo possivel de memória e de cálulos necessários para verificar se o jogador marcou o jogo ou não
    static int verificarLinhasColunas(int linha, int coluna, int jogador) {
        int pontos = 0, i;
        //Verifica na linha introduzida
        for(i = 0; i < 3; i++) {
            if(matriz[i][coluna] == jogador) {
                pontos++;
            }
        }
        //O jogador preencheu uma coluna
        if(pontos == 3) {
            GestorLinhas.calcularColuna(coluna);
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
        
        //Quer dizer que preencheu a linha
        if(pontos == 3) {
            GestorLinhas.calcularLinha(linha);
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    static int verificarDiagonal(int jogador) {
        //Se o quadrado do meio não estiver preenchido então nem sequer vale a pena verificar os outros
        if(matriz[1][1] == jogador) {
            //Só temos duas diagonais possiveis, ou a diagonal esquerda ou a direita, por isso este algoritmo verifica cada caso individualmente
            //Numa grelha maior usariamos outro estilo de algoritmo
            if((matriz[0][0] == jogador) && (matriz[2][2] == jogador)) {
                GestorLinhas.calcularDiagonal(1);
                return 1;
            }
            else if((matriz[0][2] == jogador) && (matriz[2][0] == jogador)) {
                GestorLinhas.calcularDiagonal(2);
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
    static boolean verificadorPossibilidade(int linha, int coluna) {
        if(matriz[linha][coluna] == 0) {
            if(jogoAcabado) {
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
    
    public static void verificadorGeral(int linha, int coluna) {
        int pontos = 0, jogador = GestorTurno.returnJogador();
        if((linha+coluna) % 2 == 0) {
           pontos = pontos + verificarDiagonal(jogador);
        }
        pontos = pontos + verificarLinhasColunas(linha, coluna, jogador);

        if(pontos >= 1) {
            GestorSom.tocarMusica("/sounds/tada.wav");
            GestorMensagens.vitoria(jogador);
            GestorLinhas.desenharLinha();
            //Declara o jogo como ganho/acabado
            jogoAcabado = true;
            //Código placeholder para abrir um link no caso de vitória
//            try {
//                Desktop.getDesktop().browse(new URL("https://www.youtube.com/watch?v=Dd7FixvoKBw").toURI());
//            } catch (Exception e) {}
        }
        else {
            storeLastMoveCoords(linha, coluna);
            //Se isto der quer dizer q o jogo vai dar empate
            if(GestorTurno.checkforEmpate()) {
                jogoAcabado = true;
                GestorMensagens.empate();
            }
            else {
                GestorTurno.proxTurno();
            }
        }
    }
    
    static void resetMatriz() {
        int x , y;
        for(x = 0; x < 3; x++) {
            for(y = 0; y < 3; y++) {
                matriz[x][y] = 0;
            }
        }
        jogoAcabado = false;
    }
    
    private static void storeLastMoveCoords(int linha, int coluna) {
        lastLinha = linha;
        lastColuna = coluna;
    }
    
    static boolean undo() {
        //Se isto correr entao alguem ja fez undo + q uma vez
        if(undo) {
            GestorMensagens.undoUsado();
            return false;
        }
        else {
            //Tem que ter passado pelo menos um turno
            if(GestorTurno.returnTurno() > 0) {
                //Depois de uma jogoAcabado nao se pode dar undo
                if(jogoAcabado) {
                    GestorMensagens.jaGanho();
                    return false;
                }
                else {
                    matriz[lastLinha][lastColuna] = 0; 
                    GestorTurno.turno--;
                    GestorMensagens.turnoLabel();
                    undo = true;   
                    return true;
                }                
            }
            else{
                GestorMensagens.undoImpossivel();
                return false;
            }
        }
    }
}
