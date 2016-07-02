import java.awt.RenderingHints.Key;
import java.awt.event.KeyEvent;
import java.util.Scanner;

public final class Escritor {
  public native void setChar(String text);

  static
  {
      System.loadLibrary("leitor");
  }
    public static void main(String[] args) {
      new Escritor();
    }

    Escritor() {
      Scanner scanner = new Scanner(System.in);      
      while (true) {
        System.out.println("Próxima jogada: ");        
        String text = scanner.next().trim() + "\0"; 
        setChar(text);       
      }      
    }

}
