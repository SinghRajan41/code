#include <iostream>
using namespace std;
int solve(int arr[], int n, int k)
{
   int z, o;
   z = o = 0;
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == 1)
         o++;
      else
         z++;
   }
   if (o)
   {
      cout << "YES\n";
   }
   else
   {
      cout << "NO\n";
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      solve(arr, n, k);
   }
   return 0;
}