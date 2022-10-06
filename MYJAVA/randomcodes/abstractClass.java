import java.io.*;
import java.util.*;

abstract class animal {
   public abstract void makeSound();

   public void sleep() {
      System.out.println("ZZzzzz");
   }
}

class dog extends animal {
   public void makeSound() {
      System.out.println("Making Noise");
   }
}

class abstractClass {
   public static void main(String arg[]) throws IOException {
      animal d = new animal();
      d.sleep();
      d.makeSound();
   }
}