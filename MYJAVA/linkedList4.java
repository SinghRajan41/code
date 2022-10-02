import java.lang.*;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class student {
   public String name;
   public String grade;

   public student() {
      name = grade = "";
   }

   public void input() throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String temp[] = br.readLine().split(" ");
      name = temp[0];
      grade = temp[1];
      br.close();
   }

   public void display() {
      System.out.println(name + "\t" + grade);
   }
}

class linkedList4 {
   public static void main(String arg[]) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      // Creating a linkedList of students details
      System.out.println("Enter the number of student = ");
      int n = Integer.parseInt(br.readLine());
      LinkedList arr = new LinkedList<student>();
      for (int i = 0; i < n; i++) {
         student temp = new student();
         temp.input();
         arr.add(temp);
         temp.display();
      }
      /*
       * while (!arr.isEmpty()) {
       * arr.getFirst().display();
       * arr.removeFirst();
       * }
       */

      br.close();
   }
}