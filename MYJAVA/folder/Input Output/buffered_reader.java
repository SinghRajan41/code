import java.io.*;
public class buffered_reader{
    public static void main(String args[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a string = ");    
        String str = br.readLine();
        System.out.println("Enter an integer = ");
        int n = Integer.parseInt(br.readLine());
        System.out.println(str + "\n" + n);
    }
}

/*
 * 
 * 
 * close()	Closes the stream and releases any system resources associated with it.Once the stream has been closed, further read(), ready(), mark(), reset(), or skip() invocations will throw an IOException. Closing a previously closed stream has no effect.
 * 
mark()	Marks the present position in the stream. Subsequent calls to reset() will attempt to reposition the stream to this point.

markSupported()	Tells whether this stream supports the mark() operation, which it does.

read()	Reads a single character.

read(char[] cbuf, int off, int len)	Reads characters into a portion of an array. This method implements the general contract of the corresponding read method of the Reader class. As an additional convenience, it attempts to read as many characters as possible by repeatedly invoking the read method of the underlying stream.

readLine()	Reads a line of text. A line is considered to be terminated by any one of a line feed (‘\n’), a carriage return (‘\r’), or a carriage return followed immediately by a line feed.

ready()	Tells whether this stream is ready to be read.

reset()	Resets the stream to the most recent mark.

skip(long)	Skips characters.
 */