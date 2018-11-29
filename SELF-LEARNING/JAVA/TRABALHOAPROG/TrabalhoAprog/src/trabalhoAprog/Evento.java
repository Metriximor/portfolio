package trabalhoAprog;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import static trabalhoAprog.Main.escreve;
import static trabalhoAprog.Main.escreveErro;

/**
 *
 * @author Pedro Ivo
 */
public class Evento {
    int ano, mes, dia;
    boolean carregado = false;
    List<Integer> id = new ArrayList<>();
    List<Integer> maxPonto = new ArrayList<>();
    List<String> tipJogo = new ArrayList<>();
    
    Evento(){
        
    }
    
    //Completa: a função verifica dentro da pasta evento localizada no diretorio do jar por um ficheiro que é lido
    void carregaEvento(){
        if(carregado){
            escreveErro("Ficheiro de evento já está carregado");
        }
        else{
            try {
                File folder = new File("./evento/");

                //Faz uma lista de ficheiros
                String[] ficheirosPresentes = folder.list();
                if(ficheirosPresentes.length!=1){
                    escreveErro("Só um ficheiro de evento pode estar na pasta evento");
                }
                else{
                    //Tenta arranjar a data do evento
                    try {
                        ano = Integer.parseInt(ficheirosPresentes[0].substring(0, 4));
                        mes = Integer.parseInt(ficheirosPresentes[0].substring(4, 6));
                        dia = Integer.parseInt(ficheirosPresentes[0].substring(6, 8));
                    }
                    catch(NumberFormatException e){
                        escreveErro("O ficheiro na pasta de eventos têm que ter o formato AAAAMMDD");
                    }
                    //DEBUG: escreve(ano + " " + mes + " " + dia);
                    //Tenta ler o ficheiro com encoding ANSI 
                    try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("./evento/"+ficheirosPresentes[0]), "Cp1252"));) {
                        //Cria a string para a linha que vai ser lida
                        String linha;
                        //Lê a linha uma a uma até chegar á ultima linha                  
                        while ((linha = br.readLine()) != null) {
                            //Separa a linha em colunas diferentes
                            String[] sepLinha = linha.split("-");
                            try{
                                id.add(Integer.parseInt(sepLinha[0]));
                                maxPonto.add(Integer.parseInt(sepLinha[2]));
                            }
                            catch (NumberFormatException e){
                                escreveErro("Erro ao obter o ID ou N max pontos de evento: " + e);
                            }
                            try {
                                tipJogo.add(sepLinha[1]);
                            } 
                            catch (Exception e) {
                                escreveErro("Erro ao obter o tipo de Jogo do evento: " + e);
                            }
                            //DEBUG: System.out.println(sepLinha[0] + " " + sepLinha[1] + " " + sepLinha[2]);
                            carregado = true;
                        }
                    }
                    catch (Exception e){
                        escreveErro("Erro ao ler linha-a-linha o ficheiro: " + e);
                    }
                }
            }
            catch (Exception e) {
                escreveErro("Erro ao carregar o ficheiro de eventos");
            }            
        }
    }
    
    void escreveLista(){
        if(carregado){            
            for(int i=0; i<id.size(); i++) {
                escreve("ID:"+id.get(i)+" Tipo de Jogo:"+tipJogo.get(i)+ " Número máximo de Pontos:"+maxPonto.get(i));
            }            
        }
        else{
            escreveErro("Não foi carregado nenhum ficheiro de evento");
        }
    }
}
