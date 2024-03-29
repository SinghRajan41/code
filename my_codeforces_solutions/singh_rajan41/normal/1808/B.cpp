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
int check(string s , int a , int b , char l , char r);
int luck(int x);
long long int evaluate(long long int arr[] ,long long int n);
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
int luck(int x)
{
    int high =  0;
    int low = 9;
    while(x)
    {
        int temp = x%10;
        high = max(high , temp);
        low  = min(low , temp);
        x /= 10;
    }
    return high - low;
}
long long int evaluate(long long int arr[] ,long long  int n)
{
    sort(arr , arr+n);
    long long int temp = 0;
    for(int i=0;i<n;i++)    temp += (arr[i] * i - arr[i]*(n-i-1));
    return temp;
}
void solve()
{
    long long int n,m;    cin>>n>>m;
    long long int arr[n][m];
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    cin>>arr[i][j];
    long long int ans = 0;
    long long int temp[n];
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
            temp[i] = arr[i][j];
        ans += evaluate(temp  ,  n);
    }
    cout<<ans<<"\n";
}
int check(string s , int a , int b , char l , char r)
{
    int n = s.length();
    string temp = s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i != j)
            {
                temp = s;
                temp[i] = l;    temp[j] = r;
                int x = stoi(temp);
                if(x>=a && x<=b)    return x;
                temp = s;
                temp[i] = r;    temp[j] = l;
                x = stoi(temp);
                if(x>=a && x<=b)    return x;
            }
        }
    }
    return -1;
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