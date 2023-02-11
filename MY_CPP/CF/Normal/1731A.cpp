#include<iostream>
using namespace std;
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
bool solve();
bool isPrime[100001];
void init();
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

bool solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll p = 1;
    for(int i=0;i<n;i++)
        p *= arr[i];
    cout<<(2022ll*(p+n-1))<<"\n";
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