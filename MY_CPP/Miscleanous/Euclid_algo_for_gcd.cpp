#include<iostream>
using namespace std;
int main()
{
   int a,b;
   cin>>a>>b;
   while(a!=b and a>1 and b>1)
   {
      if(a>b)
      {
         a=a-b;
      }
      else if(a<b)
      {
         b=b-a;
      }

   }
   cout<<a;
   return 0;
}