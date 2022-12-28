#include <iostream>
#include<vector>
#define ll long long int

using namespace std;
void solve();
ll min(ll a,ll b,ll c)
{
	return min(min(a,b) , c);
}
ll max(ll a , ll b, ll c)
{
	return max(max(a,b) , c);
}
int gcd(int a,int b){return a==0 ? b : gcd(b%a,a);}
int a[2001];
int arr[2001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

void solve()
{
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)	cin>>a[i];
	int j = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i] % 2 == 0)
		{
			arr[j++] = a[i];
		}
	}
	for(int i = 0;i<n;i++)
	{
		if(a[i] % 2 == 1)
		{
			arr[j++] = a[i];
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		if(arr[i] % 2 == 0)
		{
			ans += (n-i-1);
		}
		else
		{
			for(int j = i+1 ; j < n ; j++)
			{
				if(gcd(arr[i] , arr[j]) > 1)	ans++;
			}
		}
	}
	cout<<ans<<endl;
}