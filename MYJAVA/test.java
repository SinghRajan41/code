import java.lang.*;
import java.lang.Integer;
import java.lang.Double;

class test {
   public static void main(String arg[]) {
      StringBuffer sb = new StringBuffer();
      for (int i = 65; i < 91; i++) {
         sb.append((char) i);
      }
      sb.insert(4, "rajan");
      System.out.println(sb);
   }
}