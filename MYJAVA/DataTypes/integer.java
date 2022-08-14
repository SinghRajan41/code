import java.lang.*;
import java.util.Scanner;

public class integer {
   public static void main(String arg[]) {
      Scanner s = new Scanner(System.in);
      System.out.println("Enter a string=");
      String str = s.nextLine();
      encodeString(str);
      s.close();

   }

   static void encodeString(String s) {
      int i;
      for (i = 0; i < s.length(); i++) {
         // s[i] = 'a';
      }
   }
}