import java.util.*;
import java.lang.*;

class test {
   boolean compare(String a, String b) {
      int count = 0;
      for (int i = 0; i < a.length(); i++) {
         if (a.charAt(i) != b.charAt(i)) {
            count++;
         }
      }
      return count == 1 ? true : false;
   }

   public static void main(String arg[]) {
      boolean s[] = new boolean[10001];
      for (int i = 0; i < 10001; i++) {
         s[i] = true;
      }
      for (int i = 2; i < 10001; i++) {
         if (s[i] == true) {
            for (int j = i * i; j < 10001; j += i) {
               s[j] = false;
            }
         }
      }

   }
}