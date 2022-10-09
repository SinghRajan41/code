/*
Given an array of n integers (non-negative), and a target value tar, you need to check whether a subset of the array whose
sum of elements is equal to the target tar exists or not.
Please recall that a subset (or subsequence) of an array is taking zero or more elements from the array (in the same order
in which they occur in the array).
*/
#include <iostream>
using namespace std;
bool subset(int arr[], int n, int k);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   int tar;
   cin >> tar;
   if (subset(arr, n, tar))
   {
      cout << "Yes";
   }
   else
   {
      cout << "No";
   }
   return 0;
}
bool subset(int arr[], int n, int k)
{
   bool dp[n + 1][k + 1];
   for (int i = 0; i <= k; i++)
   {
      dp[0][i] = false;
   }
   dp[0][0] = true;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j <= k; j++)
      {
         if (dp[i][j])
         {
            dp[i + 1][j] = true;
         }
         else
         {
            if (j - arr[i] >= 0 && dp[i][j - arr[i]])
            {
               dp[i + 1][j] = true;
            }
            else
            {
               dp[i + 1][j] = false;
            }
         }
      }
   }
   return dp[n][k];
}