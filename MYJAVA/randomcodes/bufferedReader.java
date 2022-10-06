import java.lang.*;
import java.util.*;
import java.io.*;

class input {
   static public BufferedReader br;

   public input() throws IOException {
      br = new BufferedReader(new InputStreamReader(System.in));
   }
}

class bufferedReader {
   static void welcomeUser(input reader) throws IOException {
      String name = reader.br.readLine();

      System.out.println("Welcome Mr. " + name);
   }

   public static void main(String arg[]) throws IOException {
      // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      input reader = new input();
      int n = Integer.parseInt(reader.br.readLine());
      for (int i = 0; i < n; i++) {
         welcomeUser(reader);
      }
   }
}