#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
bool solve();
bool isPrime[100001];
bool cmp(int a,int b);
void init();
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

bool solve()
{
    int n;cin>>n;   int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr , arr+n, cmp);
    vector<int> res;
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    if(s.size() == 1)
    {
        cout<<"NO\n";
        return false;
    }
    else
    {
        int low = 0;
        int high = n-1;
        bool f = true;
        while(low <= high)
        {
            if(f)
            {
                res.push_back(arr[low++]);
            }
            else
            {
                res.push_back(arr[high--]);
            }
            f = f ? false:true;
        }
       
        cout<<"YES\n";
        for(auto i:res)
            cout<<i<<" ";
        cout<<"\n";
        return false;
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}