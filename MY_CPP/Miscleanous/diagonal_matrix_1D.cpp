#include<iostream>
using namespace std;
int main()
{
   int arr[6]={1,2,3,4,5,6};
   for(int i=0;i<6;i++)
   {
      for(int j=0;j<6;j++)
      {
         if(i==j)
         {
            cout<<arr[i]<<" ";
         }
         else
         {
            cout<<0<<" ";
         }
      }
      cout<<endl;
   }
}