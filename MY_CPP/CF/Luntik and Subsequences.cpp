#include<algorithm>
#include<iostream>
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
    ll z,o;
    z=o = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 1) o++;
        else if(arr[i] == 0) z++;
    }
    cout<< (o) * (1ll<<z)<<"\n";
}
