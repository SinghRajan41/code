#include<iostream>
#include<string>
//Write a recursive function to count to the number of paths from starting point to ending point
using namespace std;

int countpath(int s,int e)
{
   if(s==e)
   {
      return 1;
   }
   if(s>e)
   {
      return 0;
   }
   int count=0;
   for(int i=1;i<=6;i++)
   {
      count+=countpath(s+i,e);
   }
   return count;
}
int main()
{
   int s=0,e=10;
   cout<<countpath(s,e);
   return 0;
}

