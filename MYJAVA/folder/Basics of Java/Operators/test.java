import java.util.*;
public class test {
    public static void main(String args[])
    {
        List<Integer> arr = new LinkedList<Integer>();
        for(int i=0;i<10;i++)
        {
            if(arr.add(null) == true)
            {
                System.out.println("Null Value not accepted\n");
            }
        }
    }
}
