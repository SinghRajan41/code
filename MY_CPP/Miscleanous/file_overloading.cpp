#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;
//int x=0;
int f(int n)
{
   int static x=0;
   if(n>0)
   {
      x++;
      return f(n-1)+x;
   }
   
}

int main()
{
 int n=5;
 cout<<f(n);
 
 return 0;
 
}