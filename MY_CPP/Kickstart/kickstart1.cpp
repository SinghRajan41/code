#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }

   int pd=arr[1]-arr[0];
   int    temp=2,ans=INT_MIN;
   int j=2;
   while(j<n)
   {
      if(pd==(arr[j]-arr[j-1]))
      {
          temp++;
          ans=max(ans,temp);
      }
      
      else
      {
          temp=2;
         pd=arr[j]-arr[j-1];
      }
      j++;
   }
   cout<<ans;
   return 0;
}