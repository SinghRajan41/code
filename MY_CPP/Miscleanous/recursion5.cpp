/*#include<iostream>
using namespace std;

void print_decreasing(int n)
{
   if(n==1)
   {
      cout<<1<<" ";
      return;
   }
   cout<<n<<" ";
   print_decreasing(n-1);
}

void print_increasing(int n,int i)
{  if(i==n)
   {
      cout<<i<<" ";
      return ;
   }
   cout<<i<<" ";
   print_increasing(n,i+1);
}


void f(int n)
{
   if(n==1)
   {
      cout<<1<<" ";
      return;
   }
   f(n-1);
   cout<<n<<" ";
}
int main()
{
   int n=10;
   print_decreasing(n);
   cout<<endl;
   print_increasing(n,1);
   cout<<endl;
   f(n);
   return 0;
}*/

//Write a recursive function to print 1 to n and n to 1

#include<iostream>
using namespace std;
void print(int n)
{
   if(n==1)
   {
      cout<<1<<endl;
      
      return;
   }
   cout<<n<<" ";
   print(n-1);
}
void print2(int i,int n)
{
   if(i==n)
   {
      cout<<i<<" ";
      return ;
   }
   cout<<i<<" ";
   print2(i+1,n);
}
int main()
{
   int n=10;
   print(10);
   print2(1,10);
   return 0;
}