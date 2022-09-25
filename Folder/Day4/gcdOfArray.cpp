#include <iostream>
using namespace std;
int arrayGCD(int arr[], int n);
int gcd(int a, int b);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << arrayGCD(arr, n);
   return 0;
}
int gcd(int a, int b)
{
   if (a == 0)
   {
      return b;
   }
   else
   {
      return gcd(b % a, a);
   }
}
int arrayGCD(int arr[], int n)
{
   int res = arr[0];
   for (int i = 1; i < n; i++)
   {
      res = gcd(res, arr[i]);
   }
   return res;
}