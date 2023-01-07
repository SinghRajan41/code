#include<iostream>
#define ll long long int
using namespace std;
// int main()
// {
//     ll n,s;
//     cin>>n>>s;
//     ll arr[n+1],pre[n+1];pre[0] = 0;
//     for(int i=1;i<=n;i++)   cin>>arr[i] , pre[i] = pre[i-1] + arr[i];
//     ll ans = 0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i;j<=n;j++)
//         {
//             if(pre[j] - pre[i-1] <= s)
//                 ans++;
//         }
//     }
//     cout<<ans<<"\n";
//     return 0;
    
// }
int main()
{
    ll n,s; 
    cin>>n>>s;
    ll arr[n+1];
    for(int i=1;i<=n;i++)   cin>>arr[i];
    ll l = 1;
    ll x = 0,ans = 0;
    for(ll r = 1;r<=n;r++)
    {
        x += arr[r];
        while(x > s)    x -= arr[l++];
        if(x <= s)
            ans += (r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}

