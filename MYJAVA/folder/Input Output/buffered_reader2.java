import java.io.BufferedReader;
import java.io.InputStreamReader;
public class buffered_reader2 {
    public static void main(String args[])
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name;
        try{
            System.out.print("Enter your name = ");
            name = br.readLine();
            System.out.println("Name = " + name);
        }
        catch (Exception e){
            System.out.println("Error caught");
        }
    }
}
