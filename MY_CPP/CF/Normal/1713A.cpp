#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
int calcCost(vector<int> &arr);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> X, Y, Xn, Yn;
      int Xmin, Ymin;
      Xmin = Ymin = INT32_MAX;
      for (int i = 0; i < n; i++)
      {
         int x, y;
         cin >> x >> y;
         if (x == 0 && y == 0)
            continue;
         if (y == 0)
         {
            if (x > 0)
               X.push_back(x);
            else
               Xn.push_back(x);
         }
         if (x == 0)
         {
            if (y > 0)
               Y.push_back(y);
            else
               Yn.push_back(y);
         }
      }

      int cost = 0;

      cost += calcCost(X);
      cost += calcCost(Y);
      cost += calcCost(Xn);
      cost += calcCost(Yn);
      cout << cost << endl;
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