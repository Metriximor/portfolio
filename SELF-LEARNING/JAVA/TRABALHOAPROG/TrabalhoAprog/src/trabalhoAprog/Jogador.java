package trabalhoAprog;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import static trabalhoAprog.Main.escreveErro;

/**
 *
 * @author Pedro Ivo
 */
public class Jogador {
    boolean carregado = false;

    Jogador() {
    }
    
    void carregarJogadores(){
        if(carregado){
            escreveErro("Ficheiro de jogadores já está carregado");
        }
        else{
            try {
                //Tenta ler o ficheiro com encoding ANSI 
                try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("./jogadores.txt"), "Cp1252"));) {
                    //Cria a string para a linha que vai ser lida
                    String linha;
                    //Lê a linha uma a uma até chegar á ultima linha                  
                    while ((linha = br.readLine()) != null) {
                        carregado = true;
                    }
                }
                catch (Exception e){
                    escreveErro("Erro ao ler linha-a-linha o ficheiro: " + e);
                }
            }
            catch (Exception e) {
                escreveErro("Erro ao carregar o ficheiro de eventos");
            }            
        }        
    }
}
