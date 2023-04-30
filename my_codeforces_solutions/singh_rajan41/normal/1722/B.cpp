#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
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
      string a, b;
      cin >> a >> b;
      for (int i = 0; i < n; i++)

      {
         if (a[i] == 'G')
            a[i] = 'B';
         if (b[i] == 'G')
            b[i] = 'B';
      }
      bool flag = true;
      for (int i = 0; i < n; i++)
      {
         if (b[i] != a[i])
         {
            flag = false;
            break;
         }
      }
      cout << (flag ? "YES\n" : "NO\n");
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