#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define ll long long int
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
int read();
int main()
{
   // FAST_IO
   int t;
   cin >> t;
   while (t--)
   {
      int n, x, y;
      cin >> n >> x >> y;
      if (x < y)
         swap(x, y);
      if ((x == 0 && y == 0) || (x != 0 && y != 0))
         cout << "-1\n";
      else
      {
         if (n % x != 1 && x != 1)
         {
            cout << "-1\n";
         }
         else
         {
            vector<int> winners;
            int a = n / x;
            int b = 1;
            for (int i = 0; i < a; i++)
            {
               winners.push_back(b);
               b += x;
            }
            if (a > 1)
            {
               for (int i = 1; i < a; i++)
                  winners[i] += 1;
            }
            if (x != 1)
            {
               for (auto i : winners)
               {
                  for (int j = 0; j < x; j++)
                     cout << i << " ";
               }
            }
            else
            {
               for (int i = 0; i < a - 1; i++)
               {
                  for (int j = 0; j < x; j++)
                     cout << winners[i] << " ";
               }
            }
            cout << "\n";
         }
      }
   }

   return 0;
}
int read()
{
   char k = getchar();
   ll x = 0;
   while (k < '0' || k > '9')
      k = getchar();
   while (k >= '0' && k <= '9')
      x = x * 10 + k - '0', k = getchar();
   return x;
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
/*

*/