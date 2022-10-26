#include <iostream>
using namespace std;
int *arr;
int *segTree;
void buildSegTree(int n);
int _buildSegTree(int low, int high, int i);
int set(int idx, int val, int low, int high, int i);
int query(int l, int r, int low, int high, int i);
void fastscan(int &number);
int M = INT32_MAX / 2;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   arr = new int[100001];
   segTree = new int[400005];
   int n, m;
   cin >> n >> m;
   for (register int i = 0; i < n; i++)
      cin >> arr[i];
   buildSegTree(n);
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
         cout << query(a, b - 1, 0, n - 1, 0) << "\n";
      }
   }
   return 0;
}
void fastscan(int &number)
{
   bool negative = false;
   register int c;

   number = 0;
   c = getchar();
   if (c == '-')
   {
      negative = true;
      c = getchar();
   }
   for (; (c > 47 && c < 58); c = getchar())
      number = number * 10 + c - 48;
   if (negative)
      number *= -1;
}
void buildSegTree(int n)
{
   _buildSegTree(0, n - 1, 0);
}
int query(int l, int r, int low, int high, int i)
{
   if (l > r || low > high)
      return M;
   if (l == low && r == high)
      return segTree[i];
   else
   {
      int mid, a, b;
      mid = (low + high) / 2;
      if (mid >= l && mid <= r)
      {
         a = query(l, mid, low, mid, 2 * i + 1);
         b = query(mid + 1, r, mid + 1, high, 2 * i + 2);
         return a < b ? a : b;
      }
      else if (r <= mid)
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
int set(int idx, int val, int low, int high, int i)
{
   if (low > high)
      return M;
   if (low == high && idx == low)
   {
      segTree[i] = val;
      return segTree[i];
   }
   else
   {
      int mid, a, b;
      mid = (low + high) / 2;
      a = M;
      if (idx <= mid)
      {
         a = set(idx, val, low, mid, 2 * i + 1);
         b = segTree[2 * i + 2];
         segTree[i] = (a < b ? a : b);
      }
      else
      {
         a = set(idx, val, mid + 1, high, 2 * i + 2);
         b = segTree[2 * i + 1];
         segTree[i] = (a < b ? a : b);
      }
      return segTree[i];
   }
}
int _buildSegTree(int low, int high, int i)
{
   if (low > high)
   {
      return M;
   }
   if (low == high)
   {
      segTree[i] = arr[low];
      return segTree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      int a, b;
      a = _buildSegTree(low, mid, 2 * i + 1);
      b = _buildSegTree(mid + 1, high, 2 * i + 2);
      segTree[i] = (a < b ? a : b);
      return segTree[i];
   }
}