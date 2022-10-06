import java.lang.*;
import java.util.*;
import java.lang.Integer;

class minHrHandAngle {

   public int stringToInt(String s) {
      int res = 0;
      int i = s.length() - 1;
      while (i > -1) {
         res = res * 10 + (s.charAt[i--] - '0');
      }
      return res;
   }

   public static void main(String arg[]) {
      Scanner s = new Scanner(System.in);
      System.out.println("Enter time in hh-mm format=");
      char time = s.nextByte();
      System.out.print(time);
      s.close();
   }
}