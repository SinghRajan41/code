#include<iostream>
#include<iomanip>
#define ll long long int
using namespace std;
ll arr[(int)(1e5+1)];
ll k;
ll n;
bool good(ll m);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    ll r,l;
    r = 0;
    l = 0;
    ll ns = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        r+=arr[i];
        l = max(arr[i] , l);
    }
    if(k==n)
    {
        cout<<l<<"\n";
        exit(0);
    }
    while(l <= r)
    {
        ll m = (l + r)>>1;
        if(good(m))
        {
            r = m-1;
            ns = m;
        }
        else
        {
            l = m+1;
        }
    }
    cout<<ns<<"\n";
    return 0;
}
bool good(ll m)
{
    ll count = 0;
    ll l,r;
    l = r = -1;
    ll curSum = 0;
    while(r<n)
    {
        r++;
        if(r==n)
        {
            count++;
            break;
        }
        curSum += arr[r];
        if(curSum > m)
        {
            curSum = arr[r];
            l = r;
            count++;
        }
    }
    return count <= k;
}
