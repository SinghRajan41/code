#include<iostream>
using namespace std;
void display(int arr[])
{
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         if(i<=j)
         {
            cout<<arr[i*(i+1)/2 +j]<<" ";
         }
      }
      cout<<endl;
   }
}
void disp(int arr[5][5])
{
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         cout<<arr[i][j]<<" ";
      }
      cout<<endl;
   }
}
int main()
{
   int a[5][5];
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         a[i][j]=i+j;
      }
   }
   int arr[15],count=0;

   disp(a);
   cout<<endl;
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         if(i<=j)
         {
            arr[count++]=a[i][j];
         }
   
      }
      cout<<endl;
   }
   for(int i=0;i<15;i++)
   {
      cout<<arr[i]<<" ";
   }

   return 0;


}
