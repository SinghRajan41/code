/*
This problem is the reversed version of the previous one.
There was a permutation pi of n elements, for each i we wrote down the number ai, the number of j such that j<i and pj>pi.
Restore the original permutation for the given ai.
*/
#include <iostream>
#include <stack>
using namespace std;
int n;
int arr[100001];
int tree[400004];
int buildTree(int low, int high, int i);
int set(int low, int high, int i, int idx, int val);
int KthOne(int low, int high, int i, int k);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   for (int i = 0; i < 400004; i++)
      tree[i] = 1;
   buildTree(0, n - 1, 0);
   stack<int> s;
   for (int i = n - 1; i >= 0; i--)
   {
      int res = KthOne(0, n - 1, 0, arr[i] + 1);
      if (res != -1)
         s.push(res + 1);
      else
         s.push(-1);
      set(0, n - 1, 0, res, 0);
   }
   while (!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
   return 0;
}
int buildTree(int low, int high, int i)
{
   if (low == high)
   {
      tree[i] = 1;
      return tree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      int a = buildTree(low, mid, 2 * i + 1);
      int b = buildTree(mid + 1, high, 2 * i + 2);
      tree[i] = a + b;
      return tree[i];
   }
}
int KthOne(int low, int high, int i, int k)
{
   if (k > tree[i])
   {
      return -1;
   }
   if (low == high)
      return low;
   else
   {
      int mid = (low + high) / 2;
      int ro = tree[2 * i + 2];
      if (k <= ro)
         return KthOne(mid + 1, high, 2 * i + 2, k);
      else
         return KthOne(low, mid, 2 * i + 1, k - ro);
   }
}
int set(int low, int high, int i, int idx, int val)
{
   if (idx > high)
      return -1;
   if (low == high)
   {
      // int diff = val - tree[i];
      tree[i] = 0;
      return -1;
   }
   else
   {
      int mid = (low + high) / 2;
      int a;
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