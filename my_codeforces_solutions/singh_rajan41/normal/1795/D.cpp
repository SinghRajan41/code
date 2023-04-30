#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a,b,c,ans=1;
int ksm(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		y>>=1,x=x*x%mod;
	}
	return ans;
}
signed main()
{
	cin>>n;
	n/=3;
	for(int i=1;i<=n/2;i++) ans=ans*ksm(i,mod-2)%mod;
	for(int i=n;i>n/2;i--) ans=ans*i%mod;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		int p=min(min(a,b),c);
		int cnt=(a==p)+(b==p)+(c==p);
		ans=ans*cnt%mod; 
	}
	cout<<ans;
	return 0;
}