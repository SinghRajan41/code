#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll unsigned long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
ll binExp(ll a,ll b);
ll binExpM(ll a,ll b,ll M);
int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve()? "1\n" : "2\n");
    }*/
    ll a,b;
    cin>>a>>b;
    cout<<binExpM(a,b,100);
    return 0;
}
ll binExpM(ll a,ll b,ll M)
{
    if(b==0)
        return a;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b&1)
                res = ((res%M) * (a%M))%M;
            a = (a*a)%M;
            b>>=1;
        }
        return res;
    }
}
ll binExp(ll a,ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b & 1)
                res *= a;
            a *= a;
            b>>=1;
        }
        return res;
    }
}
bool solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i+=2)
    {
        if((s[i] - '0')&1)
            return true;
    }
    return false;
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}