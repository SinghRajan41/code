import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
   public static void main(String arg[]) {
      Scanner in = new Scanner(System.in);
      int t = in.nextInt();
      for (int i = 0; i < t; i++) {
         int n = in.nextInt();
         int arr[] = new int[n];
         for (int j = 0; j < n; j++) {
            arr[j] = in.nextInt();
         }
         Arrays.sort(arr);
         System.out.println(arr[n - 1] + arr[n - 2] - arr[0] - arr[1]);
      }
   }
}