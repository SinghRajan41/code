#include <iostream>
using namespace std;
int n, m, a, b;
int set(int low, int high, int i, int idx, int val);
int arr[200005];
int tree[800020];
int buildSegTree(int low, int high, int i);
int KthOne(int low, int high, int i, int k); // Correct
int KthOne_end(int low, int high, int i, int k);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for (int i = 0; i < n; ++i)
      cin >> arr[i];
   buildSegTree(0, n - 1, 0);
   while (m--)
   {
      cin >> a >> b;
      if (a == 2)
      {
         cout << KthOne_end(0, n - 1, 0, b + 1) << "\n";
      }
      else
      {
         arr[b] = 1 - arr[b];
         set(0, n - 1, 0, b, arr[b]);
      }
   }
   return 0;
}
int KthOne_end(int low, int high, int i, int k)
{
   if (k > tree[i])
      return -1;
   if (low == high)
      return low;
   else
   {
      int mid = (low + high) / 2;
      int ro = tree[2 * i + 2];
      if (k <= ro)
         return KthOne_end(mid + 1, high, 2 * i + 2, k);
      else
         return KthOne_end(low, mid, 2 * i + 1, k - ro);
   }
}
int KthOne(int low, int high, int i, int k)
{
   if (k > tree[i])
      return -1;
   if (low == high)
      return low;
   else
   {
      int mid = (low + high) / 2;
      if (k > tree[2 * i + 1])
         return KthOne(mid + 1, high, 2 * i + 2, k - tree[2 * i + 1]);
      else
         return KthOne(low, mid, 2 * i + 1, k);
   }
}
int set(int low, int high, int i, int idx, int val)
{
   if (low > high)
      return 0;
   if (low == high && low == idx)
   {
      int rvalue = val - tree[i];
      tree[i] = val;
      return rvalue;
   }
   else
   {
      int mid = (low + high) / 2;
      int a, b;
      a = b = 0;
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
int buildSegTree(int low, int high, int i)
{
   if (low > high)
      return 0;
   else if (low == high)
   {
      tree[i] = arr[low];
      return tree[i];
   }
   else
   {
      int a, b, mid;
      a = b = 0;
      mid = (low + high) / 2;
      a = buildSegTree(low, mid, 2 * i + 1);
      b = buildSegTree(mid + 1, high, 2 * i + 2);
      tree[i] = a + b;
      return tree[i];
   }
}