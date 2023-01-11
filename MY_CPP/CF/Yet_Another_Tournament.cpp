#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve();
bool cmp(pair<int,int> a,pair<int,int> b);
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
void solve()
{
    int n,m;  cin>>n>>m;
    vector<pair<int,int>> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++)    cin>>arr[i].first , arr[i].second = i;
    sort(arr.begin() , arr.end());
    
    
        int i=0;
        int a = m;
        int v = 0;
        for(i=0;i<n && arr[i].first <= a;i++)
            a -= arr[i].first , ++v;
        if(v!=0 && v!=n && (arr[v-1].first + a >= arr[v].first)) ++v;
        cout<<(n+1-v)<<"\n";
    

}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first  < b.first;
}