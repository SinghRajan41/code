#include <bits/stdc++.h>
using namespace std;
char low, high;
int main()
{
   int x;
   cin >> x;
   while (x--)
   {
      string s;
      getline(cin >> ws, s);
      vector<pair<char, int>> arr;
      if (s[0] < s[s.size() - 1])
      {
         low = s[0];
         high = s[s.size() - 1];
      }
      else
      {
         high = s[0];
         low = s[s.size() - 1];
      }
      if (s.size() == 2)
      {
         cout << abs(s[0] - s[1]) << " " << 2 << endl
              << 1 << " " << 2 << endl;
      }
      else
      {
         for (int i = 1; i < s.size() - 1; i++)
         {
            if (s[i] >= low && s[i] <= high)
            {
               arr.push_back(make_pair(s[i], i + 1));
            }
         }
         cout << abs(s[0] - s[s.size() - 1]) << " " << arr.size() + 2 << endl;
         cout << 1 << " ";
         if (arr.size() > 0)
         {
            sort(arr.begin(), arr.end());
            // We need to print
            if (s[0] < s[s.size() - 1])
            {
               // Print in ascending order
               for (int i = 0; i < arr.size(); i++)
               {
                  cout << arr[i].second << " ";
               }
            }
            else
            {
               for (int i = arr.size() - 1; i >= 0; i--)
               {
                  cout << arr[i].second << " ";
               }
            }
         }
         cout << s.size() << endl;
      }
   }
   return 0;
}