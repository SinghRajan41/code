#include <iostream>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<vector<int>> g;

public:
   void inputGraph();
   void primAlgo();
   pair<int, int> nearestPair(int u, int v, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   g.primAlgo();
   return 0;
}
pair<int, int> graph::nearestPair(int p, int q, bool visited[])
{
   int cost = INT32_MAX;
   int x = -1, y = -1;
   for (int i = 1; i <= v; i++)
   {
      if (g[p][i] != -1 && !visited[i] && g[p][i] < cost)
      {
         cost = g[p][i];
         x = p;
         y = i;
      }
   }
   for (int i = 1; i <= v; i++)
   {
      if (g[q][i] != -1 && !visited[i] && g[q][i] < cost)
      {
         cost = g[q][i];
         x = q;
         y = i;
      }
   }
   pair<int, int> r = {x, y};
   return r;
}
void graph::primAlgo()
{
   bool visited[v + 1];
   for (int i = 0; i <= v; i++)
   {
      visited[i] = false;
   }
   vector<pair<int, int>> res;
   int cost = INT32_MAX;
   int x, y;
   for (int i = 1; i <= v; i++)
   {
      for (int j = 1; j <= v; j++)
      {
         if (g[i][j] != -1 && g[i][j] < cost)
         {
            cost = g[i][j];
            x = i;
            y = j;
         }
      }
   }
   visited[x] = visited[y] = true;
   res.push_back(make_pair(x, y));
   int temp = v - 2;
   int first, second;
   first = x;
   second = y;
   while (temp--)
   {
      pair<int, int> nearPair = nearestPair(first, second, visited);
      if (nearPair.first == first)
      {
         first = nearPair.second;
      }
      else
      {
         second = nearPair.second;
      }
      visited[nearPair.first] = visited[nearPair.second] = true;
      res.push_back(nearPair);
   }
   cout << endl
        << endl;
   for (auto p : res)
   {
      cout << p.first << " " << p.second << endl;
   }
}
void graph::inputGraph()
{
   cin >> v >> e;
   for (int i = 0; i <= v; i++)
   {
      vector<int> temp(v + 1, -1);
      g.push_back(temp);
   }
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      g[x][y] = w;
      g[y][x] = w;
   }
}
/*
6 8
1 2 5
1 6 10
2 6 15
2 3 10
3 6 25
6 5 20
4 5 15
3 4 10

*/