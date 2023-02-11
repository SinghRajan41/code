#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
bool solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
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
bool solve()
{
    ll n;
    cin>>n;
    for(ll i=1;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            ll a = n/i;
            ll b = a + 1;
            a = a&b;
            if(a == 0)
            {
                cout<<i<<"\n";
                return true;
            }
            if(i != 1)
            {
                a = i;
                b = i+1;
                a = a&b;
                if(a == 0)
                {
                    cout<<n/i<<"\n";
                    return true;
                }
            }
        }
    }
    return false;
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