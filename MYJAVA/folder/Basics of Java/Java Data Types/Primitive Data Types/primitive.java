class primitive
{
    public static void main(String args[])
    {
        char p = 'A';
        short q = 20;
        int a = 21;
        long b = 22;
        float c = 23;
        double d = 24.0;
        for(int i=0;i<2000;i++)
        {
            System.out.print((char)(i+1) + " ");
        }
        System.out.println("Short = " + q);
        System.out.println("Int =" + a);
        System.out.println("Long = " + b);
        System.out.println("Float = " + c);
        System.out.println("Double = " + d);

    }
}