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
    string s;
    cin>>s;
    int n = s.length();
    int x = 2*n;
    string res(x,'a');
    for(int i = 0;i<n;i++)
    {
        res[i] = s[i];
        res[2*n-1-i] = s[i];
    }
    cout<<res<<"\n";
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}