#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n;
    ll arr[n+1]; arr[0] = 0;   for(int i=1;i<=n;i++)   cin>>arr[i];
    ll d[n+1];  d[0] = 0;   for(int i=1;i<=n;i++)   d[i] = arr[i] - arr[i-1];
    ll q;   cin>>q;
    for(int i=0;i<q;i++)
    {
        ll k,x; cin>>k>>x;
        ll l,r; r = n;
        l = n-k+1;
        d[l] += x;  
    }
    for(int i=1;i<=n;i++)
        d[i] = d[i] + d[i-1],cout<<d[i]<<" ";
    return 0;
}