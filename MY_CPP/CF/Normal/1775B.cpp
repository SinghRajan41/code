#include<bits/stdc++.h>

using namespace std;
bool solve();
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "Yes\n" : "No\n");
    }
    return 0;
}
bool solve()
{
    int n;  cin>>n;
    vector<int> arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int k;  cin>>k; arr[i].resize(k);
        for(int j=0;j<k;j++)
        {
            cin>>arr[i][j];
            mp[arr[i][j]]++;
        }
    }
    int a = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            if(mp[arr[i][j]] == 1)
            {
                a++;
                break;
            }
        }
    }
    return a==n ? false:true;
}