#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// int main()
// {
//     ll n,s;
//     cin>>n>>s;
//     ll arr[n+1],pre[n+1];
//     pre[0] = 0;
//     for(int i=1;i<=n;i++)   cin>>arr[i] , pre[i] = pre[i-1] + arr[i];
//     ll ans = 0, x = 0,l=1;
//     for(ll r=1;r<=n;r++)
//     {
//         x += arr[r];
//         while(x > s)    x-=arr[l++];
//         if(x <= s)
//             ans += (r-l+1);
//     }
//     ll temp = 0;
//     unordered_map<ll,ll> mp;
//     mp[0]++;
//     for(int i=1;i<=n;i++)
//     {
//         temp += mp[pre[i] - s];
//         mp[pre[i]]++;
//     }
//     ans = (n*(n+1))/2 - ans + temp;
//     cout<<ans<<"\n";
//     return 0;
// }
int main()
{
    ll n,s; cin>>n>>s;
    ll arr[n+1];    for(int i=1;i<=n;i++)   cin>>arr[i];
    ll ans = 0,x = 0,l=1;
    for(ll r=1;r<=n;r++)
    {
        x += arr[r];
        while(x - arr[l] >= s)
            x -= arr[l++];
        if(x >= s)
            ans += (n-r+1);
    }
    cout<<ans<<"\n";
}