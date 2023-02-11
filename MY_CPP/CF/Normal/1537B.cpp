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
	ll r,C,x,y;
	cin>>r>>C>>x>>y;
	ll maxDist = -1;
	ll a,b,c,d;
	vector<pair<ll,ll>> points;
	points.push_back(make_pair(1,1));
	points.push_back(make_pair(1,C));
	points.push_back(make_pair(r,1));
	points.push_back(make_pair(r,C));
	for(int i = 0;i<4;i++)
	{
		for(int j = i;j<4;j++)
		{
			ll mhd = 2*(r+C-2);
			ll mr,Mr,mc,Mc;
			mr = min(x , points[i].first , points[j].first);
			Mr = max(x , points[i].first , points[j].first);
			mc = min(y , points[i].second , points[j].second);
			Mc = max(y , points[i].second , points[j].second);
			mr = Mr - mr+1;
			mc = Mc - mc+1;
			if(mhd == 2*(mr + mc -2))
			{
				a = points[i].first;
				b = points[i].second;
				c = points[j].first;
				d = points[j].second;
			}
		}
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
}