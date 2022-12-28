#include<iostream>
#define ll long long int
using namespace std;
ll count(ll mid, ll n,ll l[] , ll r[]);
int main()
{
	ll n,k;
	cin>>n>>k;
	ll l[n],r[n];
	for(int i=0;i<n;i++)
		cin>>l[i]>>r[i];
	ll low = INT32_MAX;
	ll high = INT32_MIN;
	ll mid;
	k++;
	for(int i=0;i<n;i++)
	{
		low = min(low , l[i]);
		high = max(high , r[i]);
	}
	while(low != high)
	{
		mid = (low + high)>>1;
		ll x = count(mid , n , l , r);
		if(x == k)
			low = high = mid;
		else if(x > k)
			high = mid;
		else
			low = mid + 1;
	}
	cout<<low<<"\n";
	return 0;
}
ll count(ll mid, ll n,ll l[] , ll r[])
{
	ll a = 0;
	for(int i=0;i<n;i++)
	{
		if(l[i] <= mid)
			a += min(r[i]- l[i]+1ll , mid - l[i]+1ll);
	}
	return a;
}

