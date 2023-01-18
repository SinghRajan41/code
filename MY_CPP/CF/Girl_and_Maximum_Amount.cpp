#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,q; cin>>n>>q;
    ll arr[n+1];  for(int i=0;i<n;i++)    cin>>arr[i+1];  
    ll diff[n+1],freq[n+1];
    for(int i=0;i<=n;i++)   freq[i] = diff[i] = 0;
    for(int i=0;i<q;i++){   int l,r;    cin>>l>>r;  diff[l]++;  diff[r+1]--;    }
    for(int i=1;i<=n;i++)   diff[i] += diff[i-1];
    sort(diff + 1, diff + n+1); sort(arr+1 , arr + n+1);
    ll res = 0;
    for(int i=1;i<=n;i++)   res += diff[i] * arr[i];
    cout<<res<<"\n";
    return 0;
}