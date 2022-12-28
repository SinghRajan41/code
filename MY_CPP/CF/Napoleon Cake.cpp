#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
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
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)  cin>>arr[i];
    bool res[n];
    int liq = 0;
    for(int i = n-1;i>=0;i--)
    {
        if(arr[i] > liq)    liq = arr[i];
        res[i] = liq ? true : false;
        liq = max(--liq , 0);
    }
    for(int i = 0;i<n;i++) cout<<(res[i] ? "1 " : "0 ");
    cout<<endl;
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}