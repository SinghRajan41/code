import java.lang.*;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class linkedList3 {
   public static void main(String arg[]) throws Exception {
      // Print a linked list in reverse order
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      LinkedList arr = new LinkedList();
      int n = Integer.parseInt(br.readLine());

      for (int i = 0; i < n; i++) {
         int x;
         x = Integer.parseInt(br.readLine());
         arr.add(x);
      }
      for (int i = n - 1; i >= 0; i--) {
         System.out.println(arr.get(i));
      }
      br.close();
   }
}