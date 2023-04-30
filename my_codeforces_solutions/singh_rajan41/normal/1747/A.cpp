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
   FAST_IO
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      long long int pos, neg;
      pos = neg = 0;
      for (int i = 0; i < n; i++)
      {
         int temp;
         cin >> temp;
         if (temp > 0)
            pos += temp;
         else
            neg += temp;
      }
      // cout << pos << " " << neg << " ";
      cout << abs(abs(pos) - abs(neg)) << "\n";
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
int n = read();
      int arr[n];
      for (int i = 0; i < n; i++)
         arr[i] = read();

      int change = 0;
      for (int j = 0; j < n; j++)
      {
         int op = read();
         change = 0;
         for (int i = 0; i < op; i++)
         {
            char ch;
            cin >> ch;
            change = ((ch == 'D') ? change + 1 : change - 1);
         }
         change *= -1;
         if (change >= 0)
         {
            cout << (arr[j] + change) % 10 << " ";
         }
         else
         {
            cout << (arr[j] + 10 + change) % 10 << " ";
         }
      }
      cout << endl;
*/