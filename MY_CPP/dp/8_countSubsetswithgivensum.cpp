/*
You are given an array of n numbers, which represents n different types of denominations of coins.
You are given a target 'amt', you need to count the number of combinations of the coins possible that sum up to the given target amount,
i.e. in how many ways you can pay 'amt' using the available denominations.
Note 1: You can consider that you are having infinite supply of each coin denomination i.e.
the same coin denomination can be used for many installments in payment of "amt".
Note 2: You are required to find the count of combinations and not permutations. For eg, 2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7
are different permutations of the same combination. You should treat them as 1 and not 3.
*/
#include <iostream>
using namespace std;
int countSubSets(int arr[], int n, int k);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   int k;
   cin >> k;
   cout << countSubSets(arr, n, k);
   return 0;
}
int countSubSets(int arr[], int n, int k)
{
   int dp[k + 1];
   for (int i = 0; i <= k; i++)
   {
      dp[i] = 0;
   }
   dp[0] = 1;
   for (int i = 0; i < n; i++)
   {
      int coin = arr[i];
      for (int j = coin; j <= k; j++)
      {
         dp[j] = dp[j - coin] + dp[j];
      }
   }
   return dp[k];
}