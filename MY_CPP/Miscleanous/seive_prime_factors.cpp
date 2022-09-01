#include<iostream>
using namespace std;
int main()
{
   int n=100;
   int arr[101];
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
            arr[j]=i;
         }
      }
   }
   int num;
   cin>>num;

   while(num!=1)
   {
    cout<<arr[num]<<" ";
    num=num/arr[num];
   }
   return 0;
}