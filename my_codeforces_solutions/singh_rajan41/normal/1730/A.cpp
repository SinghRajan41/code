#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, c;
      cin >> n >> c;
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      vector<int> freq(101, 0);
      for (int i = 0; i < n; i++)
         freq[arr[i]] += 1;
      int minCost = 0;
      for (int i = 1; i <= 100; i++)
      {
         if (freq[i])
            minCost += min(c, freq[i]);
      }
      cout << minCost << endl;
   }
   return 0;
}