#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
   if (a == 0)
   {
      return b;
   }
   else
   {
      return gcd(b % a, a);
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int arr[n];
      vector<int> maxIdx(1001, -1), hash(1001, 0);
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
         maxIdx[arr[i]] = max(maxIdx[arr[i]], i);
         ++hash[arr[i]];
      }
      vector<int> s;
      for (int i = 1; i <= 1000; i++)
      {
         if (hash[i])
         {
            s.push_back(i);
         }
      }
      int res = -1;
      for (int i = s.size() - 1; i >= 0; i--)
      {
         for (int j = i; j >= 0; j--)
         {
            if (gcd(s[i], s[j]) == 1)
            {
               res = max(res, maxIdx[s[i]] + 2 + maxIdx[s[j]]);
            }
         }
      }
      cout << res << endl;
   }
   return 0;
}