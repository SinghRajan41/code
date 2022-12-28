#include<iostream>
#define ll long long int
using namespace std;
ll count(ll x,ll n);
int main()
{
	ll n,k;
	cin>>n>>k;
	ll l,r,m;
	l = 1;
	r = n*n;
	while(l != r)
	{
		m = (l + r)>>1;
		ll x = count(m,n);
        if(x >= k)
            r = m;
		else
			l = m+1;
	}
	cout<<r<<"\n";
	return 0;
}
ll count(ll x,ll n)
{
	ll a = 0;
	for(int i=1;i<=n;i++)
		a += min(n , x/i);
	return a;
}
