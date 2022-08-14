#include <iostream>
#include <vector>
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
}
void insertNode(int u, int v, graph *g)
{
   g->adj[u].push_back(v);
}
void showGraph(graph *g)
{
   for (int i = 0; i < g->v; i++)
   {
      for (int j = 0; j < g->adj[i].size(); j++)
      {
         cout << g->adj[i][j] << " ";
      }
      cout << endl;
   }
}
void dfs(int i, graph *g, bool visited[], int row, vector<vector<bool>> &tc)
{
   if (visited[i] == 0)
   {
      visited[i] = 1;
      tc[row][i] = 1;
      for (int j = 0; j < g->adj[i].size(); j++)
      {
         if (visited[g->adj[i][j]] == 0)
         {
            dfs(g->adj[i][j], g, visited, row, tc);
         }
      }
   }
}
vector<vector<bool>> findTransClosure(graph *g)
{
   vector<bool> temp(g->v, 0);
   vector<vector<bool>> tc;
   for (int i = 0; i < g->v; i++)
   {
      tc.push_back(temp);
   }
   for (int i = 0; i < g->v; i++)
   {
      bool visited[g->v] = {0};
      if (g->adj[i].size() > 0)
      {
         dfs(i, g, visited, i, tc);
      }
      else
      {
         tc[i][i] = 1;
      }
   }
   return tc;
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
   }
   vector<vector<bool>> tc = findTransClosure(g);
   for (int i = 0; i < tc.size(); i++)
   {
      for (int j = 0; j < tc[i].size(); j++)
      {
         cout << tc[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}