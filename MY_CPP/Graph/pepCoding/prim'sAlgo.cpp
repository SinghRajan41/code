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
   cout << "\nInputDone";
   g.primAlgo();
   return 0;
}
pair<int, int> graph::nearestPair(int u, int v, bool visited[])
{
   int cost = INT32_MAX;
   int x, y;
   for (int i = 1; i <= v; i++)
   {
      if (g[u][i] != -1 && !visited[i] && g[u][i] < cost)
      {
         cost = g[u][i];
         x = u;
         y = i;
      }
   }
   for (int i = 1; i <= v; i++)
   {
      if (g[v][i] != -1 && !visited[i] && g[v][i] < cost)
      {
         cost = g[v][i];
         x = v;
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
   while (temp--)
   {
      int u, v;
      u = res[res.size() - 1].first;
      v = res[res.size() - 1].second;
      pair<int, int> nearPair = nearestPair(u, v, visited);
      visited[nearPair.first] = visited[nearPair.second] = true;
      res.push_back(nearPair);
   }
   cout << res.size() << endl;
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