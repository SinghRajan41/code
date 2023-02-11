#include<iostream>
using namespace std;
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
int M = 1e9+7;
bool solve();
bool isPrime[100001];
void init();
ll mul(ll a,ll b );
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
ll mul(ll a,ll b )
{
    return ((a%M)*(b%M))%M;
}
bool solve()
{
    ll n;
    cin>>n;
    ll a = mul(337ll , n);
    a = mul(a , n+1);
    a = mul(a , 2*n+1);
    ll b = mul(337ll , n-1);
    b = mul(b , n);
    b = mul(b , 2*n-1);
    ll c = mul(1011ll , n);
    c = mul(c , n-1);
    cout<<(a+b+c)%M<<"\n";
    return 0;
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