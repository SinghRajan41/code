#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
bool solve();
struct monster
{
   ll power;
   ll health;
   float gain;
};
bool cmp(monster a, monster b)
{
   return a.gain > b.gain;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      solve();
   }
   return 0;
}
bool solve()
{
   ll n,k;
   cin>>n>>k;
   ll arr[n*k];
   for(int i=0;i<n*k;i++)
      cin>>arr[i];
   ll idx = n*k - n/2 -1;
   ll sum = 0;
   for(int i=0;i<k;i++)
   {
      sum += arr[idx];
      idx -= (n/2 + 1);
   }
   cout<<sum<<"\n";
   return false;
}