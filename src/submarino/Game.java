package submarino;

import java.io.IOException;

public class Game extends javax.swing.JFrame {             
    static
    {
        try {
//            Runtime.getRuntime().exec("gnome-terminal -e '/home/mfeijo/Documents/UCS/Sistemas_operacionais/trabalho_final/Submarino/src/submarino/build.sh'");
            Runtime.getRuntime().exec("gnome-terminal -e '/home/mfeijo/Documents/UCS/Sistemas_operacionais/trabalho_final/Submarino/src/submarino/otherApp.sh'");
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
        System.loadLibrary("leitor");
    }
    
     public static void main(String args[]) {
       new GameView();
   }
    
}
