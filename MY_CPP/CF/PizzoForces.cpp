#include<algorithm>
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void  solve();
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
void solve()
{
    ll n;
    cin>>n;
    if(n&1) n+=1;
    n = max(n , (ll)6);
    ll ans = 5*(n/2);
    cout<<ans<<"\n";
}
