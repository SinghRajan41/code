#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t = 1;
	//cin>>t;
	while(t--)
	{
        solve();
    }
	
	return 0;
}
int solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<k<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}