#include <bits/stdc++.h>
using namespace std;
int a[200001], t, n, k;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      char arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      for (int i = 0; i <= 2 * n; ++i)
      {
         arr[i] = '0';
      }
      int t = 0;
      int i = 1;
      while (i <= n - k + 1)
      {
         if ((arr[i] + t) % 2 == 1)
         {
            t++;
            a[i + k - 1] = 1;
         }
         t -= a[i];
         arr[i] = 48;
         i++;
      }
      for (int i = n - k + 2; i <= n; ++i)
      {
         arr[i] = 48 + (arr[i] + t) % 2;
         t -= a[i];
      }
      for (int i = 0; i < n; i++)
      {
         cout << arr[i];
      }
      cout << endl;
   }
   return 0;
}