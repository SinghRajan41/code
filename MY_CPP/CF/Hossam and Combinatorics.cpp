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
    ll n;
    cin>>n;
    ll arr[n];
    ll Max,Min;
    Max = INT32_MIN;
    ll a,b;
    a = b = 0;
    Min = INT32_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        Max = max(arr[i] , Max);
        Min = min(arr[i] , Min);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] == Max)
        {
            a++;
            continue;
        }
        if(arr[i] == Min)
        {
            b++;
        }
    }
    if(a==0 || b==0)
    {
        a = max(a,b);
        return a*(a-1);
    }
    else
    {
        return a*b*2;
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


