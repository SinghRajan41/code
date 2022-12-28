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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}
ll solve()
{
    int n;
    cin>>n;
    int arr[n];
    int idx[n+1];
    for(int i=0;i<=n;i++)   idx[i] = -1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        idx[arr[i]] = i;
    }
    vector<int> lk,dk;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '1') lk.push_back(arr[i]);
        else            dk.push_back(arr[i]);
    }
    sort(lk.begin(),lk.end());
    sort(dk.begin(),dk.end());
    int pos = 0;
    int x = lk.size();
    int a = n - x + 1;
    for(auto i:lk)
    {
        arr[idx[i]] = a++;
    }
    a = 1;
    for(auto i:dk)
    {
        arr[idx[i]] = a++;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
