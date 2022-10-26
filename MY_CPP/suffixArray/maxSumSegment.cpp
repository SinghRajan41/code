/*
Now we consider the problem of finding a segment with a maximum sum.
Our data structure must support two operations on the array:
set(i, v): set the element with index i to v.
max_segment(): find the segment of the array with the maximum sum.
//Highly Optimized 800ms -> 180 ms
*/
#include <iostream>
using namespace std;
int arr[100001];
int M = 100001;
struct node
{
   long long int seg;
   long long int pref;
   long long int suff;
   long long int sum;
};
node tree[400004];
int n, m;
node buildTree(int i, int low, int high);
node set(int i, int low, int high, int idx, int val);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   int idx, val;
   for (register int i = 0; i < n; i++)
      cin >> arr[i];
   buildTree(0, 0, n - 1);
   cout << (tree[0].seg < 0ll ? 0 : tree[0].seg) << "\n";
   for (register int i = 0; i < m; i++)
   {

      cin >> idx >> val;
      set(0, 0, n - 1, idx, val);
      cout << (tree[0].seg < 0ll ? 0 : tree[0].seg) << "\n";
   }
   return 0;
}
node set(int i, int low, int high, int idx, int val)
{
   node res;
   if (low == high && low == idx)
   {
      res = {val, val, val, val};
      tree[i] = res;
      return res;
   }
   else
   {
      int mid = (low + high) / 2;
      node a, b;
      if (idx <= mid)
      {
         a = set(2 * i + 1, low, mid, idx, val);
         b = tree[2 * i + 2];
      }
      else
      {
         b = set(2 * i + 2, mid + 1, high, idx, val);
         a = tree[2 * i + 1];
      }
      res.sum = a.sum + b.sum;
      res.seg = (a.seg > b.seg ? a.seg : b.seg) > a.suff + b.pref ? (a.seg > b.seg ? a.seg : b.seg) : a.suff + b.pref;
      res.suff = (b.suff > b.sum + a.suff ? b.suff : b.sum + a.suff);
      res.pref = (a.pref > a.sum + b.pref ? a.pref : a.sum + b.pref);
      tree[i] = res;
      return res;
   }
}
node buildTree(int i, int low, int high)
{
   node res;
   if (low == high)
   {
      res = {arr[low], arr[low], arr[low], arr[low]};
      tree[i] = res;
      return res;
   }
   else
   {
      int mid = (low + high) / 2;
      node a, b;
      a = buildTree(2 * i + 1, low, mid);
      b = buildTree(2 * i + 2, mid + 1, high);
      res.sum = a.sum + b.sum;
      res.seg = (a.seg > b.seg ? a.seg : b.seg) > a.suff + b.pref ? (a.seg > b.seg ? a.seg : b.seg) : a.suff + b.pref;
      res.suff = (b.suff > b.sum + a.suff ? b.suff : b.sum + a.suff);
      res.pref = (a.pref > a.sum + b.pref ? a.pref : a.sum + b.pref);
      tree[i] = res;
      return res;
   }
}