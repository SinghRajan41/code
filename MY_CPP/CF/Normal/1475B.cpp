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
   int n;
   cin>>n;
   int x,y;
   x = y = 0;
   for(int i = 0;i<500;i++)
   {
      y=0;
      for(int j=0;j<500;j++)
      {
         if(x+y == n)   return true;
         y+=2020;
      }
      x+=2021;
   }
   return false;
}