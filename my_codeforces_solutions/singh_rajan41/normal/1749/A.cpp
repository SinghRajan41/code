#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      for (int i = 0; i < m; i++)
      {
         int x, y;
         cin >> x >> y;
      }
      cout << (m < n ? "YES\n" : "NO\n");
   }
   return 0;
}