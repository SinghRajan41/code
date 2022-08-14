/*#include<iostream>
using namespace std;

int power(int a, int n)
{
   if (n==1)
   {
      return a;
   }
   else
   {
      return a*power(a,n-1);
   }
}
int main()
{
   int a=4;
   cout<<power(a,5);
   return 0;
}*/

#include<iostream>
//Write a recursive function to evaluate power
int power(int a,int n)
{
   if(n==1)
   {
      return a;
   }
   else
   {
      return a*power(a,n-1);
   }

   
}
using namespace std;
int main()
{
   cout<<power(5,6);
   return 0;
}