#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#define ll long long int
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
int calcCost(vector<int> &arr);
bool check(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      if (arr[i] % arr[0])
         return false;
   }
   return true;
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
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = read();
   while (t--)
   {
      int n = read();
      int m = read();
      int arr[n];
      for (int i = 0; i < n; i++)
         arr[i] = read();
      bool hasA[m + 1];
      for (int i = 0; i <= m; i++)
         hasA[i] = 0;
      for (int i = 0; i < n; i++)
      {
         int a = min(arr[i], m - arr[i] + 1);
         if (hasA[a] == 0)
            hasA[a] = 1;
         else
         {
            a = max(arr[i], m - arr[i] + 1);
            hasA[a] = 1;
         }
      }
      for (int i = 1; i <= m; i++)
         cout << (hasA[i] ? 'A' : 'B');
      cout << endl;
   }
   return 0;
}
int calcCost(vector<int> &arr)
{
   int cost = 0;
   if (arr.size())
   {
      for (int i = 0; i < arr.size(); i++)
      {
         arr[i] = max(arr[i], -arr[i]);
      }
      sort(arr.begin(), arr.end());
      cost += 2 * abs(arr[0]);
      for (int i = 1; i < arr.size(); i++)
      {
         cost += 2 * (abs(arr[i] - arr[i - 1]));
      }
   }
   return cost;
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