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
    int n;
    cin>>n;
    if(n%2 == 0)
    {
        cout<<n/2<< " "<<n/2<<"\n";
        return true;
    }
    int a,b,g,x;
    a = b = g = 0;
    vector<int> facs;
    for(int i=1;i*i<=n;i+=2)
    {
        if(n%i == 0)
        {
            facs.push_back(i);
            facs.push_back(n/i);
        }
    }
    for(int i=0;i<facs.size();i++)
    {
        if(facs[i] != n)
        {
            x = gcd(facs[i] , n-facs[i]);
            if(x>g)
            {
                g = x;
                a = facs[i];
                b = n-facs[i];
            }
        }
    }
    cout<<a<<" "<<b<<"\n";
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