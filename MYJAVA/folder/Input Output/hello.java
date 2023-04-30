import java.util.Scanner;
public class hello {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        n = (n%8);
        if(n==7)
        {
            System.out.println("Side Lower Birth");
        }
        else if(n==0)
        {
            System.out.println("Side Upper Birth");
        }
        else if(n==1 || n==4)
        {
            System.out.println("Lower Birth");
        }
        else if(n==2 || n==5)
        {
            System.out.println("Middle Birth");
        }
        else if(n==3 || n==6){
            System.out.println("Upper Birth");
        }
    }
}
