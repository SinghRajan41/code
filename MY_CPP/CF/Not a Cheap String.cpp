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
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int solve()
{
    int n,limit,p,count[27];
    string s;
    for(int i=0;i<27;i++)   count[i] = 0;
    
    
    cin>>s;
    cin>>limit;
    n = s.size();
    p = 0;
    for(int i=0;i<n;i++)
    {
        count[s[i] - 'a' + 1]++;
        p += (s[i]-'a' + 1);
    }
    int i=26;
    while(i>=1 && p>limit)
    {
        while(p>limit && count[i] > 0)
        {
            p -= i;
            count[i]--;
        }
        i--;
    }
    for(int i=0;i<n;i++)
    {
        if(count[s[i] - 'a' + 1])
        {
            cout<<s[i];
            count[s[i]-'a' + 1]--;
        }
    }
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


