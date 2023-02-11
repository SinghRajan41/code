#include <iostream>
#include <algorithm>
using namespace std;
int check(int arr[], int n);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int a[n], b[n];
      int full = n;
      int half = n / 2;
      for (int i = 0; i < n; i += 2)
         a[i] = half--;
      for (int i = 1; i < n; i += 2)
         a[i] = full--;
      full = n;
      half = n / 2;
      for (int i = 0; i < n; i += 2)
         b[i] = full--;
      for (int i = 1; i < n; i += 2)
         b[i] = half--;
      if (check(a, n) > check(b, n))
      {
         for (int i = 0; i < n; i++)
         {
            if (n % 2 == 1 && i % 2 == 0)
               cout << a[i] + 1 << " ";
            else
               cout << a[i] << " ";
         }
      }
      else
      {
         for (int i = 0; i < n; i++)
         {
            if (n % 2 == 1 && i % 2 == 0)
               cout << b[i] + 1 << " ";
            else
               cout << b[i] << " ";
         }
      }
      cout << endl;
   }
   return 0;
}

int check(int arr[], int n)
{
   int res = INT32_MAX;
   for (int i = 0; i < n - 1; i++)
   {
      res = min(res, abs(arr[i] - arr[i + 1]));
   }
   return res;
}