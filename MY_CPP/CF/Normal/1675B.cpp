#include <bits/stdc++.h>
using namespace std;
int solve(int arr[],int n);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
         cin>>arr[i];
      cout<<solve(arr,n)<<"\n";
   }
   return 0;
}
int solve(int arr[],int n)
{
   int ops = 0;
   for(int i =n-2 ; i>=0 ; i--)
   {
      int x = arr[i];
      while(x>= arr[i+1]  && x!=0)
      {
         x /= 2;
         ops += 1;
      }
      arr[i] = x;
      if(x == 0 && arr[i+1] == 0)
      {
         return -1;
      }
   }
   return ops;
}