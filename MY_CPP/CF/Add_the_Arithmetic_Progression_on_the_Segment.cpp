#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL); cout.tie(NULL);
    ll n;   cin>>n;
    ll arr[n+1],d[n+2],dd[n+2];
    arr[0] = d[0] = dd[0] = dd[n+1] = d[n+1] = 0;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    for(int i=1;i<=n;i++)   d[i] = arr[i] - arr[i-1];
    for(int i=1;i<=n;i++)   dd[i] = d[i] - d[i-1];
    int q;  cin>>q;
    for(int i=0;i<q;i++)
    {
        ll l,r,x;   cin>>l>>r>>x;
        dd[l]+=x;   dd[r+1] -= x;   dd[r+1] -= x*(r-l+1);   dd[r+2] += x*(r-l+1);
    }
    for(int i=1;i<=n;i++)   dd[i] += dd[i-1];
    for(int i=1;i<=n;i++)   dd[i] += dd[i-1];
    for(int i=1;i<=n;i++)   cout<<dd[i]<<" ";
    return 0;
}