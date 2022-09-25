#include <bits/stdc++.h>
using namespace std;
vector<int> buildSuffix(string s);
struct item
{
   int p;
   int x;
   int y;
};
int main()
{
   string s;
   cin >> s;
   vector<int> p = buildSuffix(s);
   s += '$';
   for (auto i : p)
   {
      cout << i << " -> " << s.substr(i, s.size() - i) << endl;
   }
   return 0;
}
bool cmp1(pair<int, char> a, pair<int, char> b)
{
   return a.second < b.second;
}
bool cmp2(item a, item b)
{
   return (a.x * 10 + a.y) < (b.x * 10 + b.y);
}
vector<int> buildSuffix(string s)
{
   s += '$';
   int n = s.size(), cost = 0, k;
   k = 0;
   vector<pair<int, char>> t(n);
   vector<item> a(n);
   vector<int> c(n), p(n);
   for (int i = 0; i < n; i++)
      t[i] = {i, s[i]};
   sort(t.begin(), t.end(), cmp1);
   cost = 0;
   for (int i = 1; i < n; i++)
   {
      if (t[i - 1].second != t[i].second)
         cost++;
      c[t[i].first] = cost;
   }
   c[n - 1] = 0;
   for (int i = 0; i < n; i++)
      p[i] = t[i].first;

   while ((1 << k) < n)
   {
      // creating and sorting triplet datastructure
      for (int i = 0; i < n; i++)
         a[i] = {i, c[i], c[(i + (1 << k)) % n]};
      sort(a.begin(), a.end(), cmp2);
      cost = 0;
      // updating cost array
      for (int i = 1; i < n; i++)
      {
         if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y)
         {
            cost++;
         }
         c[a[i].p] = cost;
      }
      for (int i = 0; i < n; i++)
      {
         p[i] = a[i].p;
      }
      k++;
   }
   return p;
}