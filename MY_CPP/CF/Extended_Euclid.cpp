// solve  ax + by = gcd(a,b)
#include<iostream>
#define ll long long int
using namespace std;
ll solve(ll a,ll b);
ll x,y,x1,yy1;
int main()
{
    x = y = -1;
    ll a,b;
    a = 24;
    b = 3;
    solve(a,b);
    cout<<(a*x + b*y)<<endl;
    return 0;
}
ll solve(ll a,ll b)
{
    if(b == 0)
    {
        x1 = 1;
        yy1 = 0;
        return a;
    }
    else
    {
        ll d = solve(b , a%b);
        x = yy1;
        y = x1 - (a/b)*yy1;
        x1 = x;
        yy1 = y;
        return d;
    }
}