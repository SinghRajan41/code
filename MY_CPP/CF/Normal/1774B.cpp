#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t;
	cin>>t;
	while(t--)
	{
        cout<<(solve() ? "Yes\n" : "No\n");
    }
	
	return 0;
}
int solve()
{
    int n,m,k,a;
    cin>>n>>m>>k;
    int arr[m];
    a = 0;
    for(int i=0;i<m;i++)    cin>>arr[i];
    int l = (n + k-1)/k;
    if(l*k == n)
        l++;
    //cout<<l<<" "<<n%k<<" ";
    for(int i=0;i<m;i++)
    {
        if(arr[i] > l)
            return 0;
        if(arr[i] == l)
        {
            a++;
        }
    }
    return ((a-1<n%k) ?1:0);
}