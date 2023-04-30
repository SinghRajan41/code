import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class buffered_reader_4 {
    public static void main(String args[]) throws IOException
    {
        FileReader fr = new FileReader("input.txt");
        BufferedReader br = new BufferedReader(fr , 100);
        char c[] = new char[20];
        /*if(br.markSupported())
        {
            System.out.println("mark() is supported");
            br.mark(100);
        }
        br.skip(8);
        if(br.ready())
        {
            System.out.println(br.readLine());
            br.read(c);
            for(int i=0;i<20;i++){
                System.out.print(c[i]);
            }
            System.out.println();
            br.reset();
            for(int i=0;i<8;i++)
            {
                System.out.print((char) br.read());
            }
        }*/
        br.mark(100);
        br.skip(5);
        for(int i=0;i<10;i++){
            System.out.print((char)br.read());
        }
        br.reset();
        System.out.println();
        for(int i=0;i<15;i++)
        {
            System.out.print((char) br.read());
        }
        br.reset();
        System.out.println();
        for(int i=0;i<15;i++)
        {
            System.out.print((char) br.read());
        }
    }    
}
