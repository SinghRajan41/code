#include<iostream>
#define ll long long int
using namespace std;
bool solve();
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      cout<<(solve() ? "YES\n" : "NO\n");
   }
   return 0;
}
bool solve()
{
   ll n;
   cin>>n;
   ll arr[n];
   for(int i = 0;i<n;i++)  cin>>arr[i];
   ll a[n],b[n];
   b[0] = 0;
   a[0] = arr[0];
   for(int i=1 ; i<n ; i++)
   {
      b[i] = b[i-1] + i;
      a[i] = a[i-1] + arr[i];
      if(a[i] < b[i])
         return false;
   }
   return true;

}