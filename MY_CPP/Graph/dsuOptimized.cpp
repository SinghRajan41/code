#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
   int n;
   int *par;
   int *size;

   disjointSet()
   {
      n = 101;
      par = new int[n];
      size = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         size[i] = 1;
      }
   }
   disjointSet(int x)
   {
      n = x;
      par = new int[n];
      size = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         size[i] = 1;
      }
   }
   int find(int x)
   {
      if (par[x] == x)
      {
         return x;
      }
      else
      {
         int temp = find(par[x]);
         par[x] = temp;
         return temp;
      }
   }
   void Union(int a, int b)
   {
      int pa, pb;
      pa = find(a);
      pb = find(b);
      if (pa != pb)
      {
         if (size[pa] < size[pb])
         {
            swap(pa, pb);
         }
         par[pa] = pb;
         size[pb] += size[pa];
      }
   }
};
int main()
{
   disjointSet ds(7);
   for (int i = 0; i < 4; i++)
   {
      int x, y;
      cin >> x >> y;
      ds.Union(x, y);
   }
   for (int i = 1; i <= 7; i++)
   {
      cout << ds.par[i] << " ";
   }
   return 0;
}