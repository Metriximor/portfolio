package calculadora;

import java.awt.Color;
import javax.swing.*;
import java.awt.*;

public class Gui {
    
    private JFrame frame;
    private JPanel panel;
    private JButton testeButton;
    private JLabel label;

    public Gui() {
        System.out.println("Classe GUI carregada com sucesso");
    }
    
    void gui_criar() {
        //Cria o frame, dá-lhe um nome, um tamanho e diz o q fazer em caso de ser fechado
        frame = new JFrame("Teste");
        frame.setVisible(true);
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //Cria um painel
        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        
        //Cria um butao, dá-lhe um nome
        testeButton = new JButton("Olá");
        
        //Cria uma label, dá-lhe algo para escrever
        label = new JLabel("Teste Label");
        label.setBackground(Color.WHITE);
        
        //Adiciona componentes ao painel e o painel ao frame
        panel.add(label);
        panel.add(testeButton);
        frame.add(panel);
        
    }
}
