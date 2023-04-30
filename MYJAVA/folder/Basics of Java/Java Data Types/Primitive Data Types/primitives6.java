import java.lang.*;
import java.util.*;
class primitives6
{
    public static void main(String args[])
    {
        System.out.println("Primitives Data Types");
        int x = 10;
        int y = x;
        System.out.println("Initially: ");
        System.out.println("x = " + x + ", y = " + y);
        y = 30;
        System.out.println("After changing y to 30: ");
        System.out.println("x = " + x + ", y = " + y);
        System.out.println("**Only value of y is affected here because of primitive data type\n");
        System.out.println("Reference Data tYpes\n");
        int c[] = {10,20,30,40};
        int d[] = c;
        System.out.println("Initially");
        System.out.println("Array c:" + Arrays.toString(c));
        System.out.println("Array d: " + Arrays.toString(d));
        d[1] = 500;
        System.out.println("After Modification");
        System.out.println("Array c:" + Arrays.toString(c));
        System.out.println("Array d: " + Arrays.toString(d));
    }
}