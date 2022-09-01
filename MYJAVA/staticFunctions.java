import java.lang.*;
import java.util.Scanner;
class temp
{
  public static int greetUser()
	{
		System.out.print("Please Enter ur name= ");
		String name = (new Scanner(System.in)).nextLine();
		System.out.println("Hello " + name);
		return 100;
	}
}
class staticFunctions
{
	

	public static void main(String arg[])
	{
		greetUser();		
	}
}