import java.lang.*;
import java.util.Scanner;

class hello {
   public static void main(String arg[]) {
      StringBuffer sb = new StringBuffer();
      Scanner in = new Scanner(System.in);
      sb.append(in.next());
      System.out.print(sb);
      in.close();
   }
}