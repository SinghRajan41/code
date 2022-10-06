import java.lang.*;
import java.io.*;
import java.util.LinkedList;

class linkedList {
   public static void main(String arg[]) {
      LinkedList arr = new LinkedList();
      for (int i = 0; i < 10; i++) {
         arr.add(i);
      }
      for (int i = 0; i < 10; i++) {
         System.out.println(arr.get(i));
      }
   }
}