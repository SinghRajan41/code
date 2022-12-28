#include<algorithm>
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void  solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    int arr[n];
    for(int i = 0;i<n;i++)  cin>>arr[i];
    /*ll t = 1;
    ll ans = 0;
    for(int i = 0;i<32;i++)
    {
        bool flag = true;
        for(int j = 0;j<n;j++)
        {
            if(((1<<i)&arr[j]) == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            ans += t;
        }
        t *= 2;
    }
    cout<<ans<<"\n";*/
    ll ans = arr[0];
    for(int i =0;i<n;i++)ans &= arr[i];
    cout<<ans<<"\n";
}
