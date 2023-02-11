#include <iostream>
using namespace std;
int solve(int arr[], int n)
{
   // Reverse the array
   for (int i = 0; i < n / 2; i++)
   {
      swap(arr[i], arr[n - 1 - i]);
   }
   int low = 0;
   int high = n - 1;
   int count = 0;
   while (low < high)
   {
      while (low < n && arr[low] == 1)
         low++;
      while (high > -1 && arr[high] == 0)
         high--;
      if (low < high)
      {
         count++;
         low++;
         high--;
      }
   }
   cout << count << "\n";
}
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
      solve(arr, n);
   }
   return 0;
}