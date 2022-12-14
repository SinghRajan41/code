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
int gcd(int a,int b);
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
bool solve()
{
    int n;
    char x;
    cin>>n;
    cin>>x;
    string str;
    cin>>str;
    if(x == 'g')
    {
        cout<<"0\n";
        return true;
    }
    char s[2*n];
    for(int i=0 ; i<n ; i++)
        s[i] = s[i + n] = str[i];
    int dp[2*n];
    dp[2*n-1] = INT32_MAX;
    for(int i=2*n-1;i>=0;i--)
    {
        if(s[i] == 'g')
            dp[i] = i;
        else
        {
            dp[i] = dp[i+1];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(dp[i] != INT32_MAX && s[i] == x)
        {
            ans = max(ans , dp[i] - i);
        }
    }
    cout<<ans<<"\n";
    return true;
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
