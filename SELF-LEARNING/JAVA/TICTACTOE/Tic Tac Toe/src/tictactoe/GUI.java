package tictactoe;

import java.awt.Toolkit;

public class GUI extends javax.swing.JFrame {
    
    public GUI() {
        initComponents();
        setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/tic-tac-toe.png")));
        setResizable(false);
        setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {
        java.awt.GridBagConstraints gridBagConstraints;

        mainPanel = new javax.swing.JPanel();
        label = new javax.swing.JLabel();
        painelButoes = new javax.swing.JPanel();
        topLeft = new javax.swing.JButton();
        topMid = new javax.swing.JButton();
        topRight = new javax.swing.JButton();
        midLeft = new javax.swing.JButton();
        midMid = new javax.swing.JButton();
        midRight = new javax.swing.JButton();
        bottomLeft = new javax.swing.JButton();
        bottomMid = new javax.swing.JButton();
        bottomRight = new javax.swing.JButton();
        canvas1 = new java.awt.Canvas();
        menuBarra = new javax.swing.JMenuBar();
        fileMenu = new javax.swing.JMenu();
        novoJogo = new javax.swing.JMenuItem();
        undo = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Tic Tac Toe");
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        setFont(new java.awt.Font("SansSerif", 0, 18)); // NOI18N
        setForeground(java.awt.Color.darkGray);
        setIconImages(null);
        setMinimumSize(new java.awt.Dimension(500, 500));
        setName("Tic Tac Toe"); // NOI18N

        label.setFont(new java.awt.Font("Dialog", 1, 24)); // NOI18N
        label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        label.setText("Turno do Jogador 1");
        label.setToolTipText("");
        label.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        label.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        label.setHorizontalTextPosition(javax.swing.SwingConstants.LEFT);

        painelButoes.setMaximumSize(new java.awt.Dimension(500, 500));
        painelButoes.setMinimumSize(new java.awt.Dimension(500, 500));
        painelButoes.setPreferredSize(new java.awt.Dimension(500, 500));
        painelButoes.setLayout(new java.awt.GridBagLayout());

        topLeft.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        topLeft.setText(" ");
        topLeft.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 1, new java.awt.Color(0, 0, 0)));
        topLeft.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        topLeft.setDefaultCapable(false);
        topLeft.setFocusPainted(false);
        topLeft.setFocusable(false);
        topLeft.setIconTextGap(0);
        topLeft.setMaximumSize(new java.awt.Dimension(1, 1));
        topLeft.setMinimumSize(new java.awt.Dimension(1, 1));
        topLeft.setRequestFocusEnabled(false);
        topLeft.setVerifyInputWhenFocusTarget(false);
        topLeft.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        topLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                topLeftActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(topLeft, gridBagConstraints);

        topMid.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        topMid.setText(" ");
        topMid.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 1, 1, 1, new java.awt.Color(0, 0, 0)));
        topMid.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        topMid.setDefaultCapable(false);
        topMid.setFocusPainted(false);
        topMid.setFocusable(false);
        topMid.setIconTextGap(0);
        topMid.setMaximumSize(new java.awt.Dimension(1, 1));
        topMid.setMinimumSize(new java.awt.Dimension(1, 1));
        topMid.setPreferredSize(new java.awt.Dimension(1, 1));
        topMid.setRequestFocusEnabled(false);
        topMid.setVerifyInputWhenFocusTarget(false);
        topMid.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        topMid.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                topMidActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(topMid, gridBagConstraints);

        topRight.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        topRight.setText(" ");
        topRight.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 1, 1, 0, new java.awt.Color(0, 0, 0)));
        topRight.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        topRight.setDefaultCapable(false);
        topRight.setFocusPainted(false);
        topRight.setFocusable(false);
        topRight.setIconTextGap(0);
        topRight.setMaximumSize(new java.awt.Dimension(1, 1));
        topRight.setMinimumSize(new java.awt.Dimension(1, 1));
        topRight.setRequestFocusEnabled(false);
        topRight.setVerifyInputWhenFocusTarget(false);
        topRight.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        topRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                topRightActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(topRight, gridBagConstraints);

        midLeft.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        midLeft.setText(" ");
        midLeft.setBorder(javax.swing.BorderFactory.createMatteBorder(1, 0, 1, 1, new java.awt.Color(0, 0, 0)));
        midLeft.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        midLeft.setDefaultCapable(false);
        midLeft.setFocusPainted(false);
        midLeft.setFocusable(false);
        midLeft.setIconTextGap(0);
        midLeft.setMaximumSize(new java.awt.Dimension(1, 1));
        midLeft.setMinimumSize(new java.awt.Dimension(1, 1));
        midLeft.setPreferredSize(new java.awt.Dimension(1, 1));
        midLeft.setRequestFocusEnabled(false);
        midLeft.setVerifyInputWhenFocusTarget(false);
        midLeft.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        midLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                midLeftActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(midLeft, gridBagConstraints);

        midMid.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        midMid.setText(" ");
        midMid.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        midMid.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        midMid.setDefaultCapable(false);
        midMid.setFocusPainted(false);
        midMid.setFocusable(false);
        midMid.setIconTextGap(0);
        midMid.setMaximumSize(new java.awt.Dimension(1, 1));
        midMid.setMinimumSize(new java.awt.Dimension(1, 1));
        midMid.setPreferredSize(new java.awt.Dimension(1, 1));
        midMid.setRequestFocusEnabled(false);
        midMid.setVerifyInputWhenFocusTarget(false);
        midMid.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        midMid.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                midMidActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(midMid, gridBagConstraints);

        midRight.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        midRight.setText(" ");
        midRight.setBorder(javax.swing.BorderFactory.createMatteBorder(1, 1, 1, 0, new java.awt.Color(0, 0, 0)));
        midRight.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        midRight.setDefaultCapable(false);
        midRight.setFocusPainted(false);
        midRight.setFocusable(false);
        midRight.setIconTextGap(0);
        midRight.setMaximumSize(new java.awt.Dimension(1, 1));
        midRight.setMinimumSize(new java.awt.Dimension(1, 1));
        midRight.setPreferredSize(new java.awt.Dimension(1, 1));
        midRight.setRequestFocusEnabled(false);
        midRight.setVerifyInputWhenFocusTarget(false);
        midRight.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        midRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                midRightActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(midRight, gridBagConstraints);

        bottomLeft.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        bottomLeft.setText(" ");
        bottomLeft.setBorder(javax.swing.BorderFactory.createMatteBorder(1, 0, 0, 1, new java.awt.Color(0, 0, 0)));
        bottomLeft.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        bottomLeft.setDefaultCapable(false);
        bottomLeft.setFocusPainted(false);
        bottomLeft.setFocusable(false);
        bottomLeft.setIconTextGap(0);
        bottomLeft.setMaximumSize(new java.awt.Dimension(1, 1));
        bottomLeft.setMinimumSize(new java.awt.Dimension(1, 1));
        bottomLeft.setRequestFocusEnabled(false);
        bottomLeft.setVerifyInputWhenFocusTarget(false);
        bottomLeft.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        bottomLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bottomLeftActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(bottomLeft, gridBagConstraints);

        bottomMid.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        bottomMid.setText(" ");
        bottomMid.setBorder(javax.swing.BorderFactory.createMatteBorder(1, 1, 0, 1, new java.awt.Color(0, 0, 0)));
        bottomMid.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        bottomMid.setDefaultCapable(false);
        bottomMid.setFocusPainted(false);
        bottomMid.setFocusable(false);
        bottomMid.setIconTextGap(0);
        bottomMid.setMaximumSize(new java.awt.Dimension(1, 1));
        bottomMid.setMinimumSize(new java.awt.Dimension(1, 1));
        bottomMid.setPreferredSize(new java.awt.Dimension(1, 1));
        bottomMid.setRequestFocusEnabled(false);
        bottomMid.setVerifyInputWhenFocusTarget(false);
        bottomMid.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        bottomMid.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bottomMidActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(bottomMid, gridBagConstraints);

        bottomRight.setFont(new java.awt.Font("Century Gothic", 1, 48)); // NOI18N
        bottomRight.setText(" ");
        bottomRight.setBorder(javax.swing.BorderFactory.createMatteBorder(1, 1, 0, 0, new java.awt.Color(0, 0, 0)));
        bottomRight.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        bottomRight.setDefaultCapable(false);
        bottomRight.setFocusPainted(false);
        bottomRight.setFocusable(false);
        bottomRight.setIconTextGap(0);
        bottomRight.setMaximumSize(new java.awt.Dimension(1, 1));
        bottomRight.setMinimumSize(new java.awt.Dimension(1, 1));
        bottomRight.setPreferredSize(new java.awt.Dimension(1, 1));
        bottomRight.setRequestFocusEnabled(false);
        bottomRight.setVerifyInputWhenFocusTarget(false);
        bottomRight.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                topLeftMouseEntered(evt);
            }
        });
        bottomRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bottomRightActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 135;
        gridBagConstraints.ipady = 135;
        painelButoes.add(bottomRight, gridBagConstraints);
        painelButoes.add(canvas1, new java.awt.GridBagConstraints());

        javax.swing.GroupLayout mainPanelLayout = new javax.swing.GroupLayout(mainPanel);
        mainPanel.setLayout(mainPanelLayout);
        mainPanelLayout.setHorizontalGroup(
            mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(mainPanelLayout.createSequentialGroup()
                .addGroup(mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(label, javax.swing.GroupLayout.DEFAULT_SIZE, 517, Short.MAX_VALUE)
                    .addGroup(mainPanelLayout.createSequentialGroup()
                        .addGap(6, 6, 6)
                        .addComponent(painelButoes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addContainerGap())
        );
        mainPanelLayout.setVerticalGroup(
            mainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(mainPanelLayout.createSequentialGroup()
                .addComponent(label, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(painelButoes, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        getContentPane().add(mainPanel, java.awt.BorderLayout.CENTER);

        menuBarra.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 1, 0, new java.awt.Color(0, 0, 0)));
        menuBarra.setFont(new java.awt.Font("Dialog", 0, 12)); // NOI18N

        fileMenu.setText("File");
        fileMenu.setFocusable(false);
        fileMenu.setFont(new java.awt.Font("Dialog", 0, 18)); // NOI18N

        novoJogo.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.event.InputEvent.CTRL_MASK));
        novoJogo.setText("New Game");
        novoJogo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                novoJogoActionPerformed(evt);
            }
        });
        fileMenu.add(novoJogo);

        undo.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_Z, java.awt.event.InputEvent.CTRL_MASK));
        undo.setText("Undo");
        undo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                undoActionPerformed(evt);
            }
        });
        fileMenu.add(undo);

        menuBarra.add(fileMenu);

        setJMenuBar(menuBarra);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    int ultimoEscolhido = 10;
    
    private void novoJogoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_novoJogoActionPerformed
        GestorTurno.resetTurnos();
        Verificador.resetMatriz();
        GestorMensagens.turnoLabel();
        //Desnecessário mas é melhor jogar pelo seguro
        ultimoEscolhido = 10;
        
        topLeft.setText(" ");
        topMid.setText(" ");
        topRight.setText(" ");
        midLeft.setText(" ");
        midMid.setText(" ");
        midRight.setText(" "); 
        bottomLeft.setText(" "); 
        bottomMid.setText(" "); 
        bottomRight.setText(" "); 
    }//GEN-LAST:event_novoJogoActionPerformed

    private void undoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_undoActionPerformed
        if(Verificador.undo()) {
            switch (ultimoEscolhido) {
                case 1:  
                    topLeft.setText(" ");
                    break;
                case 2:
                    topMid.setText(" ");
                    break;
                case 3:
                    topRight.setText(" ");
                    break;
                case 4:
                    midLeft.setText(" ");
                    break;
                case 5:
                    midMid.setText(" ");
                    break;
                case 6:
                    midRight.setText(" "); 
                    break;
                case 7:
                    bottomLeft.setText(" "); 
                    break;
                case 8:  
                    bottomMid.setText(" "); 
                    break;
                case 9:  
                    bottomRight.setText(" "); 
                    break;
                default:
                    System.err.println("Erro tentar fazer undo a um quadrado que não existe.");
                    break;
            }
        }
    }//GEN-LAST:event_undoActionPerformed

     private void topRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_topRightActionPerformed
        if(Verificador.verificadorPossibilidade(0, 2)) {
            topRight.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 3;
            Verificador.verificadorGeral(0, 2);
        }
    }//GEN-LAST:event_topRightActionPerformed

    private void bottomRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bottomRightActionPerformed
        if(Verificador.verificadorPossibilidade(2, 2)) {
            bottomRight.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 9;
            Verificador.verificadorGeral(2, 2);
        }
    }//GEN-LAST:event_bottomRightActionPerformed

    private void topLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_topLeftActionPerformed
        if(Verificador.verificadorPossibilidade(0, 0)) {
            topLeft.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 1;
            Verificador.verificadorGeral(0, 0);
        }
    }//GEN-LAST:event_topLeftActionPerformed

    private void midMidActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_midMidActionPerformed
        if(Verificador.verificadorPossibilidade(1, 1)) {
            midMid.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 5;
            Verificador.verificadorGeral(1, 1);
        }
    }//GEN-LAST:event_midMidActionPerformed

    private void topMidActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_topMidActionPerformed
        if(Verificador.verificadorPossibilidade(0, 1)) {
            topMid.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 2;
            Verificador.verificadorGeral(0, 1);
        }
    }//GEN-LAST:event_topMidActionPerformed

    private void midLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_midLeftActionPerformed
        if(Verificador.verificadorPossibilidade(1, 0)) {
            midLeft.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 4;
            Verificador.verificadorGeral(1, 0);
        }
    }//GEN-LAST:event_midLeftActionPerformed

    private void midRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_midRightActionPerformed
        if(Verificador.verificadorPossibilidade(1, 2)) {
            midRight.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 6;
            Verificador.verificadorGeral(1, 2);
        }
    }//GEN-LAST:event_midRightActionPerformed

    private void bottomLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bottomLeftActionPerformed
        if(Verificador.verificadorPossibilidade(2, 0)) {
            bottomLeft.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 7;
            Verificador.verificadorGeral(2, 0);
        }
    }//GEN-LAST:event_bottomLeftActionPerformed

    private void bottomMidActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bottomMidActionPerformed
        if(Verificador.verificadorPossibilidade(2, 1)) {
            bottomMid.setText(GestorTurno.returnJogadorLabel());
            ultimoEscolhido = 8;
            Verificador.verificadorGeral(2, 1);
        }
    }//GEN-LAST:event_bottomMidActionPerformed

    //Detesto esta solução mas foi a melhor que arranjei para resolver o problema da linha não se desenhar.
    //Próximo programa que desenhar tenho que tomar em conta este facto
    private void topLeftMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_topLeftMouseEntered
        if(Verificador.jogoAcabado) {
           GestorLinhas.desenharLinha();
        }
    }//GEN-LAST:event_topLeftMouseEntered

    //Icone Creditos <div>Icons made by <a href="http://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a> is licensed by <a href="http://creativecommons.org/licenses/by/3.0/" title="Creative Commons BY 3.0" target="_blank">CC 3.0 BY</a></div>
    
    /**
     * @param args the command line arguments
     */

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bottomLeft;
    private javax.swing.JButton bottomMid;
    private javax.swing.JButton bottomRight;
    private java.awt.Canvas canvas1;
    private javax.swing.JMenu fileMenu;
    public static javax.swing.JLabel label;
    private javax.swing.JPanel mainPanel;
    private javax.swing.JMenuBar menuBarra;
    private javax.swing.JButton midLeft;
    public static javax.swing.JButton midMid;
    private javax.swing.JButton midRight;
    private javax.swing.JMenuItem novoJogo;
    public static javax.swing.JPanel painelButoes;
    public static javax.swing.JButton topLeft;
    private javax.swing.JButton topMid;
    private javax.swing.JButton topRight;
    private javax.swing.JMenuItem undo;
    // End of variables declaration//GEN-END:variables

}
