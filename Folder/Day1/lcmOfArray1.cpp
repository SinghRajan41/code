#include <iostream>
using namespace std;
// This method is suitable for small integers
long long int lcmArray(long long int arr[], long long int n);
long long int gcd(long long int a, long long int b);
int main()
{
   long long int n;
   cin >> n;
   long long int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << lcmArray(arr, n);
   return 0;
}
long long int lcmArray(long long int arr[], long long int n)
{
   long long int ans = arr[0];
   for (int i = 1; i < n; i++)
   {
      ans = (ans * arr[i]) / gcd(ans, (long long int)arr[i]);
   }
   return ans;
}
long long int gcd(long long int a, long long int b)
{
   if (a == 0)
   {
      return b;
   }
   return gcd(b % a, a);
}