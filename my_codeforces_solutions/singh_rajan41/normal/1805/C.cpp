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
inline int digitSum(int n);
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    ll n,m; cin>>n>>m;
    struct para{
        ll a;
        ll b;
        ll c;
        ll d;
    };
    ll d[n];
    para p[m];
    for(int i=0;i<n;i++)    cin>>d[i];
    for(int i=0;i<m;i++)    
    {
        cin>>p[i].a>>p[i].b>>p[i].c;
        p[i].d = p[i].b*p[i].b - 4*p[i].c*p[i].a;
    }
    sort(d , d+n);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        a = p[i].a; b = p[i].b; c = p[i].c;
        if(b > d[n-1])
        {
            if(p[i].d < (d[n-1] * (2*b - d[n-1]))){
                cout<<"YES\n";
                cout<<d[n-1]<<"\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else if(b < d[0])
        {
            ll k  = d[0];
            if(p[i].d < (k * (2*b - k)))
            {
                cout<<"YES\n";  cout<<k<<"\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            ll k1,k2;
            int low,high;
            low = 0;
            high = n-1;
            bool f1,f2;
            f1 = f2 = false;
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                if(d[mid] >= b)
                {
                    k1 = d[mid];
                    high = mid - 1;
                    f1 = true;
                }
                else
                {
                    low = mid + 1;
                }
            }
            if(f1)
            {
                if(p[i].d < (k1 * (2*b - k1)))
                {
                    cout<<"YES\n"<<k1<<"\n";
                    continue;
                }
            }
            low = 0;
            high = n-1;
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                if(d[mid] <= b)
                {
                    k2 = d[mid];
                    f2 = true;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if(f2)
            {
                if(p[i].d < (k2* ( 2*b - k2)))
                {
                    cout<<"YES\n";  cout<<k2<<"\n";
                    continue;
                }
            }
            cout<<"NO\n";
        }
    }
    cout<<"\n";
}
inline int digitSum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
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