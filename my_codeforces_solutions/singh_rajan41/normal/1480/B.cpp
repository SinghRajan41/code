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
      cout<<(solve() ? "YES\n" : "NO\n");
   }
   return 0;
}
bool solve()
{
   ll A,B,n;
   cin>>A>>B>>n;
   ll a[n],b[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n;i++)
      cin>>b[i];
   ll damage = 0ll;
   for(int i=0; i<n ; i++)
   {
      ll attacks = (b[i]/A) + (b[i]%A == 0 ? 0ll:1ll);
      damage += attacks*a[i];
   }
   for(int i=0 ; i<n ; i++)
   {
      if(B - damage + a[i] >  0)
         return true;
   }
   return false;
}