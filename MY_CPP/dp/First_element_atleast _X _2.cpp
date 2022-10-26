#include <iostream>
using namespace std;
int n, m;
int arr[100001];
int M = INT32_MAX / 2;
int tree[400004];
int buildTree(int low, int high, int i);
int set(int low, int high, int i, int idx, int val);
int find(int low, int high, int i, int l, int x);
int main()
{
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   buildTree(0, n - 1, 0);
   for (int i = 0; i < m; i++)
   {
      int a;
      cin >> a;
      if (a == 1)
      {
         int idx, val;
         cin >> idx >> val;
         set(0, n - 1, 0, idx, val);
      }
      else
      {
         int l, x;
         cin >> x >> l;
         int pos = find(0, n - 1, 0, l, x);
         if (pos != M)
         {
            cout << pos << "\n";
         }
         else
         {
            cout << "-1\n";
         }
      }
   }
   return 0;
}

int buildTree(int low, int high, int i)
{
   if (low == high)
   {
      tree[i] = arr[low];
      return tree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      int a = buildTree(low, mid, 2 * i + 1);
      int b = buildTree(mid + 1, high, 2 * i + 2);
      tree[i] = a > b ? a : b;
      return tree[i];
   }
}
int set(int low, int high, int i, int idx, int val)
{
   if (low == high)
   {
      arr[low] = val;
      tree[i] = val;
      return val;
   }
   else
   {
      int mid = (low + high) / 2;
      int a, b;
      if (idx <= mid)
      {
         a = set(low, mid, 2 * i + 1, idx, val);
         b = tree[2 * i + 2];
      }
      else
      {
         a = set(mid + 1, high, 2 * i + 2, idx, val);
         b = tree[2 * i + 1];
      }
      tree[i] = (a > b ? a : b);
      return tree[i];
   }
}
int find(int low, int high, int i, int l, int x)
{
   if (x > tree[i])
      return M;
   if (low == high && tree[i] >= x)
      return low;
   else
   {
      int mid = (low + high) / 2;
      int lm = tree[2 * i + 1];
      int rm = tree[2 * i + 2];
      int a, b;
      a = b = M;
      if (lm >= x && mid >= l)
      {
         a = find(low, mid, 2 * i + 1, l, x);
         if (a == M)
         {
            if (rm >= x)
            {
               b = find(mid + 1, high, 2 * i + 2, l, x);
            }
         }
      }
      else
      {
         if (rm >= x)
            a = find(mid + 1, high, 2 * i + 2, l, x);
      }
      return min(a, b);
   }
}