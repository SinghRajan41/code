#include<iostream>
using namespace std;
int main()
{
   
   int t=20;
   int temp=t;
   while(t--)
   {
      for(int i=0;i<15;i++)
      {
         cout.width(i+1);
         cout<<0<<endl;
         



         long long int time_delay=20000000;
         int sum=0;
         while(time_delay--)
         {
           sum++;
         }

      }
      for(int i=15;i>=0;i--)
      {
         cout.width(i);
         cout<<0<<endl;
         cout.width(16-i);
         cout<<0<<endl;
         long long time_delay=20000000;
         int sum=0;
         while(time_delay--)
         {
           sum++;
         }
      }
   }
   
   return 0;
}