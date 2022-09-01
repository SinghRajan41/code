/*#include<iostream>
using namespace std;


int fib(int n)
{
   if(n==1)
   {
      return 0;
   }
   if(n==2)
   {
      return 1;
   }
   
   
      return fib(n-1) + fib(n-2);
   
}
int main()
{
   int n=4;
   cout<<fib(n);
   return 0;
}*/


//Write a recursive function to print the Nth term of fibonnaci series
#include<iostream>
using namespace std;
int fib(int n)
{
   if(n==1)
   {
      return 0;
   }
   else if(n==2)
   {
      return 1;
   }
   else
   {
      return fib(n-1)+fib(n-2);
   }
}
int main()
{
   cout<<fib(5);
   return 0;
}