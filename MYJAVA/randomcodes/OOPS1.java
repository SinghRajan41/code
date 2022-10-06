import java.lang.*;

import java.lang.*;
import java.util.Scanner;

class node {
   public int data;
   public node left, right;

   public node() {
      data = 0;
      left = right = null;
   }

   public node(int x) {
      data = x;
      left = right = null;
   }
}

class employee {
   private String name;
   private String department;
   private double salary;

   public void input() {
      Scanner in = new Scanner(System.in);
      name = in.nextLine();
      department = in.nextLine();
      salary = in.nextDouble();
      in.close();
   }

   public void display() {
      System.out.println(name + " " + department + " " + salary);
   }
}

public class OOPS1 {

   public static void main(String arg[]) {
      node t = new node(5);
      System.out.println(t.left + " " + t.right + " " + t.data);
   }
}
