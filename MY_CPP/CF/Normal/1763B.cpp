#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<set>
#include<cstdlib>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
void init_sp();
ll solve();
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return  0;
}
ll solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].first;
    for(int i=0;i<n;i++)
        cin>>arr[i].second;
    
    sort(arr.begin() , arr.end() , cmp);
    int i=0;ll dsf =0;
    while(k>0 && i<n)
    {
        dsf += k;
        while(arr[i].first<=dsf && i<n) i++;
        k-=arr[i].second;
    }
    return i==n ? 1:0;
}