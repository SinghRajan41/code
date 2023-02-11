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
      ll l,r,a;
      cin>>l>>r>>a;
      ll mul = (r/a) * a;
      if(mul >=l+1 && mul<=r)
      {
         ll ans = (mul - 1)/a + (mul -1 )%a;
         ans = max(r/a + r%a,ans);
         cout<<ans<<endl;
      }
      else
      {
         ll ans = r/a + r%a;
         cout<<ans<<endl;
      }
   }
   return 0;
}
void google(int x)
{
   cout<<"Case #"<<x<<": ";
}