#include<iostream>
#include<iomanip>
using namespace std;
double e(double x,int i)
{
   static double r,p=1,f=1;
   if(i==0)
   {
      return 1;
   }
   r=e(x,i-1);
   p=p*x;
   f=f*i;
   return r+p/f;
}

int main()
{
   cout<<setprecision(10)<<e(1,100);
   return 0;
}