/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package submarino;

/**
 *
 * @author mfeijo
 */
public class Submarino {
    
    //public native String getChar();

    static
    {
        System.loadLibrary("leitor");
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Submarino submarino = new Submarino();
        //String result = submarino.getChar();
        //System.out.println(result);
    }
}
