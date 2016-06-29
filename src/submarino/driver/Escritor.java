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
        System.out.println("1");
        while (!scanner.hasNext());
        System.out.println("2");
        String text = scanner.nextLine();
        setChar(text);
      }
    }

}
