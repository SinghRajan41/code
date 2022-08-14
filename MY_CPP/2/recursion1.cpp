/*#include<iostream>
using namespace std;



int summ(int n)
{
   if (n==1)
   {
      return 1;
   }
   else
   {
      return  n+ summ(n-1);
   }
}
int main()
{
   int n=100;
   cout<<summ(9999);
   return 0;
}*/


#include<iostream>
using namespace std;
int sum(int n)
{
   if(n==1)
   {
      return 1;
   }
   else{
      return n+ sum(n-1);
   }
}
int main()
{
   int n=10;
   cout<<sum(10);
   return 0;
}