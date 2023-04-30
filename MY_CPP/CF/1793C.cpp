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
ll arr[(int)2e5+1];
inline int digitSum(int n){     int sum = 0; while(n){ sum += n%10; n/=10; } return sum;    }
class MinSegTree
{
    int M = (int)8e5+1;
    ll tree[(int)8e5+1];
    public:
    MinSegTree()
    {
        /*for(int i=0;i<M;i++)
            tree[i] = 1e18;*/
    }
    void create(int n)
    {
        tree[0] = _create(0 , n-1 , 0);
    }
    ll _create(int low , int high , int i)
    {
        if(low == high)
        {
            tree[i] = arr[low];
            return tree[i];
        }
        else
        {
            int mid = (low + high)>>1;
            ll a,b;
            a = _create(low , mid , (i<<1)+1);
            b = _create(mid + 1,high ,(i<<1)+2);
            tree[i] = a<b ? a:b;
            return tree[i];
        }
    }
    void clear()
    {
        for(int i=0;i<M;i++)
            tree[i] = 1e18;
    }
    ll _query(int low , int high , int l , int r , int i)
    {
        if(r>high || l<low || l>r)
            return (ll)1e18;
        else if(l==low && r==high)
            return tree[i];
        else
        {
            int mid = (low + high)>>1;
            ll a,b;
            if(mid >=l && mid <= r)
            {
                a = _query(low , mid , l , mid , (i<<1)+1);
                b = _query(mid + 1 , high , mid + 1,r , (i<<1)+2);
                return min(a,b);
            }
            else if(r <= mid)
            {
                a = _query(low, mid  ,l , r , (i<<1)+1);
                return a;
            }
            else
            {
                a = _query(mid + 1,high ,  l, r , (i<<1)+2);
                return a;
            }   
        }
    }
    ll query(int l,int r ,int size)
    {
        return _query(0 , size-1 , l , r , 0);
    }
};
class MaxSegTree
{
    int M = (int)8e5+1; ll tree[(int)8e5+1];
    public:
    MaxSegTree()
    {
        /*for(int i=0;i<M;i++)
            tree[i] = -1e18;*/
    }
    void create(int n)  {   tree[0] = _create(0 , n-1 , 0); }
    ll _create(int low , int high , int i)
    {
        if(low == high)
        {
            tree[i] = arr[low];
            return tree[i];
        }
        else
        {
            int mid = (low + high)>>1;
            ll a,b;
            a = _create(low , mid , (i<<1)+1);
            b = _create(mid + 1,high , (i<<1)+2);
            tree[i] = (a > b ? a : b);
            return tree[i];
        }
    }
    void clear()
    {
        for(int i=0;i<M;i++)
            tree[i] = 1e18;
    }
    ll _query(int low , int high , int l , int r , int i)
    {
        if(r>high || l<low || l>r)
            return -(ll)1e18;
        else if(l==low && r==high)
            return tree[i];
        else
        {
            int mid = (low + high)>>1;
            ll a,b;
            if(mid >=l && mid <= r)
            {
                a = _query(low , mid , l , mid , (i<<1)+1);
                b = _query(mid + 1 , high , mid + 1,r , (i<<1)+2);
                return (a > b ? a : b);
            }
            else if(r <= mid)
            {
                a = _query(low, mid  ,l , r , (i<<1)+1);
                return a;
            }
            else
            {
                a = _query(mid + 1,high ,  l, r , (i<<1)+2);
                return a;
            }   
        }
    }
    ll query(int l,int r , int size)
    {
        return _query(0 , size-1 , l , r , 0);
    }
};
MaxSegTree tmax;
MinSegTree tmin;
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
    unordered_map<ll,ll> indexes;
    int n;  cin>>n;
    for(int i=0;i<n;i++)
    {   cin>>arr[i] ; indexes[arr[i]] = (ll)i;  }
    tmin.create(n);
    tmax.create(n);
    int l,r;
    l = 0;  r = n-1;
    while(l<r)
    {
        int idx_min,idx_max;
        if(l<r) 
        {
                idx_min = indexes[tmin.query(l, r,n)]    ,   idx_max = indexes[tmax.query(l,r,n)];
                if((idx_min != l && idx_min != r) && (idx_max != l && idx_max != r))
                {
                    cout<<l+1<<  " "<<r+1<<"\n";indexes.clear();    return;
                }
        }
        while(l<r && (idx_min == l || idx_max ==l))
        {
            l++;
            idx_min = indexes[tmin.query(l , r , n)];
            idx_max = indexes[tmax.query(l , r , n)];
        }
        if(l<r) 
        {
                idx_min = indexes[tmin.query(l,r,n)]    ,   idx_max = indexes[tmax.query(l,r,n)];
                if((idx_min != l && idx_min != r) && (idx_max != l && idx_max != r))
                {
                    cout<<l+1<<  " "<<r+1<<"\n";
                    indexes.clear();    return;
                }
        }
        while(l<r && (idx_max == r || idx_min == r))
        {
            r--;
            idx_max = indexes[tmax.query(l , r , n)];
            idx_min = indexes[tmin.query(l , r , n)];
        }
        if(l<r) 
        {
                idx_min = indexes[tmin.query(l,r,n)]    ,   idx_max = indexes[tmax.query(l,r,n)];
                if((idx_min != l && idx_min != r) && (idx_max != l && idx_max != r))
                {
                    cout<<l+1<<  " "<<r+1<<"\n";indexes.clear();    return;
                }
        }
    }
    cout<<"-1\n";
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