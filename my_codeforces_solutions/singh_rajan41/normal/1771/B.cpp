#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
vector<int> primes;
vector<int> factorize(int n) ;
void init();
bool isPrime(ll n);
ll  solve();
int gcd(int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
ll solve()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n+1],dp[n+2];
    for(int i=0;i<=n;i++)
        dp[i] = arr[i] = n+1;
    dp[n+1] = n+1;
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        arr[x] = min(arr[x] , y);
    }
    dp[n] = arr[n];
    for(int i=n-1;i>=1;i--)
    {
        dp[i] = min(dp[i+1] , arr[i]);
    }
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        res += min(arr[i] , dp[i+1])  - i;
    }
    return res;
}


vector<int> factorize(int n) {
    vector<int> factorization;
    for (int d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
int gcd(int a,int b)
{
    if(a == 0)
        return b;
    else
    {
        return gcd(b%a , a);
    }
}
bool isPrime(ll n)
{
    if((!(n&1)) && n!=2)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
            if(n%i==0)  return false;
    }
    return true;
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