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
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int solve()
{
    ll n,d;
    cin>>n>>d;
    ll arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ll count,low,high,Max,Min;
    low = high = count = 0;
    Max = Min = arr[0];
    while(high < n)
    {
        high++;
        if(high>=n) break;
        Max = max(Max , arr[high]);
        Min = min(Min , arr[high]);
        if(Max - Min > 2*d)
        {
            count++;
            low = high;
            Max = Min = arr[high];
        }
    }
    cout<<count;
    nl;
    return 0;
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


