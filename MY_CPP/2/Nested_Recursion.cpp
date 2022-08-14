#include<iostream>
using namespace std;
int f(int n)
{
   if(n>100)
   {
      return n-10;
   }
   else
   {
      return f(f(n+11)); 
   }
}
/*int sum(int n)
{
   if(n==1)
   {
      return 1;
   }
   else
   {
      return sum(n-1)+n;
   }
}*/
int main()
{
   int n=96;
   for(int i=1;i<=100;i++)
   cout<<f(i)<<" ";

   //cout<<sum(10);
   return 0;
}