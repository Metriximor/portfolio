/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

import javax.swing.JOptionPane;

/**
 *
 * @author Pedro Ivo
 */
public class GestorMensagens {
    
    public GestorMensagens() {
        
    }
    
    private static void infoBox(String infoMessage)
    {
        JOptionPane.showMessageDialog(null, infoMessage, "", JOptionPane.INFORMATION_MESSAGE);
    }
    
    static void jaEscolhido() {
        infoBox("Este quadrado já foi escolhido");
    }
    
    static void vitoria() {
        infoBox("Vitória!");
    }
}
