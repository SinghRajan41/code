#include<iostream>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
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
    int n,m,a,b,c,d;
    cin>>n>>m;
    bool ok = false;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        if(b==c) ok = true;
    }
    cout<<((m&1) ? "NO\n" : (ok ? "YES\n" : "NO\n"));
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}