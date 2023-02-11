#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int mod = 100001;
long long int _hash(string &s);
long long int binExp(long long int a, long long int b);
bool canSolve(int r, int c, int arr[], int n)
{
   int spaceLeft = r * c - 2;
   int next = n;
   bool visited[n + 1];
   for (int i = 0; i <= n; i++)
      visited[i] = false;
   for (int i = 0; i < n; i++)
   {
      visited[arr[i]] = true;
      if (arr[i] == next)
      {
         if (spaceLeft >= 2)
         {
            next--;
            while (visited[next])
            {
               next--;
               spaceLeft++;
            }
         }
         else
         {
            return false;
         }
      }
      else
      {
         spaceLeft--;
      }
   }
   return true;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int r, c, n;
      cin >> r >> c >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      if (canSolve(r, c, arr, n))
      {
         cout << "YA\n";
      }
      else
      {
         cout << "TIDAK\n";
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