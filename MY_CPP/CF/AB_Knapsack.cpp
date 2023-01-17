#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
struct item 
{
    int cost;
    int wt;
};
bool cmp(item a,item b)
{
    return a.cost < b.cost;
}
bool cmp2(item a,item b)
{
    return a.cost > b.cost;
}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,m,limit,A,B,ans;
    ans = 0;
    cin>>n>>m>>limit>>A>>B;
    item arr[n+m];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].cost;
        arr[i].wt = A;
    }
    sort(arr , arr + n , cmp);
    for(int i=n;i<n+m;i++)
    {
        cin>>arr[i].cost;
        arr[i].wt = B;
    }

    sort(arr + n , arr+n+m , cmp2);
    ll wt = 0,cost = 0;
    ll l,r;
    l = r = 0;
    for(;r<n+m;r++)
    {
        wt += arr[r].wt;
        cost += arr[r].cost;
        while(wt > limit)
        {
            wt -= arr[l].wt;
            cost -= arr[l].cost;
            l++;
        }
        if(l<=r)
        {
            ans = max(ans , cost);
        }
    }
    cout<<ans<<"\n";
    return 0;
}