#include <iostream>
#include <vector>
using namespace std;
vector<int> buildSegSumTree(int arr[], int n);
int query(vector<int> &segTree, int low, int high, int l, int r, int i);
int update(vector<int> &segTree, int idx, int newVal, int low, int high, int i);
int Sum(int arr[], int l, int r);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   vector<int> segTree = buildSegSumTree(arr, n);
   update(segTree, 1, 10, 0, n - 1, 0);
   arr[1] = 10;
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         int a, b;
         a = Sum(arr, i, j);
         b = query(segTree, 0, n - 1, i, j, 0);
         cout << (a ^ b) << endl;
      }
   }
   return 0;
}
int update(vector<int> &segTree, int idx, int newVal, int low, int high, int i)
{
   if (idx > high || idx < low)
   {
      return 0;
   }
   if (idx == low && idx == high)
   {
      int a = newVal - segTree[i];
      segTree[i] = newVal;
      return a;
   }
   else
   {
      int mid = (low + high) / 2;
      int a = 0;
      if (idx <= mid)
      {
         a = update(segTree, idx, newVal, low, mid, 2 * i + 1);
         segTree[i] += a;
         return a;
      }
      else
      {
         a = update(segTree, idx, newVal, mid + 1, high, 2 * i + 2);
         segTree[i] += a;
         return a;
      }
   }
}

int Sum(int segTree[], int l, int r)
{
   int res = 0;
   for (int i = l; i <= r; i++)
   {
      res += segTree[i];
   }
   return res;
}
int _buildSegSumTree(int arr[], int low, int high, int i, vector<int> &segTree)
{
   if (low > high)
   {
      return 0;
   }
   else if (low == high)
   {
      segTree[i] = arr[low];
      return segTree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      int a = 0, b = 0;
      a = _buildSegSumTree(arr, low, mid, 2 * i + 1, segTree);
      b = _buildSegSumTree(arr, mid + 1, high, 2 * i + 2, segTree);
      segTree[i] = a + b;
      return segTree[i];
   }
}
int query(vector<int> &segTree, int low, int high, int l, int r, int i)
{
   if (l > r)
   {
      return 0;
   }
   else if (l == low && r == high)
   {
      return segTree[i];
   }
   else
   {
      int mid = (low + high) / 2;
      int a, b;
      a = b = 0;
      if (mid >= l && mid <= r)
      {
         a = query(segTree, low, mid, l, mid, 2 * i + 1);
         b = query(segTree, mid + 1, high, mid + 1, r, 2 * i + 2);
         return a + b;
      }
      else
      {
         if (r <= mid)
         {
            a = query(segTree, low, mid, l, r, 2 * i + 1);
            return a;
         }
         else
         {
            a = query(segTree, mid + 1, high, l, r, 2 * i + 2);
            return a;
         }
      }
   }
}
vector<int> buildSegSumTree(int arr[], int n)
{
   int size;
   if (!(n & (n - 1)))
   {
      size = 2 * n - 1;
   }
   else
   {
      size = 1;
      int x = n;
      while (x > 0)
      {
         size <<= 1;
         x >>= 1;
      }
      size = 2 * size - 1;
   }
   vector<int> segTree(size, -1);
   _buildSegSumTree(arr, 0, n - 1, 0, segTree);
   return segTree;
}