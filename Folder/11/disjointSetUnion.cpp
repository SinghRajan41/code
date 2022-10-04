#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
   int n;
   int *arr;

public:
   disjointSet()
   {
      n = 100;
      arr = new int[n];
      for (int i = 0; i < n; i++)
      {
         arr[i] = i;
      }
   }
   disjointSet(int x)
   {
      n = x + 1;
      arr = new int[n];
      for (int i = 0; i < n; i++)
      {
         arr[i] = i;
      }
   }
   int find(int x)
   {
      if (arr[x] == x)
      {
         return x;
      }
      else
      {
         return find(arr[x]);
      }
   }
   int Union(int a, int b)
   {
      int x, y;
      x = find(a);
      y = find(b);
      if (x != y)
      {
         arr[x] = y;
      }
   }
};
int main()
{
   disjointSet ds(6);
   int e;
   cin >> e;
   for (int i = 0; i < e; i++)
   {
      int a, b;
      cin >> a >> b;
      ds.Union(a, b);
   }
   for (int i = 1; i <= 6; i++)
   {
      cout << ds.find(i) << " ";
   }
   return 0;
}