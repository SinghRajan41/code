/*#include<iostream>
using namespace std;

int last_occurence(int arr[],int key, int i)
{ 
   if(arr[i]==key)
   {
      return i;
   }
   if(i==-1)
   {
      return -1;//viz not found
   }
   return last_occurence(arr,key,i-1);

}


int first_occurence(int arr[],int key, int i,int n)
{ if(i==n)
  {
     return -1;// viz not found
  }
   if(arr[i]==key)
 {
   return i;
 }
   return first_occurence(arr,key,i+1,n);
}
int main()
{
   //Finding first occurence of an integer in an array using recursion


   int arr[11]={1,2,3,4,5,6,4,5,6,7,8};
   int n=sizeof(arr)/sizeof(arr[0]);
   int key=4;
   //cout<<first_occurence(arr,key,0,n);
   cout<<arr[first_occurence(arr,key,0)];

   //Finding the last occurence
   cout<<arr[last_occurence(arr,key,n-1)];
   return 0;
}*/

/*#include<iostream>
#include<string>
using namespace std;
int first_occurence(int arr[],int key,int i,int n)
{
   if(i==n)
   {
      return -1;
   }
  if(arr[i]==key)
  {
     return i;
  }
  else
  {
     return first_occurence(arr,key,i+1,n);
  }
}
int main()
{
   int arr[]={1,2,3,4,4,5,6,7,8,6,5,4,3,2,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   int key=4;
   int i=0;
   cout<<first_occurence(arr,key,i,n);
}*/


