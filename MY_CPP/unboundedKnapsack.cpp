// The problem is similar to 0-1 Knapsack
// However there's a slight change
//  You can pick up any number of items, within the constrain limit
#include <iostream>
using namespace std;
int ubdKnapSack(int weight[], int pirce[], int n, int limit);
int main()
{
   int n;
   cin >> n;
   int price[n], weight[n];
   for (int i = 0; i < n; i++)
   {
      cin >> price[i];
   }
   for (int i = 0; i < n; i++)
      cin >> weight[i];
   int limit;
   cin >> limit;
   cout << ubdKnapSack(weight, price, n, limit);
   return 0;
}
int ubdKnapSack(int weight[], int price[], int n, int limit)
{
   long long int dp[limit + 1];
   for (int i = 0; i <= limit; i++)
      dp[i] = 0;
   for (int i = 0; i < n; i++)
   {
      int wt = weight[i];
      int pr = price[i];
      for (int j = 0; j <= limit; j++)
      {
         if (j - wt >= 0)
         {
            dp[j] = max(dp[j], pr + dp[j - wt]);
         }
      }
   }
   return dp[limit];
}