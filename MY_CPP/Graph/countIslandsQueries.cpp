#include <bits/stdc++.h>
using namespace std;
// Given NxN matrix consiting of zeros and q queuries of the form (row,column)
// For each qeury mark given rwo and column in the matrix as one
// And then find the number of groups consisting of ones for each query
int *parent, n, q;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void initialise();
void printIslands(vector<pair<int, int>> queries, int q);
bool valid(int r, int c);
int find(int x);
bool Union(int a, int b);
void printIslands(vector<pair<int, int>> queries, int q);
vector<vector<int>> a, b;
int main()
{
   cin >> n >> q;
   initialise();
   vector<pair<int, int>> queries;
   for (int i = 0; i < q; i++)
   {
      int x, y;
      cin >> x >> y;
      queries.push_back(make_pair(x, y));
   }
   printIslands(queries, q);

   return 0;
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
bool Union(int a, int b)
{
   int pa = find(a);
   int pb = find(b);
   if (pa != pb)
   {
      parent[pb] = pa;
      return true;
   }
   return false;
}
bool valid(int r, int c)
{
   return (r >= 0 && c >= 0 && r < n && c < n);
}
void printIslands(vector<pair<int, int>> queries, int q)
{
   int groups = 0;
   for (int i = 0; i < q; i++)
   {
      int r, c;
      r = queries[i].first;
      c = queries[i].second;
      a[r][c] = 1;
      groups += 1;
      for (int i = 0; i < 4; i++)
      {
         int rnew, cnew;
         rnew = r + dirs[i][0];
         cnew = c + dirs[i][1];
         if (valid(rnew, cnew))
         {
            if (a[rnew][cnew] == 1)
            {
               if (Union(b[r][c], b[rnew][cnew]))
               {
                  groups--;
               }
            }
         }
      }
      cout << groups << endl;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cout << a[i][j] << " ";
         }
         cout << endl;
      }
      cout << endl
           << endl;
   }
}
void initialise()
{
   parent = new int[n * n + 1];
   for (int i = 0; i < n * n + 1; i++)
   {
      parent[i] = i;
   }
   for (int i = 0; i < n; i++)
   {
      vector<int> temp(n, 0);
      a.push_back(temp);
      b.push_back(temp);
   }
   int count = 1;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         a[i][j] = 0;
         b[i][j] = count++;
      }
   }
}