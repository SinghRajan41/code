#include <iostream>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<pair<int, int>> *adj;

public:
   void inputGraph();
   void primsAlgo();
   pair<int, int> findNearest(int x, int y, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   g.primsAlgo();
   return 0;
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v];
   for (int i = 0; i < e; i++)
   {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
   }
}
pair<int, int> graph::findNearest(int x, int y, bool visited[])
{
   int cost = INT32_MAX;
   int p, q;
   for (int i = 0; i < adj[x].size(); i++)
   {
      if (!visited[adj[x][i].first] && cost > adj[x][i].second)
      {
         cost = adj[x][i].second;
         p = x;
         q = adj[x][i].first;
      }
   }
   for (int i = 0; i < adj[y].size(); i++)
   {
      if (!visited[adj[y][i].first] && cost > adj[y][i].second)
      {
         cost = adj[y][i].second;
         p = y;
         q = adj[y][i].first;
      }
   }
   return make_pair(p, q);
}
void graph::primsAlgo()
{
   int x, y, cost;
   x = -2;
   y = -2;
   cost = 999999;
   bool visited[v];
   for (int i = 0; i < v; i++)
      visited[i] = false;
   for (int i = 0; i < v; i++)
      for (int j = 0; j < adj[i].size(); j++)
         if (cost > adj[i][j].second)
         {
            cost = adj[i][j].second;
            x = i;
            y = adj[i][j].first;
         }

   visited[x] = visited[y] = true;
   vector<pair<int, int>> res;
   res.push_back(make_pair(x, y));
   for (int i = 0; i < v - 2; i++)
   {
      pair<int, int> p = findNearest(x, y, visited);
      visited[p.first] = visited[p.second] = true;
      res.push_back(p);
      if (x == p.first || x == p.second)
      {
         x = (p.first == x ? p.second : p.first);
      }
      else
      {
         y = (p.first == y ? p.second : p.first);
      }
   }
   for (auto i : res)
   {
      cout << i.first << " " << i.second << endl;
   }
}