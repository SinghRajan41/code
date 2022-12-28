#include<iostream>
#define ll long long int
using namespace std;
bool f(ll arr[],ll n,ll k,ll m);
int main()
{
    ll n,k;
    cin>>k>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll low = 0;
    ll high = 50e9;
    ll a = 0;
    while(low<=high)
    {
        ll mid = (low + high)>>1;
        if(f(arr,n,k,mid))
        {
            low = mid + 1;
            a = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<a<<"\n";
    return 0;
}
bool f(ll arr[],ll n,ll k,ll m)
{
    ll s  = k*m;
    for(int i=0;i<n;i++)
    {
        s -= min(arr[i] ,  m);
    }
    return s<=0 ? true:false;
}