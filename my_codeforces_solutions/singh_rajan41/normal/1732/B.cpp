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
      int n;
      cin >> n;
      string s;
      cin >> s;
      int ans = 0;
      bool flag = false;
      for (int i = 1; i < n; i++)
      {
         if (s[i] != s[i - 1])
         {
            if (flag == false && s[i] == '0')
            {
               flag = true;
               ++ans;
            }
            else
            {
               if (flag)
                  ++ans;
            }
         }
      }
      cout << ans << "\n";
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