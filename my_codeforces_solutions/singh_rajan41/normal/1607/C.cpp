#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
void solve();
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    ll n;   cin>>n; ll arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ll sum = 0;
    sort(arr , arr+n);
    ll ans = arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i] -= sum;
        ans = max(ans , arr[i]);
        sum += arr[i];
    }
    cout<<ans<<"\n";
}