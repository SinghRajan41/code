#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
      int freq = 0;
      int res = -1;
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
         if (arr[i] > freq)
         {
            freq = arr[i];
            res = i + 1;
         }
      }
      cout << res << endl;
   }
   return 0;
}