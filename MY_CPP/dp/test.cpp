#include <bits/stdc++.h>
using namespace std;
struct item
{
   int cost;
   string path;
};
class cmp
{
public:
   bool operator()(item a, item b)
   {
      return a.cost > b.cost;
   }
};
/*int subsetCount(int arr[], int n, int sum)
{
   int t[n + 1][sum + 1];
   for (int i = 1; i < sum + 1; i++)
      t[0][i] = 0;

   for (int i = 0; i < n + 1; i++)
      t[i][0] = 1;

   for (int i = 1; i < n + 1; i++)
      for (int j = 1; j < sum + 1; j++)
      {
         if (arr[i - 1] <= j)
            t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]);
         else
            t[i][j] = t[i - 1][j];
      }

   return t[n][sum];
}*/
int isSubSet(int arr[], int n, int sum)
{
   // here i is no of ele and j is sum
   int dp[n + 1][sum + 1];

   for (int i = 0; i < n + 1; i++)
   {
      for (int j = 0; j < sum + 1; j++)
      {
         if (i == 0)
         {
            dp[i][j] = 1;
         }
         if (j == 0)
         {
            dp[i][j] = 0;
         }
      }
   }

   for (int i = 1; i < n + 1; i++)
   {
      for (int j = 0; j < sum + 1; j++)
      {
         if (arr[i - 1] <= j)
         {
            dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
         }
         else
         {
            dp[i][j] = dp[i - 1][j];
         }
      }
   }
   return dp[n][sum];
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   int k;
   cin >> k;
   cout << isSubSet(arr, n, k);
   return 0;
}