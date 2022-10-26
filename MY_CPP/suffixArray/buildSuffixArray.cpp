#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> buildSuffix(string s);
bool cmp1(pair<char, int> a, pair<char, int> b);
int main()
{
   string s;
   cin >> s;
   vector<int> p = buildSuffix(s);
   for (auto i : p)
   {
      cout << i << " ";
   }
   return 0;
}
bool cmp1(pair<char, int> a, pair<char, int> b)
{
   return a.first < b.first;
}
bool cmp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
   if (a.second.first == b.second.first)
   {
      return a.second.second < b.second.second;
   }
   else
   {
      return a.second.first < b.second.first;
   }
}
vector<int> buildSuffix(string s)
{
   s += '$';
   int n = s.size();
   vector<int> res(n), c(n), b(n);
   vector<pair<char, int>> t(n);
   for (int i = 0; i < n; i++)
   {
      t[i] = make_pair(s[i], i);
   }
   sort(t.begin(), t.end(), cmp1);
   for (int i = 0; i < n; i++)
   {
      res[i] = t[i].second;
   }
   int k = 0;
   b[0] = 0;
   for (int i = 1; i < n; i++)
   {
      b[i] = b[i - 1] + !(t[i].first == t[i - 1].first);
   }
   for (int i = 0; i < n; i++)
   {
      c[t[i].second] = b[i];
   }
   while ((1 << k) < n)
   {
      vector<pair<int, pair<int, int>>> a(n);
      for (int i = 0; i < n; i++)
      {
         a[i] = {i, {c[i], c[(i + (1 << k)) % n]}};
      }
      sort(a.begin(), a.end(), cmp2);
      for (int i = 0; i < n; i++)
      {
         res[i] = a[i].first;
      }
      vector<int> temp(n);
      temp[0] = 0;
      for (int i = 1; i < n; i++)
      {
         if (a[i].second.second == a[i - 1].second.second && a[i].second.first == a[i - 1].second.first)
         {
            temp[i] = temp[i - 1];
         }
         else
         {
            temp[i] = temp[i - 1] + 1;
         }
      }
      for (int i = 0; i < n; i++)
      {
         c[a[i].first] = temp[i];
      }
      k++;
   }
   vector<int> r(n - 1);
   for (int i = 1; i < n; i++)
   {
      r[i - 1] = res[i];
   }
   return r;
}