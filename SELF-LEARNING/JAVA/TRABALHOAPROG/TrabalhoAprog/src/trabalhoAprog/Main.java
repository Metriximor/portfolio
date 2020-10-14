package trabalhoAprog;

public class Main {
    
    //Esta função só serve para simplificar o comando System.out.println porque me irrita escrever aquilo tudo vezes e vezes sem conta
    public static void escreve(String texto){
        System.out.println(texto);
    }
    
    public static void escreveErro(String texto){
        System.err.println(texto);
    }

    public static void main(String[] args) {
        Menu menu = new Menu();
    }    
}
