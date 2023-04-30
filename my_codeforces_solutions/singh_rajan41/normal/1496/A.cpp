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
bool check(string &s, int n , int k)
{
    if(k==0)    return true;
    else if(k == (n/2) && n%2 == 0) return false;
    else
    {
        for(int i = 0;i<k;i++)
        {
            if(s[i] != s[n-i-1])    return false;
        }
        return true;
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    cout<<(check(s , n ,k) ? "YES\n" : "NO\n");
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}