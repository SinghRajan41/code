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
void init_seive();
void init_sp();
bool *seive;
int *sp;
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
    ll n,x,y;  cin>>n>>x>>y;
    string a,b; cin>>a>>b;
    vector<int> diff;
    for(int i=0;i<n;i++)
    {
        if(a[i] ^ b[i])
            diff.push_back(i);
    }
    if(diff.size() & 1)
        cout<<"-1\n";
    else
    {
        if(diff.size() == 2)
        {
            if(diff[0] + 1 == diff[1])
            {
                cout<<min(x , 2*y)<<"\n";
            }
            else
            {
                cout<<y<<"\n";
            }
        }
        else
        {
            cout<<((y*diff.size())>>1)<<"\n";
        }
    }
}
void init_seive()
{
    seive = new bool[(int)1e7+1];
    int M = 1e7 + 1;
    for(int i=0;i<=M;i++)   seive[i] = true;
    for(int i=2;i<=M;i++)
    {
        for(int j=2*i;j<=M;j+=i)
            seive[j] = false;
    }
}
void init_sp()
{
    int M = 1e7+1;
    sp = new int[M];
    for(int i=0;i<=M;i++)   sp[i] = -1;
    for(int i=2;i<=M;i++)
    {
        if(sp[i] == -1)
        {
            sp[i] = i;
            for(int j=2*i;j<=M;j+=i)
            {
                if(sp[j] == -1)
                    sp[j] = i;
            }
        }
    }
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