#include <iostream>
using namespace std;
int knapsack(int weight[], int price[], int i, int n, int limit, int curWt, int curPrice);
int _knapsack(int wieght[], int price[], int n, int limit);
int knapsack2(int weight[], int price[], int n, int limit);
int main()
{
   int n, limit;
   cin >> n;
   int weight[n], price[n];
   for (int i = 0; i < n; i++)
   {
      cin >> weight[i];
   }
   for (int i = 0; i < n; i++)
   {
      cin >> price[i];
   }
   cin >> limit;
   cout << knapsack2(weight, price, n, limit);
   return 0;
}
int knapsack2(int weight[], int price[], int n, int limit)
{
   int a[limit + 1], b[limit + 1];
   bool flag = true;
   for (int i = 0; i <= limit; i++)
   {
      a[i] = b[i] = 0;
   }
   for (int i = 0; i < n; i++)
   {
      int wt = weight[i];
      int pr = price[i];
      for (int j = 0; j <= limit; j++)
      {
         if (flag)
         {
            if (j - wt >= 0)
            {
               b[j] = max(a[j], pr + a[j - wt]);
            }
            else
            {
               b[j] = a[j];
            }
         }
         else
         {
            if (j - wt >= 0)
            {
               a[j] = max(b[j], pr + b[j - wt]);
            }
            else
            {
               a[j] = b[j];
            }
         }
      }
      flag = !flag;
   }
   return !flag ? b[limit] : a[limit];
}
int _knapsack(int weight[], int price[], int n, int limit)
{
   // Dynamic programming solution
   int dp[n + 1][limit + 1];
   for (int i = 0; i <= limit; i++)
      dp[0][i] = 0;
   for (int i = 0; i < n; i++)
   {
      int wt = weight[i];
      int p = price[i];
      for (int j = 0; j <= limit; j++)
      {
         int a, b;
         a = dp[i][j];
         b = 0;
         if (j - wt >= 0)
         {
            b = dp[i][j - wt];
            b = max(b + p, a);
            dp[i + 1][j] = b;
         }
         else
         {
            dp[i + 1][j] = a;
         }
      }
   }
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= limit; j++)
      {
         cout << dp[i][j] << " ";
      }
      cout << endl;
   }
   return dp[n][limit];
}
int knapsack(int weight[], int price[], int i, int n, int limit, int curWt, int curPrice)
{
   // Recursinve Solution

   if (curWt > limit)
   {
      return 0;
   }
   if (i == n)
   {
      return curPrice;
   }
   int a = knapsack(weight, price, i + 1, n, limit, curWt + weight[i], curPrice + price[i]);
   int b = knapsack(weight, price, i + 1, n, limit, curWt, curPrice);
   return a > b ? a : b;
}