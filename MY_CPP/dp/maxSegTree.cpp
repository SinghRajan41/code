#include <iostream>
using namespace std;
int *segTree;
int *arr;
int buildSegTree(int low, int high, int i);
int query(int low, int high, int l, int r, int i);
int findMax(int l, int r);
int main()
{
   segTree = new int[800001];
   arr = new int[200001];
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   buildSegTree(0, n - 1, 0);
   /* for (int i = 0; i < n; i++)
   {
      cout << i << "\t";
      for (int j = i; j < n; j++)
      {
         int a = query(0, n - 1, i, j, 0);
         int b = findMax(i, j);
         cout << (a ^ b) << " ";
      }
      cout << endl;
   }
   */
   cout << query(0, n - 1, 2, 1, 0);
   return 0;
}
int findMax(int l, int r)
{
   int Max = -1;
   for (int i = l; i <= r; i++)
   {
      Max = max(Max, arr[i]);
   }
   return Max;
}
int query(int low, int high, int l, int r, int i)
{
   if (l > r)
   {
      return -1;
   }
   if (l == low && r == high)
   {
      return segTree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      if (mid >= l && mid <= r)
      {
         int a, b;
         a = b = -1;
         a = query(low, mid, l, mid, 2 * i + 1);
         b = query(mid + 1, high, mid + 1, r, 2 * i + 2);
         return max(a, b);
      }
      else
      {
         if (r <= mid)
         {
            int a = query(low, mid, l, r, 2 * i + 1);
            return a;
         }
         else
         {
            int a = query(mid + 1, high, l, r, 2 * i + 2);
            return a;
         }
      }
   }
}
int buildSegTree(int low, int high, int i)
{
   if (low > high)
   {
      return -1;
   }
   else if (low == high)
   {
      segTree[i] = arr[low];
   }
   else
   {
      int mid = (low + high) / 2;
      int a = buildSegTree(low, mid, 2 * i + 1);
      int b = buildSegTree(mid + 1, high, 2 * i + 2);
      segTree[i] = max(a, b);
      return segTree[i];
   }
}
