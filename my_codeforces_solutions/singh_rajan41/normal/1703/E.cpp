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
int evaluate(int i1,int j1,int i2,int j2,vector<vector<int>> &arr);
int main()
{
    //ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int evaluate(int i1,int j1,int i2,int j2,vector<vector<int>> &arr)
{
    int d = j2 - j1 + 1;
    int res = 0;
    //cout<<d<<" ";
    //cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" ";
    for(int i=0;i<d-1;i++)
    {
        int z,o;    
        z = o = 0;
        if(arr[i1 + d - 1][j1 + i]) o++;    else    z++;
        if(arr[i1+i][j1]) o++;              else    z++;
        if(arr[i1][j1 + d - 1 - i]) o++;    else    z++;
        if(arr[i2-i][j2])   o++;            else    z++;
        res += min(o , z);
        arr[i1 + d - 1][j1 + i] = arr[i1+i][j1] = arr[i1][j1 + d - 1 - i] = arr[i2-i][j2] =  o < z ? 0:1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n , vector<int>(n));
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    {   char ch;    cin>>ch;    arr[i][j] = ch == '1' ? 1 : 0;  }
    int i1,j1,i2,j2;
    if(n&1)
    {
        i1 = j1 = n/2 - 1;
        i2 = j2 = n/2 + 1;
    }
    else
    {
        i1 = j1 = n/2 - 1;
        i2 = j2 = n/2;
    }
    int ans = 0;
    while(i1 >= 0)
    {
        ans += evaluate(i1,j1,i2,j2,arr);
        i1--;
        j1--;
        i2++;
        j2++;
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<  " ";
        cout<<"\n";
    }*/
    cout<<ans<<"\n";
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