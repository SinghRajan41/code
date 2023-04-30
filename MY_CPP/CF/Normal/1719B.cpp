#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      if (k & 1)
      {
         cout << "YES\n";
         for (int i = 2; i <= n; i += 2)
         {
            cout << i - 1 << " " << i << "\n";
         }
      }
      else if (k != 0)
      {
         if (k % 4 == 2)
         {
            cout << "YES\n";
            for (int i = 2; i <= n; i += 2)
            {
               if (i % 4 == 0)
               {
                  cout << i - 1 << " " << i << "\n";
               }
               else
               {
                  cout << i << " " << i - 1 << "\n";
               }
            }
         }
         else
         {
            cout << "NO\n";
         }
      }
      else
      {
         cout << "NO\n";
      }
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