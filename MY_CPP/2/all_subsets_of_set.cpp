/*#include<iostream>
using namespace std;
int check(int n)
{
   int c=0;
   while(n)
   {
      n=n & (n-1);
      c++;
   }
   return c;
}                                       //NCr   all possible r combinations from n characters
int main()
{
   char set[5]={'r','a','j','i','n'};
   int n=5;
   for(int i=0; i < 1<<n; i++)
   {
      if (check(i)==3)
      {
         for(int j=0;j<n;j++)
         {
            if(i & (1<<j))
            {
               cout<<set[j]<<" ";
            }
         }
         cout<<endl;
      }
   }
   return 0;
}*/
//Write a code to generate all possible subsets of a set
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   char arr[]={'a','b','c','d'};
   int n=sizeof(arr)/sizeof(arr[0]);
   for(int i=0;i<pow(2,n);i++)
   {
      for(int j=0;j<=31;j++)
      {
         if(i & (1<<j))
         {
            cout<<arr[j]<<" ";
         }

      }
      cout<<endl;
   }

   return 0;
}