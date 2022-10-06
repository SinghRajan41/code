import java.lang.*;
import java.util.Scanner;

class dataType {
   int i;
   float f;
   double d;
   char c;
   byte b;

   // If we don't define a constructor, Java automatically defines a constructor
   // with default values depnding on datatype
   public void show() {
      System.out.println(i);
      System.out.println("float " + f);
      System.out.println("double " + d);
      System.out.println("char " + c);
      System.out.println("byte " + b);
   }
}

public class Constructor {
   public static void main(String arg[]) {
      dataType ob = new dataType();
      ob.show();
   }
}
