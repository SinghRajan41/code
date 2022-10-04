#include <iostream>
#include <string>
#include <vector>
using namespace std;
// TestCase present at LeetCode 959
class dsu
{
   vector<vector<int>> a;
   int *parent;
   int n;

public:
   dsu(int x)
   {
      // Always give x as n+1
      n = x;
      for (int i = 0; i < n; i++)
      {
         vector<int> temp(n, 0);
         a.push_back(temp);
      }
      int count = 1;
      parent = new int[n * n + 1];
      for (int i = 0; i < n; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            a[i][j] = parent[count] = count;
            ++count;
         }
      }
   }
   bool Union(int a, int b)
   {
      int pa = find(a);
      int pb = find(b);
      if (pa != pb)
      {
         parent[pa] = pb;
         return true;
      }
      return false;
   }
   int get(int i, int j)
   {
      return a[i][j];
   }
   int find(int x)
   {
      if (parent[x] == x)
      {
         return x;
      }
      else
      {
         int temp = find(parent[x]);
         parent[x] = temp;
         return temp;
      }
   }
};
int regionBySlashes(string &grid);
int main()
{
   // cout << regionBySlashes(grid);
   return 0;
}
int regionBySlashes(vector<string> &grid)
{
   int n = grid.size();
   int count = 1;
   dsu d(n + 1);
   for (int i = 0; i <= n; i++)
   {
      int a;
      a = d.get(0, i);
      d.Union(1, a);
      a = d.get(i, 0);
      d.Union(1, a);
      a = d.get(n, i);
      d.Union(1, a);
      a = d.get(i, n);
      d.Union(1, a);
   }

   for (int i = 0; i < n; i++)
   {
      string temp = grid[i];
      for (int j = 0; j < n; j++)
      {
         int c = (int)(temp[j]);
         if (c == 32)
         {
            continue;
         }
         else if (c == 92)
         {
            int a, b;
            a = d.get(i, j);
            b = d.get(i + 1, j + 1);
            if (!d.Union(a, b))
            {
               count++;
            }
         }
         else if (c == 47)
         {
            int a, b;
            a = d.get(i, j + 1);
            b = d.get(i + 1, j);
            if (!d.Union(a, b))
            {
               count++;
            }
         }
      }
   }
   return count;
}