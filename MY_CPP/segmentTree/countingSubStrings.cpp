#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> buildSuffix(string s);
bool cmp1(pair<char, int> a, pair<char, int> b);
bool checkSubString(string query, string s, vector<int> &p);
int stringCompare(string a, string b);
int lowerBound(string s, string query, vector<int> &p);
int upperBound(string s, string query, vector<int> &p);
int f(string s, string query, vector<int> &p);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin >> s;
   vector<int> p = buildSuffix(s);
   int q;
   cin >> q;
   for (int i = 0; i < q; i++)
   {
      string query;
      cin >> query;
      cout << f(s, query, p) << "\n";
   }
   return 0;
}
int f(string s, string query, vector<int> &p)
{
   int low = 0;
   int high = p.size() - 1;
   int ub = -1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      string temp = s.substr(p[mid], query.size());
      int a = stringCompare(temp, query);
      if (a == 0)
      {
         low = mid + 1;
         ub = mid;
      }
      else if (a > 0)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   int lb = -1;
   low = 0;
   high = p.size() - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      string temp = s.substr(p[mid], query.size());
      int a = stringCompare(temp, query);
      if (a == 0)
      {
         high = mid - 1;
         lb = mid - 1;
      }
      else if (a > 0)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return ub - lb;
}
int upperBound(string s, string query, vector<int> &p)
{
   int low = 0;
   int high = p.size() - 1;
   int ub = -1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      string temp = s.substr(p[mid], query.size());
      int a = stringCompare(temp, query);
      if (a == 0)
      {
         low = mid + 1;
         ub = mid;
      }
      else if (a > 0)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return ub;
}
int lowerBound(string s, string query, vector<int> &p)
{
   int lb = -1;
   int low, high;
   low = 0;
   high = p.size() - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      string temp = s.substr(p[mid], query.size());
      int a = stringCompare(temp, query);
      if (a == 0)
      {
         high = mid - 1;
         lb = mid - 1;
      }
      else if (a > 0)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return lb;
}
int stringCompare(string a, string b)
{
   // checks whether a is greater than b or not
   for (int i = 0; i < min(a.size(), b.size()); i++)
   {
      if (a[i] != b[i])
      {
         if (a[i] > b[i])
         {
            return 1;
         }
         else
         {
            return -1;
         }
      }
   }
   if (a.size() == b.size())
   {
      return 0;
   }
   return a.size() > b.size() ? 1 : -1;
}
bool checkSubString(string query, string s, vector<int> &p)
{
   int low = 0;
   int high = p.size() - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      string temp = s.substr(p[mid], query.size());
      int a = stringCompare(query, temp);
      if (a == 0)
      {
         return true;
      }
      else if (a > 0)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return false;
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
   return res;
}