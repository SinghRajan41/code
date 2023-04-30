#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;
void solve();
ll add_mod_m(ll a, ll b, ll m);
ll sub_mod_m(ll a, ll b, ll m);
ll mul_mod_m(ll a, ll b, ll m);
ll div_mod_m(ll a, ll b, ll m);
ll extended_euclid(ll a, ll b, ll *x, ll *y);
ll binExp_Mod_M(ll a, ll b, ll m);
ll MMI(ll a, ll m);
ll gcd(ll a, ll b);
void init_seive();
void init_sp();
bool *seive;
int *sp;
inline int digitSum(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int a = 0;
    int n,k;  cin>>n>>k;
    string boss;    cin>>boss;
    a = n;
    for(int i=0;i<n-1;i++)
    {
        string temp;    cin>>temp;
        if(boss == temp)
        {
            continue;
        }
        else
        {
            a--;
        }
    }
    cout<<a<<"\n";
}
class segTree{
    int tree[500000];
    int N;
    public:
    int create(int arr[] , int low , int high , int i)
    {
        if(low > high)
        {
            return 0;
        }
        else if(low == high){
            tree[i] = arr[low];
            return tree[i];
        }
        else{
            int mid = (low  + high) >> 1;
            int x,y;
            x = create(arr , low , mid , 2*i+1);
            y = create(arr , mid + 1 , high , 2*i+2);
            tree[i] = max(x,y);
            return tree[i];
        }
    }
    void init(int arr[] , int n){
        N = n;
        tree[0] = create(arr , 0 , n-1 , 0);
    }
    int _query(int low , int high , int l  ,int r , int i)
    {
        if(l>r || l<low || r > high){
            return 0;
        }
        else if(l==low && r== high){
            return tree[i];
        } 
        else{
            int mid = (low + high) / 2;
            if(mid>=l && mid <= r)
            {
                int x,y;
                x = _query(low , mid , l  , mid, 2*i+1);
                y = _query(mid + 1 , high , mid + 1 , r , 2*i+2);
                return max(x,y);
            }
            else if(r<= mid)
            {
                return _query(low , mid , l , r , 2*i+1);
            }
            else
            {
               return  _query(mid + 1 , high , l , r , 2*i+2);
            }
        }

    }
    int query(int low , int high)
    {
        if(low > high)  return -1;
        return _query(0 , N-1 , low , high ,0);
    }

};
inline int digitSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
void init_seive()
{
    seive = new bool[(int)1e7 + 1];
    int M = 1e7 + 1;
    for (int i = 0; i <= M; i++)
        seive[i] = true;
    for (int i = 2; i <= M; i++)
    {
        for (int j = 2 * i; j <= M; j += i)
            seive[j] = false;
    }
}
void init_sp()
{
    int M = 1e7 + 1;
    sp = new int[M];
    for (int i = 0; i <= M; i++)
        sp[i] = -1;
    for (int i = 2; i <= M; i++)
    {
        if (sp[i] == -1)
        {
            sp[i] = i;
            for (int j = 2 * i; j <= M; j += i)
            {
                if (sp[j] == -1)
                    sp[j] = i;
            }
        }
    }
}
ll add_mod_m(ll a, ll b, ll m)
{
    return ((a % m) + (b % m)) % m;
}
ll sub_mod_m(ll a, ll b, ll m)
{
    return ((a % m) - (b % m) + m) % m;
}
ll mul_mod_m(ll a, ll b, ll m)
{
    return ((a % m) * (b % m)) % m;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
    {
        return gcd(b, a % b);
    }
}
ll extended_euclid(ll a, ll b, ll *x, ll *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    else
    {
        ll g = extended_euclid(b, a % b, x, y);
        ll x1 = *x;
        ll y1 = *y;
        *x = y1;
        *y = x1 - y1 * (a / b);
        return g;
    }
}
ll MMI(ll a, ll m)
{
    // return MODULAR INVERSE
    ll x, y;
    extended_euclid(a, m, &x, &y);
    x = ((x % m) + m) % m; // coz x may become negative
    return x;
}
ll binExp_Mod_M(ll a, ll b, ll m)
{
    ll x = a;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % m) * (x % m)) % m;
        }
        b >>= 1;
        x = ((x % m) * (x % m)) % m;
    }
    return res;
}