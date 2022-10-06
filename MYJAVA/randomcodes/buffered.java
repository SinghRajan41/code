import java.io.*;
import weapons.stack;

class buffered {
   public static void main(String arg[]) throws IOException {
      weapons.stack s = new weapons.stack();
      for (int i = 0; i < 10; i++) {
         s.push(i);
      }
   }
}