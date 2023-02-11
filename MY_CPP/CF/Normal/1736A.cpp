#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int a[n], b[n];
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
      }
      for (int i = 0; i < n; i++)
      {
         cin >> b[i];
      }
      int x = 0;
      int p, q;
      p = q = 0;
      for (int i = 0; i < n; i++)
      {
         x += !(a[i] == b[i]);
         p += (a[i] == 1);
         q += (b[i] == 1);
      }
      cout << min(abs(p - q) + 1, x) << endl;
   }
   return 0;
}