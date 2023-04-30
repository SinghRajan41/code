import java.text.DecimalFormat;
public class formatted_io{
    static void method1()
    {
        int x = 100;
        System.out.printf("%d\n" , x);
        System.out.printf("%.2f\n" , Math.PI);
        float n = 5.2f;
        System.out.printf("Formatted to specific width = %.4f\n" , n);
        n = 2324435.33f;
        System.out.printf("Formatted to right margin: n = %20.4f\n" , n);
    }
    static void method2(){
        double num = 123.4567;
        DecimalFormat ft = new DecimalFormat("##");
        System.out.println("Without fraction part: num = " + ft.format(num));
        ft = new DecimalFormat("#.###");
        System.out.println("Formatted to give precision: num " + ft.format(num));
        ft = new DecimalFormat("0000.00");
        System.out.println("Formatting Numeric Output: num = " + ft.format(num));
        double income = 2345.6789;
        ft = new DecimalFormat("$###,###.##");
        System.out.println("Your formatted Dream Income : " + ft.format(income));
    }
    public static void main(String args[])
    {
        //method1();
        method2();
    }
}