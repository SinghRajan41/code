#include<iostream>
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
    int arr[n+1];
    for(int i=1;i<=n;i++)   cin>>arr[i];
    int pos[n+1];
    for(int i=1;i<=n;i++)
        pos[arr[i]] = i+1;
    for(int i=1;i<=n;i++)
        cout<<min(pos[i] , n)<<" ";
    cout<<"\n";
}