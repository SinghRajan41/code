#include<iostream>
using namespace std;
void solve();
int main()
{
    int t;  //cin>>t;
    t = 1;
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
    int res[n];
    res[0] = arr[0];
    int Max = res[0];
    for(int i=1;i<n;i++)
    {
        res[i] = arr[i] + Max;
        Max = max(Max , res[i]);
    }
for(int i=0;i<n;i++)    cout<<res[i]<<" ";
    cout<<"\n";
}