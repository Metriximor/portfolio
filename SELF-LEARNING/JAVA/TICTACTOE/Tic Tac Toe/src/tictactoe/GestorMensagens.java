package tictactoe;

import javax.swing.JOptionPane;

public class GestorMensagens {
    
    public GestorMensagens() {
        
    }
    
    //Esta função cria um template para uma janela de informação
    private static void infoBox(String infoMessage)
    {
        JOptionPane.showMessageDialog(null, infoMessage, "", JOptionPane.INFORMATION_MESSAGE);
    }
    
    //Erros
    
    static void jaEscolhido() {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("Este quadrado já foi escolhido");
    }
    
    static void jaGanho() {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("O jogo já acabou");
    }
    
    static void undoImpossivel () {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("Não há nada para fazer undo");
    }
    
    static void undoUsado () {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("Undo já foi usado");
    }
    
    static void empate() {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("O jogo acabou empatado");
    }
    
    static void erro() {
        GestorSom.tocarMusica("/sounds/erro.wav");
        infoBox("Erro não especificado");
    }
    
    //Eventos
    
    static void vitoria(int jogador) {
        GUI.label.setText("O Jogador " + jogador + " venceu!");
        infoBox("Vitória do Jogador " + jogador + "!");
    }
    
    //Labels
    
    static void turnoLabel() {
        GUI.label.setText("Turno do Jogador " + GestorTurno.returnJogador());
    }
}
