#include<iostream>
#include<string>
using namespace std;
int tiling(int n)
{
   if(n==1)
   {
      return 1;
   }
   if(n==0)
   {
      return 0;
   }
   return tiling(n-1)+tiling(n-2);//This question is similar to tiling problem
}
int main()
{
   int n=4;
   cout<<tiling(n);
   return 0;
}