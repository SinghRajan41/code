/*
In this task, you need to add to the segment tree the operation of finding the minimum index j such that a[j]≥x.
*/
#include <iostream>
using namespace std;
int arr[200001];
int tree[800004];
int n, m;
int a, b;
int buildTree(int low, int high, int i);
int set(int low, int high, int i, int idx, int val);
int find(int low, int high, int i, int x);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   buildTree(0, n - 1, 0);
   for (; m--;)
   {
      cin >> a;
      if (a == 1)
      {
         cin >> a >> b;
         set(0, n - 1, 0, a, b);
      }
      else
      {
         cin >> b;
         cout << find(0, n - 1, 0, b) << "\n";
      }
   }
   return 0;
}
int find(int low, int high, int i, int x)
{
   if (x > tree[i])
      return -1;
   if (low == high)
      return low;
   else
   {
      int mid = (low + high) / 2;
      int ml = tree[2 * i + 1];
      if (x <= ml)
         return find(low, mid, 2 * i + 1, x);
      else
         return find(mid + 1, high, 2 * i + 2, x);
   }
}
int set(int low, int high, int i, int idx, int val)
{
   if (low == high)
   {
      arr[low] = val;
      tree[i] = val;
      return tree[i];
   }
   else
   {
      int a, b;
      int mid = (low + high) / 2;
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
      tree[i] = a > b ? a : b;
      return tree[i];
   }
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
