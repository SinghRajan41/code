/*
A permutation p of n elements is given.
 You need to find for each element the number of inversions:
 the number of elements to the left, which are greater.
*/
#include <iostream>
using namespace std;
int n;
int arr[100001];
int tree[400004];
int buildTree(int low, int high, int i);
int query(int low, int high, int i, int l, int r);
int set(int low, int high, int i, int idx, int val);
int main()
{
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   for (int i = 0; i < 400004; i++)
      tree[i] = 0;
   for (int i = 0; i < n; i++)
   {
      cout << query(0, n - 1, 0, arr[i], n - 1) << " ";
      set(0, n - 1, 0, arr[i] - 1, 1);
   }
   return 0;
}
int set(int low, int high, int i, int idx, int val)
{
   if (low == high && low == idx)
   {
      tree[i] = 1;
      return 1;
   }
   else
   {
      int mid = (low + high) / 2;
      int a = 0;
      if (idx <= mid)
      {
         a = set(low, mid, 2 * i + 1, idx, val);
      }
      else
      {
         a = set(mid + 1, high, 2 * i + 2, idx, val);
      }
      tree[i] += a;
      return a;
   }
}
int query(int low, int high, int i, int l, int r)
{
   if (l > r)
      return 0;
   if (l == low && high == r)
      return tree[i];
   else
   {
      int mid = (low + high) / 2;
      if (r <= mid)
      {
         // Segment is completely in left
         return query(low, mid, 2 * i + 1, l, r);
      }
      else if (l > mid)
      {
         // Segment is completely in right
         return query(mid + 1, high, 2 * i + 2, l, r);
      }
      else
      {
         // Intersecting segment
         int a, b;
         a = b = 0;
         a = query(low, mid, 2 * i + 1, l, mid);
         b = query(mid + 1, high, 2 * i + 2, mid + 1, r);
         return a + b;
      }
   }
}