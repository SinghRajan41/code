#include <iostream>
#include <string>
using namespace std;
class dsu
{
public:
   int n;
   int *par;
   int *size;
   dsu()
   {
      n = 100;
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
      if (x == par[x])
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
      // Always merge the small tree into large tree
      int pa = find(a);
      int pb = find(b);
      if (pa != pb)
      {
         if (size[pa] > size[pb])
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
   int n = 6;
   dsu ds;
   for (int i = 0; i < n; i++)
   {
      int a, b;
      cin >> a >> b;
      ds.Union(a, b);
   }
   for (int i = 1; i <= 8; i++)
   {
      cout << ds.par[i] << " ";
   }
   return 0;
}