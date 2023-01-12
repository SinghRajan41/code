#include<iostream>
using namespace std;
#define ll long long int
ll n,p,arr[(int)1e3+1],pre[(int)1e3+1]; 
int main()
{
    pre[0] = 0;
    cin>>n>>p;
    for(int i=1;i<=n;i++)   cin>>arr[i] , pre[i] = arr[i] + pre[i-1];
    ll num[n+1];
    for(int i=0;i<=n;i++)
        num[i] = 1e18;
    cout<<endl;
    for(int l=1;l<=n;l++)
    {
        ll songs = 0;
        ll a = pre[n] - pre[l-1];
        ll rem;
        if(p > a)
        {
            songs += (n-l+1);
            rem = p - a;
            ll cycles = rem / pre[n];
            songs += n*cycles;
            rem = rem % pre[n];
            ll r = 1;
            while(r<=n && rem > 0)  rem -= arr[r++] , songs++;
        }
        else
        {
            ll r = l;
            rem = p;
            while(r<=n && rem > 0)  rem -= arr[r++] , songs++;
        }
        num[l] = songs;
    }
    ll len = 2e18;
    ll idx = -1;
    for(int i=1;i<=n;i++)
    {
        if(num[i] < len)
        {
            len = num[i];
            idx = i;
        }
    }
    cout<<idx<<" "<<len<<"\n";
        
    return 0;
}