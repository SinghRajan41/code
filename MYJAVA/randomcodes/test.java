import java.lang.*;
import java.util.*;
import weapons.stack;

class test {
   public static void main(String arg[]) {
      stack s = new stack();
      for (int i = 0; i < 1000; i++) {
         s.push(i);
      }
      for (int i = 0; i < 500; i++) {
         System.out.println(s.top());
         s.pop();
      }
   }
}