#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,limit;    cin>>n>>limit;
    ll w[n],c[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)   
        cin>>c[i];
    ll ans = 0;
    ll cost = 0;
    ll wt = 0;
    ll l = 0;
    for(int r= 0;r<n;r++)
    {
        cost += c[r];
        wt += w[r];
        while(wt > limit)
        {
            wt -= w[l];
            cost -= c[l];
            l++;
        }
        ans = max(cost , ans);
    }
    cout<<ans<<"\n";
    return 0;
}