#include <iostream>
using namespace std;
int segTree[400005], count[400005], arr[100001];
pair<int, int> buildSegTree(int low, int high, int i);
pair<int, int> query(int l, int r, int low, int high, int i);
pair<int, int> set(int idx, int val, int low, int high, int i);
int M = 2000000000;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   for (register int i = 0; i < n; i++)
      cin >> arr[i];
   buildSegTree(0, n - 1, 0);
   int type, a, b;
   for (register int i = 0; i < m; i++)
   {
      cin >> type >> a >> b;
      if (type == 1)
      {
         set(a, b, 0, n - 1, 0);
      }
      else
      {
         pair<int, int> res = query(a, b - 1, 0, n - 1, 0);
         cout << res.first << " " << res.second << "\n";
      }
   }

   return 0;
}
pair<int, int> set(int idx, int val, int low, int high, int i)
{
   pair<int, int> a, b;
   if (low > high)
   {
      a = {M, 0};
      return a;
   }
   if (low == high && low == idx)
   {
      segTree[i] = val;
      count[i] = 1;
      a = {val, 1};
      return a;
   }
   else
   {
      int mid = (low + high) / 2;
      if (idx <= mid)
      {
         a = set(idx, val, low, mid, 2 * i + 1);
         b = {segTree[2 * i + 2], count[2 * i + 2]};
      }
      else
      {
         a = set(idx, val, mid + 1, high, 2 * i + 2);
         b = {segTree[2 * i + 1], count[2 * i + 1]};
      }
      if (a.first == b.first)
      {
         a.second = a.second + b.second;
         segTree[i] = a.first;
         count[i] = a.second;
      }
      else if (a.first < b.first)
      {
         segTree[i] = a.first;
         count[i] = a.second;
      }
      else
      {
         segTree[i] = b.first;
         count[i] = b.second;
         a = {b.first, b.second};
      }
      return a;
   }
}
pair<int, int> query(int l, int r, int low, int high, int i)
{
   pair<int, int> a, b;
   if (l > r || low > high)
   {
      a = {M, 0};
      return a;
   }
   if (l == low && r == high)
   {
      a = {segTree[i], count[i]};
      return a;
   }
   else
   {
      int mid = (low + high) / 2;
      if (mid >= l && mid <= r)
      {
         a = query(l, mid, low, mid, 2 * i + 1);
         b = query(mid + 1, r, mid + 1, high, 2 * i + 2);
         if (a.first == b.first)
         {
            a = {a.first, a.second + b.second};
         }
         else if (a.first < b.first)
         {
            a = {a.first, a.second};
         }
         else
         {
            a = {b.first, b.second};
         }
         return a;
      }
      else
      {
         if (r <= mid)
         {
            a = query(l, r, low, mid, 2 * i + 1);
            return a;
         }
         else
         {
            a = query(l, r, mid + 1, high, 2 * i + 2);
            return a;
         }
      }
   }
}
pair<int, int> buildSegTree(int low, int high, int i)
{
   pair<int, int> a = {M, 0}, b;
   if (low > high)
   {
      return a;
   }
   if (low == high)
   {
      a = {arr[low], 1};
      segTree[i] = arr[low];
      count[i] = 1;
      return a;
   }
   else
   {
      int mid = (low + high) / 2;
      a = buildSegTree(low, mid, 2 * i + 1);
      b = buildSegTree(mid + 1, high, 2 * i + 2);
      segTree[i] = (a.first < b.first ? a.first : b.first);
      if (a.first == b.first)
      {
         count[i] = a.second + b.second;
      }
      else if (a.first < b.first)
      {
         count[i] = a.second;
      }
      else
      {
         count[i] = b.second;
      }
      a = {segTree[i], count[i]};
      return a;
   }
}