#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int T;
   cin >> T;
   while (T--)
   {
      int n, m;
      cin >> n >> m;
      string a, b;
      cin >> a >> b;
      if (n < m)
      {
         cout << "NO\n";
         continue;
      }
      bool same = true;
      for (int i = 1; i < b.size(); ++i)
      {
         if (a[i + n - m] != b[i])
         {
            same = false;
            break;
         }
      }
      if (!same)
      {
         cout << "NO\n";
         continue;
      }
      for (int i = 0; i < n - m + 1; ++i)
      {
         if (a[i] == b[0])
         {
            same = false;
         }
      }
      if (same)
      {
         cout << "NO\n";
      }
      else
      {
         cout << "YES\n";
      }
   }
}