#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct graph
{
   int v;
   vector<int> *adj;
};
graph *createGraph(int x)
{
   graph *g = new graph;
   g->v = x;
   g->adj = new vector<int>[x];
   return g;
}
void insertNode(int u, int v, graph *g)
{
   g->adj[u].push_back(v);
}
void dfs(int i, graph *g, bool visited[])
{
   if (visited[i] == 0)
   {
      cout << i << " ";
      visited[i] = 1;
      for (int j = 0; j < g->adj[i].size(); j++)
      {
         if (visited[g->adj[i][j]] == 0)
         {
            dfs(g->adj[i][j], g, visited);
         }
      }
   }
}
void KCores(graph *g, int k)
{
   queue<int> q;
   bool visited[g->v] = {0};
   for (int i = 0; i < g->v; i++)
   {
      if (visited[i] == 0)
      {
         fillQ(visited, i, q, g);
      }
   }
}
void fillQ(bool visited[], int i, queue < int < &q, graph *g)
{
   if (visited[i] == 0)
   {
      visited[i] = 1;
      if (g->adj[i].size() < k)
      {
         q.push()
      }
   }
}
int main()
{
   int v, e;
   cin >> v >> e;
   graph *g = createGraph(v);
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(x, y, g);
      insertNode(y, x, g);
   }

   return 0;
}