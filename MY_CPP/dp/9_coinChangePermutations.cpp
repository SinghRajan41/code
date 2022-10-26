#include <bits/stdc++.h>
using namespace std;
int countPerm(vector<int> &arr, int n, int k);
int main()
{
   int n;
   cin >> n;
   vector<int> arr(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   int k;
   cin >> k;
   cout << countPerm(arr, n, k);
   return 0;
}
int countPerm(vector<int> &arr, int n, int k)
{
   int dp[k + 1];
   for (int i = 0; i <= k; i++)
   {
      dp[i] = 0;
   }
   dp[0] = 1;
   for (int i = 0; i <= k; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i - arr[j] >= 0)
         {
            dp[i] += dp[i - arr[j]];
         }
      }
   }
   return dp[k];
}