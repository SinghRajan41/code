#include<iostream>
using namespace std;
int main()
{
   int arr[]={5,3,8,9,2,4,11,44,0,45,23,21,17,19,16,24,25};
   int n=sizeof(arr)/sizeof(arr[0]);
   int k=44;
   short int h[1000]={0};
   for(int i=0;i<n;i++)
   {
      h[arr[i]]++;
      if(h[k-arr[i]]>0 && h[arr[i]]>0)
      {
         if(arr[i]<k+1)
         {
            cout<<arr[i]<<" "<<k-arr[i]<<endl;

         
         h[arr[i]]=-100;
         h[k-arr[i]]=-100;
         }
      }
   }
   
   return 0;
}