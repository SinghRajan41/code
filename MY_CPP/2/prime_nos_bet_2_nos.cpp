#include<iostream>
using namespace std;
int main()
{
   int a=20,b=100;
   
   int n=max(a,b);
   int arr[n+1];
   for(int i=0;i<=n;i++)
   {
      arr[i]=0;
   }


   for(int i=2;i<=n;i++)
   {
      if(arr[i]==0)
      {
         for(int j=i*i;j<=n;j+=i)
         {
            arr[j]=1;
         }
      }
   }
   for(int i=2;i<=b;i++)
   {
      if(arr[i]==0)
      {
         cout<<i<<" ";
      }
   }
   cout<<"Done";
   return 0;
}