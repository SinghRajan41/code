#include <iostream>
#include<vector>
#define ll long long int
using namespace std;
int  solve();
ll min(ll a,ll b,ll c)
{
	return min(min(a,b) , c);
}
ll max(ll a , ll b, ll c)
{
	return max(max(a,b) , c);
}
int gcd(int a,int b){return a==0 ? b : gcd(b%a,a);}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cout<<solve()<<"\n";
	}
	return 0;
}

int solve()
{
	int n;
	cin>>n;
	int arr[n];
	ll flag = 1;
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i] != i+1)	flag = 0;
	}
	if(flag)	return 0;
	if(arr[0] == n && arr[n-1] == 1)	return 3;
	else if(arr[0]==1 || arr[n-1] == n)	return 1;
	else
		return 2;
}
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int &x : a) cin >> x;
//     sort(a.begin(), a.end(), [](int x, int y) {
//       return x % 2 < y % 2;
//     });
//     int ans = 0;
//     for (int i = 0; i < n; ++i) {
//       for (int j = i + 1; j < n; ++j) {
//         ans += __gcd(a[i], a[j] * 2) > 1;
//       }
//     }
//     cout << ans << endl;
//   }
// }