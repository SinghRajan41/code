#include <bits/stdc++.h>
using namespace std;
void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   vector<int> b(n + 1);
   b[0] = a[0];
   b[n] = a[n - 1];
   for (int i = 1; i < n; i++)
   {
      b[i] = (a[i] * a[i - 1]) / __gcd(a[i], a[i - 1]);
   }
   for (int i = 1; i <= n; i++)
   {
      if (__gcd(b[i], b[i - 1]) != a[i - 1])
      {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }
   return 0;
}