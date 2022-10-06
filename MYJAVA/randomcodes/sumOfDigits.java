import java.lang.*;
import java.util.Scanner;

class sumOfDigit {
   public static void main(String arg[]) {
      int n;
      System.out.println("Enter a number =");
      Scanner scan = new Scanner(System.in);
      n = scan.nextInt();
      int digSum = 0;
      while (n != 0) {
         digSum += n % 10;
         n = n / 10;
      }
      System.out.println("\nSum of digits= " + digSum);
      scan.close();
   }
}