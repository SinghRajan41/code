#include <iostream>
#include <algorithm>
using namespace std;
int ceil(int a, int b)
{
   if (a % b == 0)
   {
      return a / b;
   }
   else
   {
      return a / b + 1;
   }
}
int main()
{

   int t = 1;
   while (t--)
   {
      int n, d;
      cin >> n >> d;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      sort(arr, arr + n);
      int low = 0;
      int high = n - 1;
      int count = 0;
      while (low <= high)
      {
         int req = ceil(d + 1, arr[high]);
         if (high - low + 1 >= req)
         {
            count++;
            high--;
            low += (req - 1);
         }
         else
         {
            low = high + 1;
         }
      }
      cout << count << endl;
   }
   return 0;
}