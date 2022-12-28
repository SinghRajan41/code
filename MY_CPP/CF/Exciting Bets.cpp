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
    ll a,b;
    cin>>a>>b;
    ll maxGCD = max(a,b) - min(a,b);
    if(a>b) swap(a,b);
    if(maxGCD)
    {
        ll cost = min(a%maxGCD , maxGCD- a%maxGCD);
        cout<<maxGCD<<" "<<cost<<endl;
    }
    else
    {
        cout<<"0 0\n";
    }
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}