package tictactoe;

import java.io.IOException;
import java.net.URL;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

public class GestorSom {
    
    public static void tocarMusica(String filename)
    {
        //Vai buscar o URL para carregar recursos relativamente á posição do jar file
        //Depois de várias horas a testar entre getClass().getResource() e getResourceAsStream descobri que a melhor forma de o fazer é com
        //getClass().getResource(), ambos funcionam como static, a diferença entre os dois é q um envia URLS e o outro Input Streams 
        URL input = GestorSom.class.getClass().getResource(filename);
        
        try
        {
            //Vai buscar um clip
            Clip clip = AudioSystem.getClip();
            //Abre o clip
            AudioInputStream audio = AudioSystem.getAudioInputStream(input);
            clip.open(audio);
            //Toca o clip
            clip.start();
            //Fecha o clip (á partida não deve ser necessário)
            //clip.close();
        }
        catch (IOException | LineUnavailableException | UnsupportedAudioFileException exc)
        {
            exc.printStackTrace(System.out);
        }
    }
}
