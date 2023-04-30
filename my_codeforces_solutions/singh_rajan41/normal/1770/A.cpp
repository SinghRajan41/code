#include<iostream>
#define ll long long int
using namespace std;
void solve();
int main()
{
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
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    for(int i=0;i<m;i++)
    {
        int idx = 0;
        for(int j=0;j<n;j++)
        {
            if(a[j] < a[idx])
                idx = j;
        }
        a[idx] = b[i];
    }
    ll sum = 0;
    for(int i=0;i<n;i++)
        sum += a[i];
    cout<<sum<<"\n";
}