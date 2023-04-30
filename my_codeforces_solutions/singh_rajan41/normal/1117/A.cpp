#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int n;
	cin>>n;
 
	int a[n];
	int i;
	int m=INT_MIN;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		m = max(a[i],m);
	}
	int b[n]={0};
	int c=0;
 
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			c++;
		}
		else
		{
			c=0;
		}
		b[i]=c;
	}
	int ans=INT_MIN;
	for(i=0;i<n;i++)
	{
		ans=max(ans,b[i]);
	}
	cout<<ans<<endl;
 
 
}