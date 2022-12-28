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
    }
    l = arr[1] - arr[0];
    for(int i=0;i<n-1;i++)
    {
        l = min(l , arr[i+1]-arr[i]);
    }
    r = arr[n-1] - arr[0];
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
            l = m+1;
            ns = m;
        }
        else
        {
            r = m-1;
        }
    }
    cout<<ns<<"\n";
    return 0;
}
bool good(ll m)
{
    int cows = 1;
    int dist = 0;
    int l,r;
    l = r = 0;
    while(r<n)
    {
        r++;
        if(r==n)
            break;
        dist = arr[r] - arr[l];
        if(dist >= m)
        {
            cows++;
            l = r;
            dist = 0;
        }
    }
    if(arr[r] - arr[l] >= m)
        cows++;
    //cout<<cows<<" ";
    return cows >= k;
}
