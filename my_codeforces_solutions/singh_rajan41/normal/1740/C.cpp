#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
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
      int bag3 = arr[n - 1];
      int res = 0;
      for (int i = 0; i < n - 2; i++)
      {
         int bag2 = arr[i];
         int bag1 = arr[i + 1];
         res = max(res, abs(bag2 - bag1) + abs(bag3 - bag2));
      }
      bag3 = arr[0];
      for (int i = 1; i < n - 1; i++)
      {
         res = max(res, arr[i + 1] - arr[i] + arr[i + 1] - arr[0]);
      }

      cout << res << endl;
   }
   return 0;
}

long long int _hash(string &s)
{
   int h = 0;
   for (int i = 0; i < s.length(); i++)
   {
      int hashValue = binExp(31, i + 1);
      hashValue = (hashValue % mod * (s[i] - 'a' + 1) % mod) % mod;
      h = (h % mod + hashValue % mod) % mod;
   }
   return (long long int)h;
}
long long int binExp(long long int a, long long int b)
{
   if (b == 0)
      return 1ll;
   else
   {
      if (b & 1)
      {
         long long int t = binExp(a, b / 2);
         return (a % mod * 1ll * t % mod * t % mod) % mod;
      }
      else
      {
         long long int t = binExp(a, b / 2);
         return (t % mod * t % mod) % mod;
      }
   }
}