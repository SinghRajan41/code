#include<iostream>
using namespace std;
bool solve();
#define ll long long int
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
bool solve()
{
    ll n;
    cin>>n;
    if(n<=2)
    {
        int x = 9;
        for(int i=0;i<n;i++)
        {
            cout<<x;
            x-=1;
            if(x == -1)
                x = 9;
        }
    }
    else
    {
       cout<<"98";
       ll x = 9;
       for(int i=0;i<n-2;i++)
       {
            cout<<x;
            x = (x + 1) % 10;
       }
    }
    cout<<"\n";
    return true;
}