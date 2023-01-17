#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n;   cin>>n;
    ll arr[n+1],pre[n+1];
    pre[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pre[i] = arr[i] ^ pre[i-1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<(pre[r] ^ pre[l-1])<<"\n";
    }
    return 0;
}