#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;
void solve();
ll add_mod_m(ll a, ll b,ll m);
ll sub_mod_m(ll a,ll b,ll m);
ll mul_mod_m(ll a,ll b,ll m);
ll div_mod_m(ll a,ll b,ll m);
ll extended_euclid(ll a,ll b, ll *x,ll * y);
ll binExp_Mod_M(ll a,ll b,ll m);
ll MMI(ll a,ll m);
ll gcd(ll a,ll b);
int main()
{
    int t;
    string s = "codeforces";
    cin>>t;
    while(t--)
    {
        char x;
        cin>>x;
        bool flag = false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == x)
            {
                flag = true;
            }
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
void solve()
{

}
ll add_mod_m(ll a, ll b,ll m)
{
    return ((a%m) + (b%m))%m;
}
ll sub_mod_m(ll a,ll b,ll m)
{
    return ((a%m) - (b%m) + m)%m;
}
ll mul_mod_m(ll a,ll b,ll m)
{
    return ((a%m) * (b%m))%m;
}
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
    {
        return gcd(b , a%b);
    }
}
ll extended_euclid(ll a,ll b, ll *x,ll * y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    else
    {
        ll g = extended_euclid(b , a%b , x,y);
        ll x1 = *x;
        ll y1 = *y;
        *x = y1;
        *y = x1 - y1*(a/b);
        return g;
    }
}
ll MMI(ll a,ll m)
{
    //return MODULAR INVERSE
    ll x,y;
    extended_euclid(a,m,&x,&y);
    x = ((x%m) + m)%m; // coz x may become negative
    return x;
}
ll binExp_Mod_M(ll a,ll b,ll m)
{
    ll x = a;
    ll res = 1;
    while(b > 0)
    {
        if(b&1)
        {
            res = ((res%m)*(x%m))%m;
        }
        b>>=1;
        x = ((x%m) * (x%m))%m;
    }
    return res;
}