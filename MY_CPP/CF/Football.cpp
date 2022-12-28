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
    int n;
    cin>>n;
    map<string,int> m;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        m[str]++;
    }
    int freq = 0;
    string res;
    for(auto it = m.begin();it != m.end();it++)
    {
        if((*it).second > freq)
        {
            freq = (*it).second;
            res = (*it).first;
        }
    }
    cout<<res<<"\n";
    return 0;
}