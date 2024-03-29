// #include <bits/stdc++.h>

// #define forn(i, n) for (int i = 0; i < int(n); i++)

// using namespace std;

// int main() {
// 	int t;
// 	scanf("%d", &t);
// 	forn(_, t){
// 		int n;
// 		scanf("%d", &n);
// 		vector<int> a(n), b(n);
// 		forn(i, n) scanf("%d", &a[i]);
// 		forn(i, n) scanf("%d", &b[i]);
// 		priority_queue<int> qa(a.begin(), a.end());
// 		priority_queue<int> qb(b.begin(), b.end());
// 		int ans = 0;
// 		while (!qa.empty()){
// 			if (qa.top() == qb.top()){
// 				qa.pop();
// 				qb.pop();
// 				continue;
// 			}
// 			++ans;
// 			if (qa.top() > qb.top()){
// 				qa.push(to_string(qa.top()).size());
// 				qa.pop();
// 			}
// 			else{
// 				qb.push(to_string(qb.top()).size());
// 				qb.pop();
// 			}
// 		}
// 		printf("%d\n", ans);
// 	}
// 	return 0;
// }
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
    int n;  cin>>n;
    char s[n+1];
    for(int i=1;i<=n;i++)   cin>>s[i];
    char arr[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            arr[i][j] = (i==j) ? 'X' : '.';
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '1')
        {
            for(int j=1;j<=n;j++)
            {
                if(arr[i][j]=='.' && arr[j][i] == '.')
                    arr[i][j] = arr[j][i] = '=';

            }
            bool ok = true;
            for(int j=1;j<=n;j++)
                if(arr[i][j] == '-')
                    ok = false;
            if(!ok)
            {
                cout<<"NO\n";
                return;
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                if(arr[i][j]=='.' && arr[j][i] == '.' && s[j]=='2')
                {
                    arr[i][j] = '+';
                    arr[j][i] = '-';
                    break;
                }
            }
            bool ok = false;
            for(int j=1;j<=n;j++)
                if(arr[i][j] == '+')    
                    ok = true;
            if(!ok)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(arr[i][j] == '.')
                arr[i][j] = '=';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<arr[i][j];
        cout<<"\n";
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