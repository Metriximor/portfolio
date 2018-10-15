package tictactoe;

public class Verificador {
    
    //Implementa o Gestor de Turno
    GestorTurno turno = new GestorTurno();
    
    private final int[][] matriz = new int[3][3];
    
    public Verificador() {
        
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
        //O jogador preencheu uma linha
        if(pontos == 3) {
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
            matriz[linha][coluna] = turno.returnJogador();
            return true;
        }
        else {
            return false;
        }
    }
    
    public void vitoria(int linha, int coluna) {
        int pontos = 0;
        if((linha+coluna) != 0) {
           pontos = pontos + verificarDiagonal(turno.returnJogador());
        }
        pontos = pontos + verificarLinhasColunas(linha, coluna, turno.returnJogador());

        if(pontos >= 1) {
            GestorMensagens.vitoria();
        }
        else {
            turno.proxTurno();
        }
    }
}
