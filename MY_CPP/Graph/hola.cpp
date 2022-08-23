#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
   int t;
   cin >> t;
   int x = 1;
   while (t--)
   {
      int n;
      cin >> n;
      int Arr[n];
      unordered_map<int, int> freq;
      for (int i = 0; i < n; i++)
      {
         cin >> Arr[i];
         freq[Arr[i]]++;
      }
      vector<int> arr(Arr, Arr + n);
      sort(arr.begin(), arr.end());
      int i, j;
      i = j = 0;
      unordered_map<int, int> map;
      for (int i = 0; i < n - 1; i++)
      {
         while (j < n && (arr[j] * 0.5 <= arr[i]))
         {
            j++;
         }
         if (j - 1 == i && freq[arr[i]] == 1)
         {
            if (i == 0)
               map[arr[i]] = -1;
            else
            {
               map[arr[i]] = arr[i - 1];
            }
         }
         else
         {
            map[arr[i]] = arr[j - 1];
         }
         // map[arr[i]] = (j - 1 != i) ? (arr[j - 1]) : (-1);
      }
      map[arr[n - 1]] = arr[n - 2];
      cout << "Case #" << x << ": ";
      x++;
      for (int i = 0; i < n; i++)
      {
         cout << map[Arr[i]] << " ";
      }
      cout << endl;
   }
   return 0;
}