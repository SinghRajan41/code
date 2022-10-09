#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class graph
{
   int v, e;
   vector<pair<int, int>> *adj;

public:
   void inputGraph();
   void connectCities();
   pair<int, int> findMinimumCostEdge(int x, int y, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   cout << "\nInput Done\n";
   g.connectCities();
   return 0;
}
pair<int, int> graph::findMinimumCostEdge(int x, int y, bool visited[])
{
   int p, q, cost;
   cost = INT32_MAX;
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
void graph::connectCities()
{
   int x, y, cost;
   vector<pair<int, int>> res;
   cost = INT32_MAX;
   bool visited[v];
   memset(visited, false, v);
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         if (cost > adj[i][j].second)
         {
            cost = adj[i][j].second;
            x = i;
            y = adj[i][j].first;
         }
      }
   }
   res.push_back(make_pair(x, y));
   visited[x] = visited[y] = true;
   int k = v - 2;
   for (int i = 0; i < k; i++)
   {
      pair<int, int> p = findMinimumCostEdge(x, y, visited);
      res.push_back(p);
      visited[p.first] = visited[p.second] = true;
      if (x == p.first || x == p.second)
      {
         x = (x == p.first ? p.second : p.first);
      }
      else if (y == p.first || y == p.second)
      {
         y = (y == p.first ? p.second : p.first);
      }
   }
   for (auto i : res)
   {
      cout << i.first << " " << i.second << " " << endl;
   }
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v];
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back(make_pair(y, w));
      adj[y].push_back(make_pair(x, w));
   }
}