import java.lang.*;
import java.util.*;

class linkedList {
   class node {

      public int data;
      public node next;
   };

   class list {
      public node first, last;

      public list() {
         first = last = null;
      }
   }

   public static void main(String arg[]) {
      list arr = new list();
   }
}