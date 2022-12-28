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
    int n;
    cin>>n;
    if(n&1)
    {
        for(int i = 0;i<n;i++)
        {
            cout<<"1 ";
        }
        cout<<"\n";
    }
    else
    {
        for(int i = 0;i<n-2;i++)
        {
            cout<<"4 ";
        }
        cout<<"2 6\n";
    }

    
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}