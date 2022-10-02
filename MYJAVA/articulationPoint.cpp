
#include <bits/stdc++.h>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;
   bool *visited;
   int *disc, *low;
   bool *ap;

public:
   void inputGraph();
   void initialise()
   {
      visited = new bool[v];
      disc = new int[v];
      low = new int[v];
      ap = new bool[v];
      for (int i = 0; i < v; i++)
      {
         visited[i] = ap[i] = false;
         disc[i] = low[i] = -1;
      }
   }
   void printArticulation();
   void dfs(int u, int par, int &count);
};
int main()
{
   graph g;
   g.inputGraph();
   g.printArticulation();
   return 0;
}
void graph::printArticulation()
{
   initialise();
   int count = 0;
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         dfs(i, -1, count);
      }
   }
   for (int i = 0; i < v; i++)
   {
      if (ap[i])
      {
         cout << i << " ";
      }
   }
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}
void graph::dfs(int u, int par, int &count)
{
   if (!visited[u])
   {
      visited[u] = true;
      low[u] = disc[u] = count++;
      int child = 0;
      for (auto v : adj[u])
      {
         if (!visited[v])
         {
            dfs(v, u, count);
            child++;
            low[u] = min(low[u], low[v]);
            if (par != -1 && low[v] >= disc[u])
            {
               ap[u] = true;
            }
         }
         else if (par != v)
         {
            low[u] = min(low[u], disc[v]);
         }
      }
      if (par == -1 && child >= 2)
      {
         ap[u] = true;
      }
   }
}
