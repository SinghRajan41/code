import java.lang.*;
import java.util.Scanner;
class employee
{
	private String name;
	private double salary;
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
		
	}
}