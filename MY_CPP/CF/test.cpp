#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll maxSplit(ll n);
void dp(vector<ll> arr , ll *res);
ll res = 1;
int main()
{
	ll n;	cin>>n;
	cout<<maxSplit(n);
	return 0;
}
ll maxSplit(ll n)
{
	vector<ll> arr;
	arr.push_back(n);
	dp(arr , &res);
	return res;
}
void dp(vector<ll> arr , ll *r)
{
	ll temp  = 1;
	for(int i=0;i<arr.size()&& arr.size()>1;i++)
	{
		temp *= arr[i];
	}
	*r = max(temp , *r);
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] > 3)
		{
			vector<ll> cp(arr.begin() , arr.end());
			vector<ll> cp2(arr.begin() , arr.end());
			cp2[i] -= 3;	cp2.push_back(3);
			cp[i] -= 2;	cp.push_back(2);
			dp(cp , r);
			dp(cp2 , r);
		}
	}
}