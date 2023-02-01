#include<iostream>
#define ll long long int
using namespace std;
void solve();
int main()
{
    int n;  cin>>n;
    while(n--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    ll n;  cin>>n; 
    ll arr[n+1],p[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        p[i] = 0;
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++)
    {
        //Update range
        for(int j=i+2;j<=min(i+arr[i] , n) ; j++) p[j]++;
        //Update answer
        ll jump = arr[i] - 1 - p[i];
        if(jump > 0)
            ans += jump;
        //push remaining pekoras ahead
        if(arr[i] <= p[i])
        {
            p[i+1] += (p[i] - arr[i] + 1);
        }
        
    }
    cout<<ans<<"\n";
}