import java.lang.*;
import java.io.*;

class test {
   public static void main(String arg[]) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String arr[] = br.readLine().split(" ");
      for (String a : arr) {
         System.out.println(a);
      }
   }
}