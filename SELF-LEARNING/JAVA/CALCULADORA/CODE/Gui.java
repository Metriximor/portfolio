package calculadora;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import net.miginfocom.swing.MigLayout;

/*TODO
-Estudar Listeners
-Estudar layouts
*/
public class Gui extends JFrame implements ActionListener, MouseListener, KeyListener {

    //Cria a janela
    private JFrame frame;

    //Cria o painel
    private JPanel mainPanel;
    
    //Label
    private JLabel label;

    //Butoes
    private JButton parImparBt, fatorialBt, somaBt, subtracaoBt, multiplicacaoBt, divisaoBt, solucaoBt, deleteBt;

    //Textfields
    private JTextField txtfield;

    //Doubles
    private Double var1 = null, var2 = null;

    //Strings
    private String resultSt = "";
    
    //Integer
    private int operFlag;

    public Gui() {
        gui_criar();
    }
    
    void gui_criar() {

        //Cria o frame, dá-lhe um nome, um tamanho e diz o q fazer em caso de ser fechado
        frame = new JFrame("Calculadora");
        frame.setSize(500, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Define um icone
        try {
            frame.setIconImage(ImageIO.read(frame.getClass().getResource("/images/calculating.png")));
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        
        //Cria uma label
        label = new JLabel();
        label.setFont(new Font("SansSerif", Font.BOLD, 30));
        label.setForeground(Color.WHITE);
        label.setHorizontalAlignment(SwingConstants.RIGHT);

        //Cria um painel
        mainPanel = new JPanel();
        mainPanel.setBackground(Color.BLACK);
        
        //Cria um butao, dá-lhe um nome
        parImparBt = new JButton("Par/Impar");
        parImparBt.addActionListener(this);

        fatorialBt = new JButton("Fatorial");
        fatorialBt.addActionListener(this);
        
        somaBt = new JButton("+");
        somaBt.addActionListener(this);
        
        subtracaoBt = new JButton("-");
        subtracaoBt.addActionListener(this);
        
        multiplicacaoBt = new JButton("*");
        multiplicacaoBt.addActionListener(this);
        
        divisaoBt = new JButton("÷");
        divisaoBt.addActionListener(this);
        
        solucaoBt = new JButton("=");
        solucaoBt.addActionListener(this);
        
        deleteBt = new JButton("C");
        deleteBt.addActionListener(this);

        //Cria uma label, dá-lhe algo para escrever
        //label = new JLabel("Teste Label");
        //Cria o textfield para introduzir dados
        txtfield = new JTextField();
        //txtfield.setValue(calc.var1);
        //txtfield.setColumns(30);
        txtfield.setFont(new Font("SansSerif", Font.BOLD, 25)); 
        //txtfield.setHorizontalAlignment(SwingConstants.RIGHT);
        txtfield.addMouseListener(this);
        txtfield.addKeyListener(this);
        
        //GridBagConstraints gc = new GridBagConstraints();

        //Adiciona componentes ao painel e o painel ao frame
        //Isto deve estar após os outros componentes serem incializados
        //Tenho que estudar mais os layouts de um programa, tais como Border Grid, Gridbag, etc..
        mainPanel.setLayout(new MigLayout());
        mainPanel.add(txtfield, "wrap, span 6, pushx, growx");
        //Adiciona os botões
        mainPanel.add(parImparBt, "span 3, growx");
        mainPanel.add(fatorialBt, "span 3, growx, wrap");
        mainPanel.add(somaBt, "growx, pushx");
        mainPanel.add(subtracaoBt, "growx, pushx");
        mainPanel.add(multiplicacaoBt, "growx, pushx");
        mainPanel.add(divisaoBt, "growx, pushx");
        mainPanel.add(solucaoBt, "growx, pushx");
        mainPanel.add(deleteBt, "growx, pushx, wrap");
        mainPanel.add(label, "wrap, span 6, grow");
        
        
        frame.add(mainPanel);
        //Isto deve ir em ultimo para que o gui possa ser lido apenas no ultimo lugar
        frame.setVisible(true);
    }

    Double lerNumero() {
        try {
                return Double.parseDouble(txtfield.getText());
            }
            catch (NumberFormatException erro) {
                //System.err.println("Falhou no var1");
                txtfield.setText("Valor Introduzido não é um número");
                return null;
            } 
    }
    
    @Override
    public void actionPerformed(ActionEvent evento) {
        //Para apagar não importa o que estiver
        if(evento.getSource() == deleteBt) {
            var1 = null;
            var2 = null;
            operFlag = -1;
            label.setText("");
            resultSt = "";
            txtfield.setText("");
        }
        //Se nenhum número for conhecido
        else if(var1 == null) {
            //Lê o numero que está na caixa
            var1 = lerNumero();
            //Se este if correr isso quer dizer que o utilizador não introduziu nada
            //Não é um código bonito mas funciona
            if(var1 == null) {
                return;
            }
            
            if(evento.getSource() == somaBt) {
                operFlag = 0;
                label.setText(String.format("%.0f + ", var1));
            }
            else if(evento.getSource() == subtracaoBt) {
                operFlag = 1;
                label.setText(String.format("%.0f - ", var1));
            }
            else if(evento.getSource() == multiplicacaoBt) {
                operFlag = 2;
                label.setText(String.format("%.0f * ", var1));
            }
            else if(evento.getSource() == divisaoBt) {
                operFlag = 3;
                label.setText(String.format("%.0f ÷ ", var1));
            }
            else if(evento.getSource() == fatorialBt) {
                resultSt = Calculadora.fatorial(var1);
                label.setText(String.format("%.0f! = %s", var1, resultSt));
                var1 = Double.parseDouble(resultSt);
                txtfield.setText(resultSt);
                var1 = null;
                operFlag = 4;
            }
            else if(evento.getSource() == parImparBt) {
                resultSt = Calculadora.parImpar(var1);
                label.setText(String.format("%.0f %s", var1, resultSt));
                var1 = null;
                operFlag = 5;
            }
        }
        //Se um número for conhecido
        else if(var2 == null) {
            //Lê o segundo número
            var2 = lerNumero();
            if(var2 == null) {
                return;
            }
            
            //Aqui já temos duas variáveis por isso já podemos correr as funções que requeriam mais info
            if(evento.getSource() == solucaoBt) {
                switch (operFlag) {
                    case 0:
                        resultSt = Calculadora.somar(var1, var2);
                        label.setText(String.format("%.0f + %.0f = %s", var1, var2, resultSt));
                        break;
                    case 1:
                        resultSt = Calculadora.subtrair(var1, var2);
                        label.setText(String.format("%.0f - %.0f = %s", var1, var2, resultSt));
                        break;
                    case 2:
                        resultSt = Calculadora.multiplicar(var1, var2);
                        label.setText(String.format("%.0f * %.0f = %s", var1, var2, resultSt));
                        break;
                    case 3:
                        resultSt = Calculadora.dividir(var1, var2);
                        label.setText(String.format("%.0f ÷ %.0f = %s", var1, var2, resultSt));
                        break;
                    //Neste caso, só se pode aceitar um valor por isso vamos aceitar o último a ser introduzido
                    case 4:
                        resultSt = Calculadora.fatorial(var2);
                        label.setText(String.format("%.0f! = %s", var2, resultSt));
                        break;
                    case 5:
                        resultSt = Calculadora.parImpar(var2);
                        label.setText(String.format("%.0f %s", var2, resultSt));
                        break;
                }
            }
            //Aqui já temos ambas as operações realizadas por isso podemos escrever os resultados
            txtfield.setText(resultSt);
            var1 = null;
            var2 = null;
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        if (!"".equals(txtfield.getText())) {
            txtfield.setText("");
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        if (!"".equals(txtfield.getText())) {
            txtfield.setText("");
        }
    }
    
    @Override
    public void keyTyped(KeyEvent e) {
         char texto = e.getKeyChar();
         if(!(Character.isDigit(texto)) || (texto == KeyEvent.VK_BACK_SPACE) || (texto == KeyEvent.VK_DELETE)) {
             e.consume();
         }
    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        
    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }
}
