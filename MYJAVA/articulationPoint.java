import java.util.*;

import javax.lang.model.util.ElementScanner14;

import java.io.*;

class articulationPoint {
   static int parent[];
   static int disc[];
   static int low[];
   static int time = 0;
   static boolean vis[];
   static boolean ap[];

   public static void main(String arg[]) {
      Scanner scn = new Scanner(System.in);
      int v = scn.nextInt();
      int e = scn.nextInt();
      ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
      for (int i = 0; i < v; i++) {
         graph.add(new ArrayList<>());
      }
      for (int i = 0; i < e; i++) {
         int u = scn.nextInt();
         int v1 = scn.nextInt();
         graph.get(u).add(v1);
         graph.get(v1).add(u);
      }
      parent = new int[v];
      disc = new int[v];
      low = new int[v];
      time = 0;
      vis = new boolean[v];
      ap = new boolean[v];
      parent[0] = -1;
      dfs(0, graph);
      int ans = 0;
      for (int i = 0; i < v; i++) {
         if (ap[i] == true) {
            ans++;
         }
      }
      System.out.println(ans);
   }

   public static void dfs(int u, ArrayList<ArrayList<Integer>> graph) {
      disc[u] = low[u] = time;
      time++;
      vis[u] = true;
      int count = 0;
      ArrayList<Integer> nbrs = graph.get(u);
      for (int i = 0; i < nbrs.size(); i++) {
         int v = nbrs.get(i);
         if (parent[u] == v) {
            continue;
         } else if (vis[v] == true) {
            low[u] = Math.min(low[u], disc[v]);
         } else {
            parent[v] = u;
            count++;
            dfs(v, graph);
            low[u] = Math.min(low[u], low[v]);
            if (parent[u] == -1) {
               // Actual source
               if (count >= 2) {
                  ap[u] = true;
               }

            } else {
               if (low[v] >= disc[u]) {
                  ap[u] = true;
               }
            }
         }
      }
   }
}