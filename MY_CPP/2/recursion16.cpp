#include<iostream>
#include<string>
using namespace std;
int pairing(int n)
{
   if(n==0 || n==1 || n==2)
   {
      return n;
   }
   else
   {
      return pairing(n-1)+(n-1)*pairing(n-2);
   }
}
int main()
{
   int n=3;
   cout<<pairing(n);
   return 0;
}