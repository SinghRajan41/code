#include <iostream>
using namespace std;
int *arr;
long long int *segTree;
void buildSegTree(int n);
long long int _buildSegTree(int low, int high, int i);
long long int set(int idx, int val, int i, int low, int high);
long long int query(int l, int r, int low, int high, int i);
int Sum(int l, int r);
int main()
{
   arr = new int[100001];
   segTree = new long long int[400005];
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   buildSegTree(n);
   for (int i = 0; i < m; i++)
   {
      int type, a, b;
      cin >> type >> a >> b;
      if (type == 1)
      {
         set(a, b, 0, 0, n - 1);
      }
      else
      {
         cout << query(a, b - 1, 0, n - 1, 0) << endl;
      }
   }
   return 0;
}
int Sum(int l, int r)
{
   int res = 0;
   for (int i = l; i <= r; i++)
   {
      res += arr[i];
   }
   return res;
}
void buildSegTree(int n)
{
   _buildSegTree(0, n - 1, 0);
}
long long int _buildSegTree(int low, int high, int i)
{
   if (low > high)
      return 0;
   if (low == high)
   {
      segTree[i] = arr[low];
      return arr[low];
   }
   long long int a, b, mid;
   a = b = 0;
   mid = (low + high) / 2;
   a = _buildSegTree(low, mid, 2 * i + 1);
   b = _buildSegTree(mid + 1, high, 2 * i + 2);
   segTree[i] = a + b;
   return segTree[i];
}
long long int set(int idx, int val, int i, int low, int high)
{
   if (low > high)
   {
      return 0;
   }
   if (low == high && low == idx)
   {
      long long int a = val - segTree[i];
      segTree[i] = val;
      return a;
   }
   else
   {
      long long int a = 0;
      int mid = (low + high) / 2;
      if (idx <= mid)
      {
         a = set(idx, val, 2 * i + 1, low, mid);
      }
      else
      {
         a = set(idx, val, 2 * i + 2, mid + 1, high);
      }
      segTree[i] += a;
      return a;
   }
}
long long int query(int l, int r, int low, int high, int i)
{
   if (l > r || low > high)
   {
      return 0;
   }
   if (low == l && high == r)
   {
      return segTree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      if (mid >= l && mid <= r)
      {
         long long int a, b;
         a = b = 0;
         a = query(l, mid, low, mid, 2 * i + 1);
         b = query(mid + 1, r, mid + 1, high, 2 * i + 2);
         return a + b;
      }
      else if (r <= mid)
      {
         long long int a = query(l, r, low, mid, 2 * i + 1);
         return a;
      }
      else
      {
         long long int a = query(l, r, mid + 1, high, 2 * i + 2);
         return a;
      }
   }
}