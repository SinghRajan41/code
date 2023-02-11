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
   ll n;
   cin>>n;
   ll i = 3;
   while((n%2) == 0) n >>= 1;
   while(n>1)
   {
      while(n%i==0)
      {  
         n /= i;
         if(i&1)
            return true;
         
      }
      i+=2;
   }
   return false;
}