#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
int solve(int arr[],int n);
void google(int x);
ll ceildiv(ll a,ll b)
{
   return (a/b) + (a%b==0 ? 0:1);
}
vector<int> arr(200001,0);
int n,chairs;
map<int,int> m;
ll need;
int main()
{
   FIO
   int t;
   cin >> t;
   for(;t--;)
   {
      cin>>n;
      int hf = -1;
      for(int i = 0;i<n;i++)
      {
         cin>>arr[i];
         m[arr[i]]++;
         hf = max(hf,m[arr[i]]);
      }      
      if(n==1)
      {
         cout<<"0\n";
      }
      else
      {
         int rem = n - hf;
         int ops = 0;
         for(;rem > 0;)
         {
               rem -= hf;
               if(rem < 0)
               {
                  rem += hf;
                  ops += (rem + 1);
                  break;
               }
               else
               {
                  ops += (hf + 1);
                  hf <<= 1;
               }
         }
         cout<<ops<<"\n";
         m.clear();
      }
   }
   return 0;
}
void google(int x)
{
   cout<<"Case #"<<x<<": ";
}