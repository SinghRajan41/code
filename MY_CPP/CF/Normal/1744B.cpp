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
      int n, q;
      cin >> n >> q;
      int arr[n];
      long long int evenSum, oddSum;
      evenSum = oddSum = 0;
      int odd, even;
      odd = even = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
         if (arr[i] & 1)
         {
            oddSum += arr[i];
            odd++;
         }
         else
         {
            evenSum += arr[i];
            even++;
         }
      }
      for (int i = 0; i < q; i++)
      {
         int type, x;
         cin >> type >> x;
         if (type == 0)
         {
            // All even numbers
            if (x % 2 == 0)
            {
               evenSum += (even * x);
            }
            else
            {
               oddSum += (even * x + evenSum);
               odd += even;
               evenSum = even = 0;
            }
         }
         else
         {
            // All odd numbers
            if (x % 2 == 0)
            {
               oddSum += (odd * x);
            }
            else
            {
               evenSum += (odd * x + oddSum);
               even += odd;
               oddSum = odd = 0;
            }
         }
         cout << evenSum + oddSum << endl;
      }
   }
   return 0;
}