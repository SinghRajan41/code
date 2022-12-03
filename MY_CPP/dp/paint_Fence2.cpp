//Given n houses in line and k colours, find the number of ways of coloring n houses using k colors such that not more than three homes have same color
#include<iostream>
#define ll long long int
using namespace std;
ll factorial(ll k)
{
    ll res = 1;
    while(k>1)
    {
        res *= k;
        k--;
    }
    return res;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1],b[n+1],c[n+1],d[n+1];
    for(int i=0;i<=n;i++)   a[i] = b[i] = c[i] = d[i] = 0ll;
    a[3] = k;
    b[3] = k*(k-1);
    c[3] = k*(k-1)*(k-2);
    d[3] = b[3];
    for(int i=4;i<=n;i++)
    {
        a[i] = b[i-1];
        b[i] = (c[i-1] + d[i-1]) * (k-1);
        c[i] = b[i];
        d[i] = (a[i-1]) * (k-1);
    }
    cout<<(a[n] + b[n] + c[n] + d[n]);
    return 0;
}