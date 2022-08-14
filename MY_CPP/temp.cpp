#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n],q[k];
	for(int i=0;i<n;i++)
	{
		a[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		cin>>q[i];
	}
	///Solutions
	for(int i=0;i<k;i++)
	{
		a[q[i]-1]++;
	}
	for(int i=1;i<n;i++)
	{
		a[i]=a[i]+a[i-1];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}