import java.lang.*;
import java.util.Scanner;

class string2 {
   public static void main(String arg[]) {
      Scanner in = new Scanner(System.in);
      StringBuffer sb = new StringBuffer();
      sb.append(in.next());
      for (int i = 0; i < sb.length(); i++) {
         System.out.println(sb.charAt(i));
      }
      String str = new String(sb);
      str.toLowerCase();
      System.out.print(str);
   }
}