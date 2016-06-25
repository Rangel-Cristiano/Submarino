/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package submarino;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mfeijo
 */
public class Submarino {
    
    public native String getChar();

    static
    {
        try {
            Runtime.getRuntime().exec("/home/mfeijo/Documents/UCS/Sistemas_operacionais/trabalho_final/Submarino/src/submarino/build.sh; exec /bin/bash -i");
            Runtime.getRuntime().exec("gnome-terminal -e '/home/mfeijo/Documents/UCS/Sistemas_operacionais/trabalho_final/Submarino/src/submarino/otherApp.sh'");
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
        System.loadLibrary("leitor");
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Submarino submarino = new Submarino();
        String result = submarino.getChar();

        System.out.println(result);
    }
}
