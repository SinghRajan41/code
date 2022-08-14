#include <iostream>
#include <queue>
using namespace std;
int main()
{
   int v, e;
   cin >> v >> e;
   bool g[v + 1][v + 1];
   for (int i = 0; i <= v; i++)
   {
      for (int j = 0; j <= v; j++)
      {
         g[i][j] = 0;
      }
   }
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x][y] = 1;
      g[y][x] = 1;
   }
   // Writing code for BFS
   bool visited[v + 1] = {0};
   queue<int> q;
   q.push(1);
   while (!q.empty())
   {
      int cur = q.front();
      q.pop();
      if (visited[cur] == 0)
      {
         visited[cur] = 1;
         cout << cur << " ";
         for (int j = 0; j <= v; j++)
         {
            if (g[cur][j] == 1 && visited[j] == 0)
            {
               q.push(j);
            }
         }
      }
   }
   return 0;
}