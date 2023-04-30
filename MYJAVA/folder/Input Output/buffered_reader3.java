import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class buffered_reader3 {
    public static void print(String message)
    {
        System.out.print(message);
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        print("Enter a word = ");   
        String word = br.readLine();
        print("Enter a line = ");
        String line = br.readLine();
        print("Enter an integer = ");
        int n = Integer.parseInt(br.readLine());
        print("Enter a double number = ");
        double d = Double.parseDouble(br.readLine());

    }
}
