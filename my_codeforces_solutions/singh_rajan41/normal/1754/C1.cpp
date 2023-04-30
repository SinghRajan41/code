#include <bits/stdc++.h>
using namespace std;
int M = 2000000000;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      if (n & 1)
      {
         cout << -1 << "\n";
         int x;
         for (int i = 0; i < n; i++)
            cin >> x;
      }
      else
      {
         int arr[n];
         int count = 0;
         for (int i = 0; i < n; i++)
            cin >> arr[i];

         for (int i = 0; i < n; i += 2)
            if (arr[i] * arr[i + 1] == 1)
               ++count;
            else
               count += 2;
         cout << count << "\n";
         for (int i = 0; i < n; i += 2)
         {
            if (arr[i] * arr[i + 1] == 1)
            {
               cout << i + 1 << " " << i + 2 << "\n";
            }
            else
            {
               cout << i + 1 << " " << i + 1 << "\n";
               cout << i + 2 << " " << i + 2 << "\n";
            }
         }
      }
   }
   return 0;
}