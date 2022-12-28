#include<iostream>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
bool solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(n==b && b==a)
        return true;
    else if(a+b>=n && a+b<2*n)
        return false;
    else
    {
        if(n-(a+b) >= 2)
            return true;
        else
            return false;
    }
}


