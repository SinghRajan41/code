#include <bits/stdc++.h>
using namespace std;
int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool cmp(int a, int b)
{
   return a > b;
}
long long int add(vector<int> &a)
{
   long long int res = 0;
   for (auto i : a)
      res += i;
   return res;
}
long long int solve(short skill[], int damage[], int n)
{
   long long int res = 0;
   vector<int> a, b;
   for (int i = 0; i < n; i++)
      if (skill[i] == 0)
         a.push_back(damage[i]);
      else
         b.push_back(damage[i]);

   sort(a.begin(), a.end(), cmp);
   sort(b.begin(), b.end(), cmp);
   if (a.size() == 0 || b.size() == 0)
   {
      return a.size() ? add(a) : add(b);
   }
   if (a.size() < b.size())
   {
      for (auto i : a)
         res += 2 * i;
      for (int i = 0; i < a.size(); i++)
         res += 2 * b[i];
      for (int i = a.size(); i < b.size(); i++)
         res += b[i];
      return res;
   }
   else if (a.size() > b.size())
   {
      for (auto i : b)
         res += 2 * i;
      for (int i = 0; i < b.size(); i++)
         res += 2 * a[i];
      for (int i = b.size(); i < a.size(); i++)
         res += a[i];
      return res;
   }
   else
   {
      long long int r1, r2;
      r1 = r2 = 0;
      for (auto i : a)
         r1 += 2 * i;
      for (auto i : b)
         r2 += 2 * i;
      int x = a[a.size() - 1];
      int y = b[b.size() - 1];
      res = max(r1 - 2 * x + r2 + x, r2 - 2 * y + r1 + y);
      return res;
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      short skill[n];
      int damage[n];
      for (int i = 0; i < n; i++)
         cin >> skill[i];
      for (int i = 0; i < n; i++)
         cin >> damage[i];
      cout << solve(skill, damage, n) << "\n";
   }
   return 0;
}