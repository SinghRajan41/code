import java.lang.*;
import java.io.*;
import java.util.*;
class invalidName extends Exception
{
    public invalidName(String message)
    {
        super(message);
    }
}
class exceptionHandling
{
    public static void f1()
    {
        int a = 100 / 0;
    }
    public static void f2()
    {
        int arr[] = {1 ,2,3,4,5,6,7,8};
        int a = arr[10];
    }
    public static void f3()
    {
        String s = null;
        try{
            System.out.println(s.length());
        }
        catch(NullPointerException e)
        {
            System.out.println(e.toString());
        }
    }
    public static void f4()
    {
        String s = "abc";
        try{
            int a = Integer.parseInt(s);
        }
        catch(NumberFormatException e)
        {
            System.out.println(e.toString());
        }
    }
    public static void f5()
    {
        Scanner in = new Scanner(System.in);
        try{
            int a = in.nextInt();
        }
        catch(Exception e){
                System.out.println(e.getMessage());
        }
    }
    public static void f6()
    {
        try{
            int a = 100 / 0;
            String s = null;
            if(s.compareTo("Rajan") == 0)
            {
                System.out.println("I am equal");
            }
            int arr[] = {1 , 2 , 3 , 4 , 5};
            int x = arr[5];
            int num = Integer.parseInt("abs");
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        catch(NullPointerException e)
        {
            System.out.println(e.getMessage());
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e.getMessage());
        }
        catch(NumberFormatException e)
        {
            System.out.print(e.getMessage());
        }
        catch(Exception e)
        {
            System.out.println("Exception Found");
        }
    }
    public static void f7()
    {
        Scanner in = new Scanner(System.in);
        String name = in.nextLine();
        try{
            if(name.compareTo("Rajan Singh")!=0)
            {
                throw new invalidName("You are not Rajan Singh\nGet Lost");
            }
        } 
        catch(invalidName e)
        {
            System.out.println(e.getMessage());
        }
    }
    public static void main(String arg[])
    {
        try{
           // f1();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        try{
            //f2();
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e.getMessage());
        }
        f7();
    }
}