#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve();
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
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin() , arr.end());
    for(int i=0;i<n-1;i++)
    {
        res[arr[i].second] = arr[i].first - arr[n-1].first;
    }
    res[arr[n-1].second] = arr[n-1].first - arr[n-2].first;
    for(int i=0;i<n;i++)
        cout<<res[i]<< " ";
    cout<<"\n";
}