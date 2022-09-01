#include<iostream>
#include<string>
using namespace std;
int partition(int arr[],int l,int h)
{

   int pivot=arr[h];
   int k=0,j=0,m=0,temp=0;
   int low[h-l+1],equal[h-l+1],high[h-l+1];
   for(int i=l;i<=h;i++)
   {
      if(arr[i]<pivot)
      {
         low[j++]=arr[i];
         continue;
      }
      if(arr[i]>pivot)
      {
         high[k++]=arr[i];
         continue;
      }
      equal[m++]=arr[i];
   }
   int count=l;
   while(temp<j)
   {
      arr[count++]=low[temp++];
   }
   temp=0;
   while(temp<m)
   {
      arr[count++]=equal[temp++];
   }
   int rvalue=count-1;
   temp=0;
   while(temp<k)
   {
      arr[count++]=high[temp++];
   }
   return rvalue;
}
void quicksort(int arr[],int l,int h)
{
   if(l<h)
   {
      int pi=partition(arr,l,h);
      quicksort(arr,l,pi-1);
      quicksort(arr,pi+1,h);
   }
}
int main()
{
   int arr[]={8,7,3,5,6,7,8,4,3,1,2,3,5,6,6,4,2,2,3,4,5,6,6,4,3,2,2,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   quicksort(arr,0,n-1);
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }
   return 0;
}