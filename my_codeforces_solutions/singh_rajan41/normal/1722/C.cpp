#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int M = 100001;
long long int binExp(long long int a, long long int b)
{
   if (b == 0)
      return 1ll;
   else
   {
      if (b & 1)
      {
         long long int t = binExp(a, b / 2);
         return (a % M * 1ll * t % M * t % M) % M;
      }
      else
      {
         long long int t = binExp(a, b / 2);
         return (t % M * t % M) % M;
      }
   }
}
long long int _hash(string &s)
{
   int h = 0;
   for (int i = 0; i < s.length(); i++)
   {
      int hashValue = binExp(31, i + 1);
      hashValue = (hashValue % M * (s[i] - 'a' + 1) % M) % M;
      h = (h % M + hashValue % M) % M;
   }
   return (long long int)h;
}
int f[100001];
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      for (int i = 0; i < 100001; i++)
         f[i] = 0;
      vector<string> a(n), b(n), c(n);
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         f[_hash(a[i])]++;
      }
      for (int i = 0; i < n; i++)
      {
         cin >> b[i];
         f[_hash(b[i])]++;
      }
      for (int i = 0; i < n; i++)
      {
         cin >> c[i];
         f[_hash(c[i])]++;
      }
      int aScore, bScore, cScore;
      aScore = bScore = cScore = 0;
      for (int i = 0; i < n; i++)
      {
         int x = f[_hash(a[i])];
         if (x == 1)
            aScore += 3;
         else if (x == 2)
            aScore += 1;
         x = f[_hash(b[i])];
         if (x == 1)
            bScore += 3;
         else if (x == 2)
            bScore += 1;
         x = f[_hash(c[i])];
         if (x == 1)
            cScore += 3;
         else if (x == 2)
            cScore += 1;
      }
      cout << aScore << " " << bScore << " " << cScore << endl;
   }
   return 0;
}

/*int t;
cin >> t;
while (t--)
{
   int n;
   cin >> n;
   vector<string> a(n), b(n), c(n);
   unordered_map<string, int> map;
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      map[a[i]]++;
   }
   for (int i = 0; i < n; i++)
   {
      cin >> b[i];
      map[b[i]]++;
   }
   for (int i = 0; i < n; i++)
   {
      cin >> c[i];
      map[c[i]]++;
   }
   int aScore, bScore, cScore;
   aScore = bScore = cScore = 0;
   for (int i = 0; i < n; i++)
   {
      int x = map[a[i]];
      if (x == 1)
         aScore += 3;
      else if (x == 2)
         aScore += 1;
      x = map[b[i]];
      if (x == 1)
         bScore += 3;
      else if (x == 2)
         bScore += 1;
      x = map[c[i]];
      if (x == 1)
         cScore += 3;
      else if (x == 2)
         cScore += 1;
   }
   cout << aScore << " " << bScore << " " << cScore << endl;*/