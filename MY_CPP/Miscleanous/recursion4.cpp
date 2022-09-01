/*#include<iostream>
using namespace std;


bool sorted(int arr[],int n,int i)
{
   if(n==1)
   {
      return true;
   }
   return ( arr[i]<arr[i+1] && sorted(arr,n-1,i+1));
}

bool sorted2(int arr[],int n)
{  if(n==1)
   {
      return true;
   }
   return (arr[0]<arr[1] && sorted2((arr+1),n-1));
}
int main()
{
   int arr[10]={1,2,3,4,5,7,6,8,9,10};
   int size=sizeof(arr)/sizeof(arr[0]);
   cout<<sorted(arr,size,0)<<endl;
   cout<<sorted2(arr,size);

   return 0;
}*/


//Check if an array is sorted or not using recursion
#include<iostream>
using namespace std;
bool check(int arr[],int i,int n)
{
   if(i==n)
   {
      return true;
   }
   
   return arr[0]<arr[1]  && check((arr+1),i+1,n);
}
int main()
{
   int arr[]={1,2,3,4,6,5,7,8,9};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<check(arr,0,n-1);
   return 0;
}