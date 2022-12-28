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
        if(solve())
            cout<<"-1\n";
    }
	
	return 0;
}
int solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i!=j && j!=k && i!=k)
                {
                    if(a[i]== a[j]+a[k])
                    {
                        cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    return 1;
}