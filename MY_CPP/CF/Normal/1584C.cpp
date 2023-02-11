#include<algorithm>
#include<iostream>
#define ll long long int
using namespace std;
bool solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}bool solve()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i = 0;i<n;i++)  cin>>a[i];
    for(int i = 0;i<n;i++)  cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0;i<n;i++)
    {
        if(a[i] == b[i] || a[i] + 1 == b[i])    continue;
        else    return false;
    }
    return true;
}