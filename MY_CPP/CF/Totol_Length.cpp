#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
struct item {ll l;ll r;};
ll f(ll i);
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,s;
    cin>>n>>s;
    ll arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    ll l = 1;
    ll x = 0;
    vector<item> seg;
    seg.push_back({0 , 0});
    for(ll r=1;r<=n;r++)
    {
        x += arr[r];
        while(x > s && l<=r)
            x -= arr[l++];
        if(l<=r)
            seg.push_back({l,r});
    }
    ll ans = 0;
    for(int i=1;i<seg.size();i++)
    {
        ans += f(seg[i].r - seg[i].l + 1);
        if(seg[i-1].r >= seg[i].l)
            ans -= f(seg[i-1].r - seg[i].l + 1);
    }
    cout<<ans<<"\n";
    return 0;
}
ll f(ll i)
{
    return ((i*(i+1)*(i+1))/2)  - (i*(i+1)*(2*i+1))/6;
}