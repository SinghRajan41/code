#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
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
    ll n;
    cin>>n;
    ll arr[n];
    set<ll> st;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        st.insert(arr[i]);
    }
    if(st.size() < n)
    {
        cout<<"YES\n";
    }
    else
    {
        bool isdescending = true;
        for(int i=0;i<n-2;i++)
        {
            //Check descending order
            if(arr[i] <arr[i+1])
            {
                isdescending = false;
                break;
            }
        }
        if(isdescending)
        {
            if(arr[n-1] < arr[n-2])
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
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