import java.io.*;
import java.util.*;

public class myStack {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int arr[] = new int[n];
      for (int i = 0; i < n; i++) {
         arr[i] = Integer.parseInt(br.readLine());
      }
      int dp[] = new int[n + 2];
      dp[0] = dp[1] = 0;
      for (int i = 2; i <= n + 1; i++) {
         int key = arr[i - 2];
         dp[i] = Math.max(dp[i - 1], dp[i - 2] + key);
      }
      System.out.println(dp[n + 1]);
   }
}