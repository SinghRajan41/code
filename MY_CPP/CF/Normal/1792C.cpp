#include<iostream>
#include<vector>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;  cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int ans=-1,l,r,m;
    l = 0;
    r = n;
    while(l<=r)
    {
        m = (l + r)/2;
        bool s= true;
        vector<int> temp;
        temp.clear();
        for(int i=0;i<n;i++)
        {
            if(arr[i] > m && arr[i] <= (n-m))   temp.push_back(arr[i]);
        }
        for(int i=1;i<(temp.size());i++)
        {
            int a = temp[i-1];  int b = temp[i];
            if(a != b-1)    s = false;
        }
        if(s)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
}