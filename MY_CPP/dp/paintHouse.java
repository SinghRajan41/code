
/*
1. You are given a number n, representing the number of houses.
2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
 */
import java.io.*;
import java.util.*;

public class paintHouse {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int R[] = new int[n];
      int B[] = new int[n];
      int G[] = new int[n];
      int dpR[] = new int[n];
      int dpB[] = new int[n];
      int dpG[] = new int[n];
      for (int i = 0; i < n; i++) {
         String temp[] = br.readLine().split(" ");
         R[i] = Integer.parseInt(temp[0]);
         B[i] = Integer.parseInt(temp[1]);
         G[i] = Integer.parseInt(temp[2]);
      }
      dpR[0] = R[0];
      dpB[0] = B[0];
      dpG[0] = G[0];
      for (int i = 1; i < n; i++) {
         dpR[i] = R[i] + Math.min(dpB[i - 1], dpG[i - 1]);
         dpB[i] = B[i] + Math.min(dpR[i - 1], dpG[i - 1]);
         dpG[i] = G[i] + Math.min(dpB[i - 1], dpR[i - 1]);
      }
      System.out.println(Math.min(Math.min(dpR[n - 1], dpB[n - 1]), dpG[n - 1]));
   }
}