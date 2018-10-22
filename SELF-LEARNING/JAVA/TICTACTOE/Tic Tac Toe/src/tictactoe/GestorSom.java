package tictactoe;

import java.io.*;
import java.io.IOException;
import java.io.InputStream;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

public class GestorSom {
    
//    public static void tocarMusica(String filename)
//    {
//        //Vai buscar a path para carregar recursos relativamente á posição do jar file
//        InputStream input = GestorSom.class.getResourceAsStream(filename);
//        //GestorSom p = new Player(getClass().getResourceAsStream(filename));
//        
//        try
//        {
//            //Vai buscar um clip
//            Clip clip = AudioSystem.getClip();
//            //Abre o clip
//            AudioInputStream audio = AudioSystem.getAudioInputStream(input);
//            clip.open(audio);
//            //Toca o clip
//            clip.start();
//            //Fecha o clip (á partida não deve ser necessário)
//            //clip.close();
//        }
//        catch (IOException | LineUnavailableException | UnsupportedAudioFileException exc)
//        {
//            exc.printStackTrace(System.out);
//        }
//    }
    
    public void tocarMusica(String filename) {
        try {
            AudioInputStream audio = AudioSystem.getAudioInputStream(this.getClass().getResourceAsStream(filename));
            Clip clip = AudioSystem.getClip();
            clip.open(audio);
            clip.start();
        }
        catch (IOException | LineUnavailableException | UnsupportedAudioFileException exc)
        {
            exc.printStackTrace(System.out);
        }
    }
}
