#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
void solve();
class map
{
    int * arr;
    int d;
    int m;
    public:
    map(int x)
    {
        m = x;
        d = 0;
        arr = new int[m+1];
        for(int i=0;i<=m;i++)   arr[i] = 0;
    }
    void add(int x)
    {
        if(x > m || x<1)   return;
        arr[x]++;
        if(arr[x] == 1)
            d++;
    }
    bool good()
    {
        return d >= m;
    }
    void remove(int x)
    {
        if(x > m || x<1)
            return;
        if(arr[x] == 0) return;
        arr[x]--;
        if(arr[x] == 0) d--;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
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
    int n,m;    cin>>n>>m;
    int arr[n]; for(int i=0;i<n;i++)    cin>>arr[i];
    vector<int> divs[n];
    sort(arr , arr+n);
    for(int i=0;i<n;i++)
    {
        int num = arr[i];
        for(int j=1;j*j <= num ; j++)
        {
            if(num % j == 0)
            {
                divs[i].push_back(j);
                if(num/j != j)
                    divs[i].push_back(num / j);
            }
        }
    }
    map mp(m);
    int l,r;
    l = r = 0;
    ll ans = -1;
    ll len = INT32_MAX;
    for(l = 0;l<n;l++)
    {
        while(!mp.good() && r<n)
        {
            for(auto j:divs[r])
                mp.add(j);
            r++;
        }
        if(mp.good() && l<=r-1)
        {
            if(arr[r-1] - arr[l] < len)
            {
                len = arr[r-1] - arr[l];
                ans = len;
            }
        }
        for(auto j:divs[l])
            mp.remove(j);
    }
    cout<<ans<<"\n";
}