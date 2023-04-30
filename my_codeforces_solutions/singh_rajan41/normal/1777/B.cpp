#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool seive[10000001];
int sp[10000001];
vector<int> factorize(int n) ;
void init();            
void initsp();             
ll  solve();
ll M =(int) 1e9+7;
int gcd(int a,int b);
int main()
{   ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
ll solve()
{
    ll n;
    cin>>n;
    ll t = (n*(n-1));
    for(ll i=1;i<=n;i++)
    {
        t = (t*i)%M;
    }
    cout<<t<<"\n";
    return 0;
}
void initsp()
{
    int M = 10000001;
    for(int i=0;i<M;i++)
        sp[i] = -1;
    for(int i=2;i<M;i+=2)
        sp[i] = 2;
    sp[1] = 1;
    for(int i=3;i<M;i+=2)
    {
        if(sp[i]  == -1)
        {
            sp[i] = i;
            for(int j=2*i;j<M;j+=i)
            {
                if(sp[j] == -1)
                {
                    sp[j] = i;
                }
            }
        }
    }
}
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
vector<int> factorize(int n) {
    vector<int> facs;
    /*while(n > 1)
    {
        int f = sp[n];
        n/=f;
        facs.push_back(f);
    }
    return facs;*/
    for(int i=1;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            if(i != n/i)
                facs.push_back(i) , facs.push_back(n/i);
            else
                facs.push_back(i);
        }
    }
    return facs;
}
void init()
{
    for(int i=0;i<100001;i++)   seive[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(seive[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                seive[j] = false;
            }
        }
    }
}