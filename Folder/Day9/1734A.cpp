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
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      int res = INT32_MAX;
      for (int i = 0; i < n; i++)
      {
         int t = 0;
         int c = INT32_MAX;
         int b;
         for (int j = 0; j < n; j++)
         {
            if (i != j)
            {
               if (c > abs(arr[i] - arr[j]))
               {
                  c = abs(arr[i] - arr[j]);
                  b = j;
               }
            }
         }
         t += c;
         c = INT32_MAX;
         for (int j = 0; j < n; j++)
         {
            if (i != j && j != b)
            {
               if (c > abs(arr[i] - arr[j]))
               {
                  c = abs(arr[i] - arr[j]);
               }
            }
         }
         t += c;
         res = min(res, t);
      }
      cout << res << endl;
   }
   return 0;
}