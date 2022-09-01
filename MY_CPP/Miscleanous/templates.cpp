//Wrtie a generic function to merge sort an array followed by overloaded function


#include<iostream>
using namespace std;

void sort(int arr[],int n)
{
   int m=100000,idx;
   //Selection Sort
   for(int i=0;i<n;i++)
   {
      idx=i;
      m=arr[i];
      
      
      for(int j=i;j<n;j++)
      {
       if(m>arr[j])
       {
          m=arr[j];
          idx=j;
       }
      }
      //Perform Swapping
      int temp=arr[i];
      arr[i]=m;
      arr[idx]=temp;
   }
}
int main()
{
 int a[]={5,4,3,2,1};
 float b[]={5.1,4.1,3.1,2.1,1.1};
 int n=sizeof(a)/sizeof(a[0]);
 sort(a,n);

 for(int i=0;i<n;i++)
 {
    cout<<a[i]<<" ";
 }
 cout<<endl;
 for(int i=0;i<n;i++)
 {
    //cout<<b[i]<<" ";
 }
 return 0;
}