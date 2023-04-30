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
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first + a.second  < b.first + b.second;
}
pair<int,int> solve(int n);
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
bool check(pair<int,int> x);
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
bool check(pair<int,int> x)
{
    int a,b;
    a = digitSum(x.first);
    b = digitSum(x.second);
    if(abs(a-b) > 1)
        return false;
    else
        return true;
}
void solve()
{
    string s;
    cin>>s; int n = s.length();
    int a[n],b[n],arr[n];
    for(int i=0;i<n;i++)
        arr[i] = (int)(s[i] - '0');
    bool up = true;
    for(int i=0;i<n;i++)
    {
        if(arr[i] & 1)
        {
            //odd digit
            if(up)
            {
                a[i] = arr[i]/2;
                b[i] = arr[i] - arr[i]/2;
            }
            else
            {
                a[i] = arr[i] - arr[i]/2;
                b[i] = arr[i]/2;
            }
            up = up ? false : true;
        }
        else
        {
            a[i] = b[i] = arr[i]/2;
        }
    }
    int x,y;
    x = y = 0;
    for(int i=0;i<n;i++)
    {
        x = x*10 + a[i];
        y = y*10 + b[i];
    }
    cout<<x<< " "<<y<<"\n";
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