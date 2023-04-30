#include <bits/stdc++.h>
using namespace std;
int64_t n,i,x,y,a[179000];
int main()
{
	for(cin>>n;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++)i<n/2?y+=a[i]:x+=a[i];
	cout<<x*x+y*y;
}