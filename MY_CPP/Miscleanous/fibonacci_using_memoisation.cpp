#include<iostream>
using namespace std;
int fib(int n);
int arr[1000];


int fib(int n)
{
   if(n<=2)
   {
      
      return arr[n];
   }
   else
   {
      if(arr[n-2]==-1)
      {
         arr[n-2]=fib(n-2);
      }
      if(arr[n-1]==-1)
      {
         arr[n-1]=fib(n-1);
      }
      return arr[n-2]+ arr[n-1];
   }
}
int main()
{
   for(int i=0;i<1000;i++)
   {
      arr[i]=-1;
   }
   arr[0]=0;
   arr[1]=0;
   arr[2]=1;
   cout<<fib(5);
   return 0;
}