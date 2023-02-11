// #include <iostream>
// #include<vector>
// #define ll long long int
// using namespace std;
// void solve();
// ll min(ll a,ll b,ll c)
// {
// 	return min(min(a,b) , c);
// }
// ll max(ll a , ll b, ll c)
// {
// 	return max(max(a,b) , c);
// }
// int gcd(int a,int b){return a==0 ? b : gcd(b%a,a);}
// int a[2001];
// int arr[2001];
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		solve();
// 	}
// 	return 0;
// }

// void solve()
// {
// 	int n,evens,j,ans;
// 	j = 0;
// 	ans = 0;
// 	evens = 0;
// 	cin>>n;
// 	for(int i = 0;i<n;i++)
// 	{
// 		int temp;
// 		cin>>temp;
// 		if(temp&1)
// 		{
// 			arr[j++] = temp;
// 		}
// 		else
// 		{
// 			evens++;
// 		}
// 	}
// 	while(evens--)
// 	{
// 		ans += (n-1);
// 		n-=1;
// 	}
// 	for(int i = 0;i<j;i++)
// 	{
// 		for(int k = i+1 ; k < j ; k++)
// 		{
// 			if(gcd(arr[i] , arr[k])>1)
// 			{
// 				ans++;
// 			}
// 		}
// 	}
// 	cout<<ans<<"\n";
	

// }
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end(), [](int x, int y) {
      return x % 2 < y % 2;
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans += __gcd(a[i], a[j] * 2) > 1;
      }
    }
    cout << ans << endl;
  }
}