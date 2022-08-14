#include<iostream>
using namespace std;
int main()
{
   int arr[]={1,3,4,5,6,8,9,10,12,14};
   int n=sizeof(arr)/sizeof(arr[0]);
   int l=0,h=n-1;
   int k=10;
   while(l<h)
   {
     if(arr[l] + arr[h]==k)
     {
        cout<<arr[l]<<" "<<arr[h]<<endl;l++;h--;
     }
     else if(arr[l] + arr[h] > k)
     {
        h--;
     }
     else
     {
        l++;
     }
   }
}