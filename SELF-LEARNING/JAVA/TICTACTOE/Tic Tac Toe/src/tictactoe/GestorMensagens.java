package tictactoe;

import javax.swing.JOptionPane;

public class GestorMensagens {
    
    GestorSom som = new GestorSom();
    
    public GestorMensagens() {
        
    }
    
    private static void infoBox(String infoMessage)
    {
        JOptionPane.showMessageDialog(null, infoMessage, "", JOptionPane.INFORMATION_MESSAGE);
    }
    
    //Erros
    
    void jaEscolhido() {
        som.tocarMusica("/sounds/erro.wav");
        infoBox("Este quadrado já foi escolhido");
    }
    
    void jaGanho() {
        som.tocarMusica("/sounds/erro.wav");
        infoBox("O jogo já acabou");
    }
    
    void undoImpossivel () {
        som.tocarMusica("/sounds/erro.wav");
        infoBox("Não há nada para fazer undo");
    }
    
    void undoUsado () {
        som.tocarMusica("/sounds/erro.wav");
        infoBox("Undo já foi usado");
    }
    
    void empate() {
        som.tocarMusica("/sounds/erro.wav");
        infoBox("O jogo acabou empatado");
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
