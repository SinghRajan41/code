import java.io.*;
//custom wrapper class in java
class Maximum{
    private int maxi = 0;
    private int size = 0;
    public void insert(int x)
    {
        this.size++;
        if(x <= this.maxi)  return;
        else                this.maxi = x;
    }
    public int top(){
        return this.maxi;
    }
    public int elementNumber(){
        return this.size;
    }
};
public class wrapper2 {
    public static void main(String arg[])
    {
        Maximum x = new Maximum();
        x.insert(12);
        x.insert(13);
        x.insert(20);
        System.out.println("Maximum Element : " + x.top());
        System.out.println("Number of elements Inserted = " + x.elementNumber());
    }
}
