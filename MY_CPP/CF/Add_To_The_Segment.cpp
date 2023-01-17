#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n;
    ll arr[n+1];   for(int i=1;i<=n;i++)   cin>>arr[i];    arr[0] = 0;
    ll diff[n+2];   diff[0] = diff[n+1] = 0ll;
    for(int i=1;i<=n;i++)
        diff[i] = arr[i] - arr[i-1];
    int q;  cin>>q;
    for(int i=0;i<q;i++)
    {
        ll l,r,x;   cin>>l>>r>>x;
        diff[l] += x;
        diff[r+1] -= x;
    }
    ll a = 0;
    for(int i=1;i<=n;i++)
        diff[i] += diff[i-1];
    for(int i=1;i<=n;i++)
        cout<<diff[i]<<" ";
    cout<<"\n";
    return 0;
}