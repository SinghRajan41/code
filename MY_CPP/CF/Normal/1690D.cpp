#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
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
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
int solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int pre[n+1];
    pre[0] = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'B') pre[i+1] = pre[i] + 1;
        else    pre[i+1] = pre[i];
    }
    int res = INT32_MAX;
    for(int i=0;i+k<=n;i++)
    {
        int a = pre[i+k] - pre[i];
        a = k-a;
        res = min(res , a);
    }
    return res;
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