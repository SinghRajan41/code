#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputarr(arr, n)       \
   for (int i = 0; i < n; i++) \
      cin >> arr[i];
#define ll long long int
using namespace std;
int mod = 998244353;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
int read();
vector<int> generatePrimes(int m);
bool isPrime[1000000];
void init();
ll arr[200001];
ll n;
int main()
{
   // FAST_IO
   int t;
   cin >> t;
   while (t--)
   {
      cin >> n;
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      ll sum = 0;
      ll z = 0;
      bool flag = false;
      for (int i = 0; i < n - 1; i++)
      {
         sum += arr[i];
         if (!flag && arr[i] > 0)
         {
            flag = true;
         }
         if (flag && arr[i] == 0)
         {
            z++;
         }
      }
      cout << sum + z << "\n";
   }

   return 0;
}
void init()
{
   int n = 1000000;
   for (int i = 0; i < n; i++)
   {
      isPrime[i] = 1;
   }
   for (int i = 2; i < n; i++)
   {
      if (isPrime[i])
      {
         for (int j = 2 * i; j < n; j += i)
            isPrime[j] = 0;
      }
   }
}
vector<int> generatePrimes(int m)
{
   set<int> res;
   for (int i = 2; i * i <= m; i++)
   {
      if (m % i == 0 && isPrime[i])
         res.insert(i);
   }
   vector<int> a;
   for (auto i : res)
   {
      a.push_back(i);
   }
   return a;
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