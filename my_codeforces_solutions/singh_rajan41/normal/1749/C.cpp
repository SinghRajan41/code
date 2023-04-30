#include <iostream>
#include <algorithm>
using namespace std;
bool check(int arr[], int n, int k);
int solve(int arr[], int n);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      sort(arr, arr + n);
      cout << solve(arr, n) << endl;
   }
   return 0;
}
bool check(int arr[], int n, int k)
{
   int low = 0;
   int high = n - 1;
   while (low <= high)
   {
      if (k == 0)
         return true;
      while (arr[high] > k && low <= high)
         high--;
      if (low > high)
         return false;
      else
      {
         ++low;
         --high;
         --k;
      }
   }
   return k == 0 ? true : false;
}
int solve(int arr[], int n)
{
   for (int i = n; i > 0; i--)
   {
      if (check(arr, n, i))
      {
         return i;
      }
   }
   return 0;
}