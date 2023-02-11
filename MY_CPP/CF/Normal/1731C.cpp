#include<iostream>
#define ll long long int
using namespace std;
void solve();
int main()
{
    ll t;
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
    ll arr[n+1],pre[n+1];
    pre[0] = arr[0] = 0ll;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pre[i] = arr[i] ^ pre[i-1];
    }

    ll count = 0;
    for(ll m = 0;m*m < 2*n;m++)
    {
        ll freq[2*n];
        for(int i=0;i<2*n;i++)
            freq[i] = 0;
        for(int i=1;i<=n;i++)
        {
            if((pre[i] ^ (m*m))  < (2*n))
            {
                count += freq[pre[i] ^ (m*m)];
            }
            if(pre[i] == m*m)
                count++;
            freq[pre[i]]++;
        }
    }
    cout<<(n*(n+1)/2) - count<<"\n";
}