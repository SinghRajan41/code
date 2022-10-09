/*
Given an array of n integers (non-negative), and a target value tar, you need to check whether a subset of the array whose
sum of elements is equal to the target tar exists or not.
Please recall that a subset (or subsequence) of an array is taking zero or more elements from the array (in the same order
in which they occur in the array).
*/
#include <iostream>
using namespace std;
bool subset(int arr[], int i, int n, int curSum, int tar);
int main()
{
   int n, tar;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   cin >> tar;
   if (subset(arr, 0, n, 0, tar))
   {
      cout << "Yes";
   }
   else
   {
      cout << "No";
   }
   return 0;
}
bool subset(int arr[], int i, int n, int curSum, int tar)
{
   if (i >= n)
      return false;
   if (curSum == tar)
      return true;
   bool a, b;
   a = subset(arr, i + 1, n, curSum + arr[i], tar);
   b = subset(arr, i + 1, n, curSum, tar);
   return a || b;
}