import java.io.*;
import java.lang.*;
import java.util.*;
public class Main
{
    public static void main(String arg[])
    {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0)
        {
            int n = in.nextInt();
            int limit;
            if(n%2 == 1)
            {
                limit = ((n/2) + 1);
                System.out.println(((n/2) + 1));
            }
            else
            {
                limit = n/2;
                System.out.println(n/2);
            }
            int low = 1;
            int high = 3*n-1;
            while(limit-- > 0)
            {
                System.out.println(low + " " + high + "\n");
                low += 3;
                high -= 3;
            }
        }
    }
}