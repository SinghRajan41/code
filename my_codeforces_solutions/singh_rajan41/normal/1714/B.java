import java.lang.*;
import java.util.*;
import java.io.*;

public class Main {
   public static void main(String arg[]) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int t = Integer.parseInt(br.readLine());
      while (t-- > 0) {
         int n = Integer.parseInt(br.readLine());
         int freq[] = new int[n + 1];
         int arr[] = new int[n];
         for (int i = 0; i <= n; i++)
            freq[i] = 0;
         String temp[] = br.readLine().split(" ");
         int dist = 0;
         for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(temp[i]);
            freq[arr[i]]++;
            if (freq[arr[i]] == 1)
               dist++;
         }
         int remaining = n;
         int i = 0;

         while (i < n) {
            if (remaining == dist) {
               break;
            } else {
               freq[arr[i]]--;
               if (freq[arr[i]] == 0)
                  dist--;
               remaining--;
            }
            i++;
         }

         System.out.println(n - remaining);
      }
   }
}