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
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
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
    int n,w,h;  cin>>n>>w>>h;
    int a[n] , b[n];    
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)    cin>>b[i];
    int del  = a[0] - w + h - b[0];
    for(int i=0;i<n;i++)    b[i] += del;
    int l = 0;
    int r = a[0] + w - b[0] - h;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r)>>1;
        int al,bl,ar,br,bi;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            bi = b[i] + mid;
            al = a[i] - w;
            bl = bi - h;
            ar  = a[i] + w;
            br  = bi + h;
            if(bl>=al && br <= ar)
            {
                continue;
            }
            else
            {
                flag = false;
                if(br > ar)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
                break;
            }
        }
        if(flag)
        {
            ans = 1;
            break;
        }
    }
    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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