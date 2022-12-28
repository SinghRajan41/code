#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<map>
#include<unordered_map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[10000001];
int sp[10000001];
vector<int> primes;
vector<int> factorize(int n) ;
void init();
void initsp();
int find(int n);
ll  solve();
int gcd(int a,int b);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    initsp();
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
ll solve()
{
    int a,b;
    cin>>a>>b;
    if((a-b<0 ? b-a : a-b) == 1)
    {
        return -1;
    }
    else
    {

        
        int d = abs(b-a);
        int res = INT32_MAX;
        a = max(a,b);
        while(d != 1)
        {
            int f = sp[d];
            d /= f;
            int ceil = (a + f - 1) / f;
            res = min(res ,ceil*f - a);
        }
        return res;
        
    }
}
void initsp()
{
    //Lookup table for finding the smallest prime factor of a number
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
int find(int n)
{
    for (int d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            return d;
        }
    }
    return n;
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

