#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
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
bool solve()
{
    ll n,k;
    cin>>n>>k;
    ll x = n;
    ll i = 2;
    while(x>1 && x%i != 0)
    {
        i++;
    }
    if(i  == 2)
    {
        cout<<(n + 2*k)<<"\n";
    }
    else
    {
        cout<<(i+n + 2*(k-1))<<"\n";
    }
    return true;
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