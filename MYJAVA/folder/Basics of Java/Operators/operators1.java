public class operators1
{
    public static void main(String args[])
    {
        //Max of three numbers
        int a = 20;
        int b = 10;
        int c = 30;
        int result;
        result = ((a>b ? a : b) > (b>c ? b : c) ? (a>b ? a : b) : (b>c ? b : c));
        System.out.println("Max = " + result);
    }
}