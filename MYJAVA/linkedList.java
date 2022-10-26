import java.lang.*;
import java.util.*;
import java.io.*;

class graph {
   private LinkedList<LinkedList<Integer>> adj;
   int v, e;

   public graph() throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String temp[] = br.readLine().split(" ");
      v = Integer.parseInt(temp[0]);
      e = Integer.parseInt(temp[1]);
      adj = new LinkedList<>();
      for (int i = 0; i <= v; i++) {
         adj.add(new LinkedList());
      }
      for (int i = 0; i < e; i++) {
         int x, y;
         temp = br.readLine().split(" ");
         x = Integer.parseInt(temp[0]);
         y = Integer.parseInt(temp[1]);
         adj.get(x).add(y);
         adj.get(y).add(x);
      }
      System.out.println("Input Done");
   }

   public void displayAdj() {
      for (int i = 0; i < v; i++) {
         System.out.print(i + " -> ");
         for (int j = 0; j < adj.get(i).size(); j++) {
            System.out.print(adj.get(i).get(j) + "\t");
         }
         System.out.println("");
      }
   }

   public void _dfs(int cur, boolean visited[]) {
      if (!visited[cur]) {
         visited[cur] = true;
         System.out.println(cur);
         for (int i = 0; i < adj.get(cur).size(); i++) {
            _dfs(adj.get(cur).get(i), visited);
         }
      }
   }

   public void dfs() {
      boolean visited[] = new boolean[v + 1];
      for (int i = 0; i <= v; i++) {
         visited[i] = false;
      }
      for (int i = 0; i < v; i++) {
         if (!visited[i]) {
            _dfs(i, visited);
         }
      }
   }

}

class linkedList {
   public static void main(String arg[]) throws IOException {
      graph g = new graph();
      g.displayAdj();
      g.dfs();

      /*
       * LinkedList<String> list = new LinkedList<>();
       * System.out.println("Enter 5 names = ");
       * BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       * for (int i = 0; i < 5; i++) {
       * String temp = br.readLine();
       * list.add(temp);
       * }
       * System.out.println("The floowing names have been enterred");
       * for (int i = 0; i < list.size(); i++) {
       * System.out.println(list.get(i));
       * }
       * System.out.println("Enter the modification=");
       * int i = Integer.parseInt(br.readLine());
       * String newVal = br.readLine();
       * list.set(i, newVal);
       * System.out.println("The new list is as follows = ");
       * for (i = 0; i < list.size(); i++) {
       * System.out.println(list.get(i));
       * }
       */
   }
}