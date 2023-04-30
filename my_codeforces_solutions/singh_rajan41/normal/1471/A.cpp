#include<iostream>
using namespace std;
void solve();
#define ll long long int
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
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    for(int i = 0;i<n;i++)  cin>>arr[i];
    ll Max,Min;
    Max=Min = 0;
    for(int i = 0;i<n;i++)
    {
        Min += arr[i];
        Max += (arr[i] + x - 1)/x;
    }
    cout<<(Min + x - 1)/x<<" "<<Max<<endl;
}