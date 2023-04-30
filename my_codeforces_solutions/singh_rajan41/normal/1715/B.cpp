#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
int  solve();
int gcd(int a,int b);
int main()
{
    int t = 1;
    cin>>t;
    while(t--)
    {
        if(!solve())
            cout<<"-1\n";
    }
    return 0;
}
int solve()
{
    ll n,k,b,s,x,remain,i;
    cin>>n>>k>>b>>s;
    if(s >= b*k)
    {
        x = b*k + k-1;
        if(x>s)
            x = s;
        remain = s - x;
        if(remain <= (k-1)*(n-1))
        {
            ll res[n];
            for(i=0;i<n;i++)    res[i] = 0;
            res[0] = x;
            i = 1;
            while(remain > 0 && i<n)
            {
                if(remain > k-1)
                {
                    remain -= (k-1);
                    res[i] += k-1;
                }
                else
                {
                    res[i] +=  remain;
                    remain = 0;
                }
                /*if(res[i] >= 2*k)
                {
                    ll diff = res[i] - (2*k - 1);
                    res[i] = 2*k-1;
                    remain += diff;
                }*/
                i++;
            }
            
            for(i=0;i<n;i++)    cout<<res[i]<<" ";
            cout<<"\n";
            return true;
            
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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