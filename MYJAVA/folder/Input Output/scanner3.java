import java.util.Scanner;
public class scanner3 {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int sum = 0 , count = 0;
        while(in.hasNextInt())
        {
            sum += in.nextInt();
            count++;
        }
        System.out.println("Mean = " + (sum/count));
        in.close();
    }    
}
