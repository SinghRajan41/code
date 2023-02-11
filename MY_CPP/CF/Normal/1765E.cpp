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
bool solve()
{
   int n,a,b;
   cin>>n>>a>>b;
   if(n<=a)
   {
        cout<<"1\n";
   }
   else
   {
    if(a>b)
        cout<<"1\n";
    else
        cout<<((n + a - 1)/a)<<"\n";
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