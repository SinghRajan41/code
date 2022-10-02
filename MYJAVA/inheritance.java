// import java.util.Scanner;

// class Person{
// 	 public String name, address, phone_number, email;
// 	 public String toString() {  
// 		 return  name + ", " + address + ", " + phone_number + ", " + email;  
// 	 }
// }

// class Student extends Person{
// 	String Status;
// 	public String toString() {  return  super.toString() +", "+ Status;  }
// }

// class Employee extends Person{
// 	String office;
// 	String salary;
// 	public String toString() {  return  super.toString() +", "+ office+", "+salary;  }
// }

// class Faculty extends Employee{
// 	String hrs, rank;
// 	public String toString() {  return  super.toString() +", "+ hrs+", "+rank;  }
// }

// class Staff extends Employee{
// 	String title;
// 	public String toString() {  return  super.toString() +", "+ title;  }
// }

// class Main{
// 	public static void main(String[] args) {
// 		Scanner inp = new Scanner(System.in);
// 		char ch = inp.nextLine().charAt(0);
// 		if (ch=='P') {
// 			Person p = new Person();
// 			p.name=inp.nextLine();
// 			p.address=inp.nextLine();
// 			p.phone_number=inp.nextLine();
// 			p.email=inp.nextLine();
// 			System.out.println("Person : "+p.toString());  
// 		}
// 		else if (ch=='S') {
// 			Student p = new Student();
// 			p.name=inp.nextLine();
// 			p.address=inp.nextLine();
// 			p.phone_number=inp.nextLine();
// 			p.email=inp.nextLine();
// 			p.Status=inp.nextLine();
// 			System.out.println("Student : "+p.toString()); 
// 		}
// 		else if (ch=='E') {
// 			Employee p = new Employee();
// 			p.name=inp.nextLine();
// 			p.address=inp.nextLine();
// 			p.phone_number=inp.nextLine();
// 			p.email=inp.nextLine();
// 			p.office=inp.nextLine();
// 			p.salary=inp.nextLine();
// 			System.out.println("Employee : "+p.toString()); 
// 		}
// 		else if (ch=='F') {
// 			Faculty p = new Faculty();
// 			p.name=inp.nextLine();
// 			p.address=inp.nextLine();
// 			p.phone_number=inp.nextLine();
// 			p.email=inp.nextLine();
// 			p.office=inp.nextLine();
// 			p.salary=inp.nextLine();
// 			p.hrs=inp.nextLine();
// 			p.rank=inp.nextLine();
// 			System.out.println("Faculty : "+p.toString()); 
// 		}
// 		else if (ch=='T')
// 		{
// 			Staff p = new Staff();
// 			p.name=inp.nextLine();
// 			p.address=inp.nextLine();
// 			p.phone_number=inp.nextLine();
// 			p.email=inp.nextLine();
// 			p.office=inp.nextLine();
// 			p.salary=inp.nextLine();
// 			p.title=inp.nextLine();
// 			System.out.println("Staff : "+p.toString()); 
// 		}
// 	}
// }

import java.util.Scanner;

class Person {
   private String name, address, phone_number, email;

   Person(String n, String adds, String phone, String mail) {
      name = n;
      address = adds;
      phone_number = phone;
      email = mail;
   }

   public String toString() {
      return name + ", " + address + ", " + phone_number + ", " + email;
   }
}

class Student extends Person {
   private String Status;

   Student(String n, String adds, String phone, String mail, String St) {
      super(n, adds, phone, mail);
      Status = St;
   }

   public String toString() {
      return super.toString() + ", " + Status;
   }
}

class Employee extends Person {
   private String office, salary;

   Employee(String n, String adds, String phone, String mail, String off, String Sal) {
      super(n, adds, phone, mail);
      office = off;
      salary = Sal;
   }

   public String toString() {
      return super.toString() + ", " + office + ", " + salary;
   }
}

class Faculty extends Employee {
   private String hrs, rank;

   Faculty(String n, String adds, String phone, String mail, String off, String Sal, String hr, String rnk) {
      super(n, adds, phone, mail, off, Sal);
      hrs = hr;
      rank = rnk;
   }

   public String toString() {
      return super.toString() + ", " + hrs + ", " + rank;
   }
}

class Staff extends Employee {
   private String title;

   Staff(String n, String adds, String phone, String mail, String off, String Sal, String t) {
      super(n, adds, phone, mail, off, Sal);
      title = t;
   }

   public String toString() {
      return super.toString() + ", " + title;
   }
}

class inheritance {
   public static void main(String[] args) {
      String name, address, phone_number, email;
      Scanner inp = new Scanner(System.in);
      char ch = inp.nextLine().charAt(0);
      name = inp.nextLine();
      address = inp.nextLine();
      phone_number = inp.nextLine();
      email = inp.nextLine();
      if (ch == 'P') {
         Person p = new Person(name, address, phone_number, email);
         System.out.println("Person : " + p.toString());
      } else if (ch == 'S') {
         String St = inp.nextLine();
         Student p = new Student(name, address, phone_number, email, St);
         System.out.println("Student : " + p.toString());
      } else if (ch == 'E') {
         String office = inp.nextLine();
         String salary = inp.nextLine();
         Employee p = new Employee(name, address, phone_number, email, office, salary);
         System.out.println("Employee : " + p.toString());
      } else if (ch == 'F') {
         String office = inp.nextLine();
         String salary = inp.nextLine();
         String hrs = inp.nextLine();
         String rank = inp.nextLine();
         Faculty p = new Faculty(name, address, phone_number, email, office, salary, hrs, rank);
         System.out.println("Faculty : " + p.toString());
      } else if (ch == 'T') {
         String office = inp.nextLine();
         String salary = inp.nextLine();
         String title = inp.nextLine();
         Staff p = new Staff(name, address, phone_number, email, office, salary, title);
         System.out.println("Staff : " + p.toString());
      }
   }
}