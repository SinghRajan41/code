import java.util.Scanner;

class Account {
   int id;
   private double balance, interestrate;

   public Account() {
      id = 0;
      balance = 0.0;
      interestrate = 0.0;
   }

   public Account(int id, double balance, double interestrate) {
      this.id = id;
      this.balance = balance;
      this.interestrate = interestrate;
   }

   public boolean withdraw(double amount) {
      if (balance > amount) {
         balance -= amount;
         return true;
      } else
         return false;
   }

   public void deposit(double amount) {
      balance += amount;
      System.out.println("Deposit SuccessFul");
   }

   public int getId() {
      return id;
   }

   public void setId(int id) {
      this.id = id;
   }

   public double getBalance() {
      return balance;
   }

   public void setBalance(double balance) {
      this.balance = balance;
   }

   public double getInterestrate() {
      return interestrate;
   }

   public void setInterestrate(double interestrate) {
      this.interestrate = interestrate;
   }

}

class Main {
   public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int id = sc.nextInt();
      double balance = sc.nextDouble();
      double interestrate = sc.nextDouble();
      double amt = sc.nextDouble();
      Account ac = new Account();
      ac.setId(id);
      ac.setBalance(balance);
      ac.setInterestrate(interestrate);
      System.out.println("Enter the amount to withdraw");
      double amount = sc.nextDouble();
      if (ac.withdraw(amount)) {
         System.out.println("\nWithDraw Successfull");
      } else {
         System.out.println("\nInsufficient Balance");
      }
      System.out.println("Enter the amount to deposit=");
      amount = sc.nextDouble();
      ac.deposit(amount);
      System.out.println(ac.getId());
      System.out.println(ac.getBalance());
      System.out.println(ac.getInterestrate());

   }
}