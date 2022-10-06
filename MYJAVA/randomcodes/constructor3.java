//Java Code for implementing copy constructor
import java.lang.*;
import java.util.Scanner;
class employee
{
	private String name;
	private double salary;
	public employee()
	{
		Scanner in = new Scanner(System.in);
		this.name = in.nextLine();
		this.salary = in.nextDouble();		
	}
	public employee(employee e)
	{
		this.name = e.name;
		this.salary = e.salary;
	}
	void show()
	{
		System.out.println(this.name);
		System.out.println(this.salary);
	}
}
class constructor3
{
	public static void main(String arg[])
	{
		employee e1 = new employee();
		employee e2 = new employee(e1);
		e1.show();
		e2.show();	
	}
}