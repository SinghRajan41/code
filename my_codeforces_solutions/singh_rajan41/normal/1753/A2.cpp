#include <bits/stdc++.h>
using namespace std;
int M = 2000000000;
int t, prod, n, z, sum;
int arr[200005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> t;
   for (; t--;)
   {
      z = sum = 0;
      cin >> n;
      queue<int> q;
      for (int i = 1; i <= n; ++i)
      {
         cin >> arr[i];
         if (arr[i] != 0)
            q.push(i);
         else
            ++z;
         sum += arr[i];
      }
      if ((sum > 0 ? sum : -sum) & 1)
      {
         cout << -1 << "\n";
      }
      else
      {
         if (!(z ^ n))
         {
            cout << 1 << "\n"
                 << 1 << " " << n << "\n";
            continue;
         }
         vector<pair<int, int>> seg;
         int low, high;
         low = high = 0;
         for (; !q.empty();)
         {
            if ((high + 1) ^ (q.front()))
            {
               seg.push_back(make_pair(high + 1, q.front() - 1));
               high = q.front() - 1;
            }
            low = q.front();
            q.pop();
            high = q.front();
            q.pop();
            z = high - low - 1;
            prod = arr[low] * arr[high];
            if (z == 0)
            {
               if (prod == 1)
                  seg.push_back(make_pair(low, high));
               else
               {
                  seg.push_back(make_pair(low, low));
                  seg.push_back(make_pair(high, high));
               }
            }
            else
            {
               // Zeroes exist in between
               if (z & 1)
               {
                  // Odd number of zeroes
                  if (prod == 1)
                  {
                     seg.push_back(make_pair(low, low));
                     seg.push_back(make_pair(low + 1, high));
                  }
                  else
                  {
                     seg.push_back(make_pair(low, high));
                  }
               }
               else
               {
                  // Even number of zeroes in between
                  if (prod == 1)
                  {
                     seg.push_back(make_pair(low, high));
                  }
                  else
                  {
                     seg.push_back(make_pair(low, low));
                     seg.push_back(make_pair(low + 1, high));
                  }
               }
            }
         }
         if (high ^ n)
         {
            seg.push_back(make_pair(high + 1, n));
         }
         cout << seg.size() << "\n";
         for (register int i = 0; i < seg.size(); ++i)
         {
            cout << seg[i].first << " " << seg[i].second << "\n";
         }
      }
   }
   return 0;
}