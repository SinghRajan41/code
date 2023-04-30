import java.util.Scanner;
public class scanner {
    static void print(String message)
    {
        System.out.print(message);
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        print("Enter a word = ");
        String word = sc.next();
        print("Enter a line = ");
        String line = sc.nextLine();
        print("Enter an integer = ");
        int n = sc.nextInt();
        print("Enter a floating number = ");
        float f = sc.nextFloat();
        print("Enter a double number = ");  
        double d = sc.nextDouble();
        print("enter a short number = ");
        short s = sc.nextShort();
        print("Word = " + word + "\n");
        print("Line = " + line + "\n");
        print("Integer = " + n + "\n");
        print("Floating number = " + f + "\n");
        print("Double nujber = " + d + "\n");
        print("Short number = " + s + "\n");
    }
}
