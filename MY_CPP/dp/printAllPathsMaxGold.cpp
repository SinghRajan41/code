#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define nl cout<<"\n";
using namespace std;
void printAllPaths(int r,int c,vector<vector<int>> &gold);
bool valid(int i,int j,int r,int c);
struct node
{
    int x;
    int y;
    string psf;
    node *next;
    node()
    {
        x = y = -1;
        psf = "";
    }
};
class queue
{
    node *first,*last;
    public:
    queue()
    {
        first = last = NULL;
    }
    void insert(int x,int y,string psf)
    {
        node *temp = new node;
        temp->x = x;
        temp->y = y;
        temp->psf = psf;
        temp->next = NULL;
        if(first == NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    bool empty()
    {
        return first == NULL ? true:false;
    }
    node remove()
    {
        node temp;
        temp.x = first->x;
        temp.y = first->y;
        temp.psf = first->psf;
        node *x = first;
        if(first->next == NULL)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            first = first->next;
            delete x;
        }
        return temp;
    }
};
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> gold;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c,-1);
        gold.push_back(temp);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>gold[i][j];
    }
    printAllPaths(r,c,gold);
    return 0;
}
bool valid(int i,int j,int r,int c)
{
    return (i>=0 && i<r && j>=0 && j<c);
}
void printAllPaths(int r,int c,vector<vector<int>> &gold)
{
    vector<vector<int>> dp;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c,0);
        dp.push_back(temp);
    }
    for(int i=0;i<r;i++)
        dp[i][c-1] = gold[i][c-1];
    for(int j=c-2;j>=0;j--)
    {
        for(int i=0;i<r;i++)
        {
            int x = 0;
            if(valid(i+1,j+1,r,c))
            {
                x = max(x,dp[i+1][j+1]);
            }
            if(valid(i,j+1,r,c))
            {
                x = max(x,dp[i][j+1]);
            }
            if(valid(i-1,j+1,r,c))
            {
                x = max(x , dp[i-1][j+1]);
            }
            dp[i][j] =  x + gold[i][j];
        }
    }
    queue q;
    int x = 0;
    for(int i=0;i<r;i++)
        x = max(x , dp[i][0]);
    for(int i=0;i<r;i++)
    {
        if(dp[i][0] == x)
        {
            q.insert(i,0,to_string(i));
        }
    }
    cout<<x<<"\n";
    int i,j;
    vector<string> res;
    while(!q.empty())
    {
        node cur = q.remove();
        i = cur.x;
        j = cur.y;
        if(j == c-1)
        {
            res.push_back(cur.psf);
            continue;
        }
        x = dp[i][j] - gold[i][j];
        if(valid(i+1,j+1,r,c) && dp[i+1][j+1] == x)
        {
            q.insert(i+1,j+1,cur.psf + 'c');
        }
        if(valid(i,j+1,r,c) && dp[i][j+1] == x)
        {
            q.insert(i,j+1,cur.psf + 'b');
        }
        if(valid(i-1,j+1,r,c) && dp[i-1][j+1] == x)
        {
            q.insert(i-1,j+1,cur.psf + 'a');
        }
    }
    sort(res.begin() , res.end());
    for(auto psf:res)
    {
        for(auto i:psf)
        {
            if(i == 'a')
            {
                cout<<" d1";
                continue;
            }
            if(i == 'b')
            {
                cout<<" d2";
                continue;
            }
            if(i == 'c')
            {
                cout<<" d3";
                continue;
            }
            cout<<i;
        }
        cout<<" ";
        cout<<endl;
    }
}

/*#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define vt vector
#define vs vt<string>
#define vi vt<int>
#define vll vt<ll>
#define vvi vt<vi>
#define vpii vt<pair<int, int>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sz(x) (int)(x).size()
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define pb push_back
#define ff first
#define ss second
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n]
#define range(a, b) substr(a, b - a + 1)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long 
#define casePrint(x, y) cout << "Case #" << x << ": " << y;
#define each(x, a) for (auto &x : a)
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define amax(a, k) a = max(a, k)
#define amin(a, k) a = min(a, k)
#define narr(n,a) int (n); read((n)); vi (a)(n); read((a));
#define nkarr(n,k,a) int (n); read((n)); int (k); read((k)); vi (a)(n); read((a));

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__) (__VA_ARGS__)

inline namespace Strings
{
    string to_string(int x) { return std::to_string(x); }
    string to_string(ll x) { return std::to_string(x); }
    string to_string(float x) { return std::to_string(x); }
    string to_string(double x) { return std::to_string(x); }
    string to_string(char c) { return string(1, c); }
    string to_string(bool b) { return b ? "true" : "false"; }
    string to_string(const char *s) { return string(s); }
    string to_string(string s) { return s; }
    string to_string(vt<bool> v) { string res; FOR(sz(v)) res += char('0' + v[i]); return res; }
    template <size_t S> string to_string(bitset<S> b) { string res; FOR(S) res += char('0' + b[i]); return res; }
    template <class H,class T> string to_string(pair<H,T> v) { return Strings::to_string(v.ff) +" "+ Strings::to_string(v.ss); }
    template <class T> string to_string(T v) { 
        bool f = 1; string res;
        each(x, v) { if (!f) res += ' '; f = 0; res += Strings::to_string(x); }
        return res;
    }
    template <class H,class T> string to_string(unordered_map<H,T> v)
    {
        bool f = 1; string res;
        each(x, v) { if (!f) res += ','; f = 0; res += " (" + Strings::to_string(x.ff) + "->" + Strings::to_string(x.ss) + ")"; }
        return res;
    }
    template <class H,class T> string to_string(map<H,T> v)
    {
        bool f = 1; string res;
        each(x, v) { if (!f) res += ','; f = 0; res += "(" + Strings::to_string(x.ff) + "->" + Strings::to_string(x.ss) + ")"; }
        return res;
    }
}

inline namespace IO
{
    template <class A> void read(vt<A> &v);
    template <class A, size_t S> void read(ar<A, S> &a);
    template <class T> void read(T &x) { cin >> x; }
    void read(double &d) { string t; read(t); d = stod(t); }
    void read(long double &d) { string t; read(t); d = stold(t); }
    template <class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }
    template <class A> void read(vt<A> &x) { each(a, x) read(a); }
    template <class A, size_t S> void read(array<A, S> &x) { each(a, x) read(a); }
    template <class A> void write(A x) { cout << Strings::to_string(x); }
    template <class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }
    void print() { write("\n"); } 
    template <class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }
}

inline namespace debug
{
    void DBG() { cerr << "]" << endl; }
    template <class H, class... T> void DBG(H h, T... t) { cerr << Strings::to_string(h); if (sizeof...(t)) cerr << ", "; DBG(t...); }
}

inline namespace handyFunctions
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
    int popcount(ll x) { return __builtin_popcountll(x); };
    ll ceil(ll n, ll div) { assert(div > 0); return n >= 0 ? (n + div - 1) / div : n / div; }
    ll floor(ll n, ll div) { assert(div > 0); return n >= 0 ? n / div : (n - div + 1) / div; }
    ll digitsum(ll n) { ll ret = 0; while (n) { ret += n % 10; n /= 10; } return ret; }
    void ynans(bool x) { if (x) print("Yes"); else print("No"); }
    bool is2pow(ll n){ return !(n&(n-1)); }

    ll closest2pow(ll n){
        if ( is2pow(n) ) return n;
        bool fb = false;
        FOR(i,31,-1,-1){ if ( fb ) n|=(1<<i); else if ( n&(1<<i) ) fb=1; }
        return n+1;
    }

    vi facts(int n){
        unordered_set<int> st;
        FOR(i,1,sqrt(n)+1)  if ( n%i==0 ){ st.insert(n/i); st.insert(i); }
        return vi(all(st));
    }

    vi primefacts(int n) {
        vi primefacts;
        while (n % 2 == 0) { primefacts.pb(2); n /= 2; }
        FOR(i,3,sqrt(n)+1,2){ while (n % i == 0) { primefacts.pb(i); n /= i; } }
        if (n > 1) primefacts.pb(n);
        return primefacts;
    }

    template <typename T> T min(const vector<T> &v) { return *min_element(v.begin(), v.end()); }
    template <typename T> T max(const vector<T> &v) { return *max_element(v.begin(), v.end()); }
    template <typename T> T acc(const vector<T> &v) { return accumulate(v.begin(), v.end(), T(0)); };
    template <typename T> T reverse(const T &v) { return T(v.rbegin(), v.rend()); };
    int sum() { return 0;}
    template<typename T, typename... Args> T sum(T a, Args... args) { return a + sum(args...); }
    ll _min() { return 1e9; }
    template<typename T, typename... Args> T _min(T a, Args... args) { return std::min(a,T(_min(args...))); }
    ll _max() { return -1e9; }
    template<typename T, typename... Args> T _max(T a, Args... args) { return std::max(a,T(_max(args...))); }
}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T, vector<T>, greater<T>>;

#define int ll
#define _DEBUG 1
#define endl "\n"

#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll inf = 1e9;
const ll linf = 1e18;
const ll MOD1 = 1e9 + 7;
const ll MOD9 = 998244353;

void solve()
{
    narr(n,a);
    vi b;
    FOR(n) b.pb(i);
    sort(all(b),[&](int x,int y){return a[x]<a[y];});
    vi ans(n);

    int mul = a[b[0]];
    FOR(i,1,n) {
        int idx = b[i];
        int x = a[idx];

        int c_m = (x + mul - 1) / mul;
        int d = mul * c_m;
        mul = d;
        ans[idx] = d-x;

    }
    print(n);
    FOR(i,0,n)
        print(i+1,ans[i]);

}

signed main(){
    FIO;
    int n = 1;
    cin>>n;
    while(n--)
        solve();
}*/