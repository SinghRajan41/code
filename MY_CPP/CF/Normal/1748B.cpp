#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
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
      int ans,n,limit,mf,dist;
      ans = 0;
      string s;
      cin>>n;
      cin>>s;
      for(int i = 0; i < n; i++)
      {
         limit  = (n < i+100 ? n : i+100);
         vector<int> freq(10,0);
         mf = dist = 0;
         for(int j = i; j<limit ; j++)
         {
            freq[s[j] - '0']++;
            if(freq[s[j] - '0'] == 1)
               ++dist;
            mf = max(mf , freq[s[j] - '0']);
            if(dist >= mf)
               ans++;
            
         }
      }
      cout<<ans<<endl;
   }
   return 0;
}
void google(int x)
{
   cout<<"Case #"<<x<<": ";
}