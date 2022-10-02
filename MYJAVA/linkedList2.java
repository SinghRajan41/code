import java.util.LinkedList;
import java.lang.*;
import java.io.*;

class linkedList2 {
   public static void main(String arg[]) {
      LinkedList arr = new LinkedList();
      for (int i = 0; i < 10; i++) {
         arr.add(i + 1);
      }
      while (!arr.isEmpty()) {
         System.out.println(arr.get(0));
         arr.remove(0);
      }
   }
}