
package trabalhoAprog;

import static trabalhoAprog.Main.escreve;

/**
 *
 * @author Pedro Ivo
 */
public class Menu {
    
    int numEventos = 0;
    
    LeitorConsola leitorConsola = new LeitorConsola();
    Evento evento = new Evento();
    Jogador jogador = new Jogador();
    
    Menu() {
        int opcao = 1;
        //escreve o "Logo"
        escreve("  ________                        .____                       .___\n"
              + " /  _____/_____    _____   ____   |    |   _____    ____    __| _/\n"
              + "/   \\  ___\\__  \\  /     \\_/ __ \\  |    |   \\__  \\  /    \\  / __ | \n"
              + "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  |    |___ / __ \\|   |  \\/ /_/ | \n"
              + " \\______  (____  /__|_|  /\\___  > |_______ (____  /___|  /\\____ | \n"
              + "        \\/     \\/      \\/     \\/          \\/    \\/     \\/      \\/ \n");
            
        //Escreve o menu
        escreve("[0] - Encerrar o programa");
        escreve("[1] - Carregar informação de evento");
        escreve("[2] - Mostrar informação do evento");
        escreve("[3] - Carregar Jogadores");
        
        do{
            //Lê a opção do utilizador
            escreve("Introduza a sua opção >:");
            opcao = leitorConsola.lerInt();

            //Menu de escolhas
            switch(opcao) {
                case 0:
                    escreve("Adeus");
                    break;
                case 1:
                    evento.carregaEvento();
                    break;
                case 2:
                    evento.escreveLista();
                    break;
                case 3: 
                    jogador.carregarJogadores();
                default: 
                    escreve("Valor introduzido ínvalido");
                    break;
            }
        }while(opcao != 0);              
    }      
}
