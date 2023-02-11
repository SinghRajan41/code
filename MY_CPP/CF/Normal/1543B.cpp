#include<algorithm>
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void  solve();
ll ceilDiv(ll a, ll b);
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
    ll arr[n];
    for(int i = 0;i<n;i++)  cin>>arr[i];
    ll sum = 0;
    for(int i = 0;i<n;i++)sum += arr[i];
    ll x,y;
    x = y = 0;
    ll a,b;
    a = sum / n;
    b = ceilDiv(sum , n);
    if(a^b)
    {
        for(ll i = 0;i<=n;i++)
        {
            ll p = i*a + (n - i) * b;
            if(p == sum)
            {
                x = i;
                y = n-i;
                break;
            }
        }
        cout<<(x*y)<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}