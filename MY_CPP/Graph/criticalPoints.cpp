// Given an undirected graph
// Print all the edges which if removed will break the graph into two components
#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
   int v, e;
   vector<int> *adj;
   bool *visited, *ap;
   int *disc, *low;

   void inputGraph();
   void initialise();
   vector<int> articulationPoint();
   void dfs(int u, int par, int &count);
};
bool binSearch(int key, vector<int> &res)
{
   int n = res.size();
   int low = 0;
   int high = n - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (res[mid] == key)
      {
         return true;
      }
      else if (res[mid] > key)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return false;
}
int main()
{
   graph g;
   g.inputGraph();
   vector<int> res = g.articulationPoint();
   for (auto u : res)
   {
      for (auto v : g.adj[u])
      {
         if (binSearch(v, res) && v > u)
         {
            cout << u << " " << v << endl;
         }
      }
   }
   return 0;
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
      if (child >= 2 && par == -1)
      {
         ap[u] = true;
      }
   }
}
vector<int> graph::articulationPoint()
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
   vector<int> res;
   for (int i = 0; i < v; i++)
   {
      if (ap[i])
      {
         res.push_back(i);
      }
   }
   return res;
}
void graph::initialise()
{
   visited = new bool[v];
   ap = new bool[v];
   low = new int[v];
   disc = new int[v];
   for (int i = 0; i < v; i++)
   {
      ap[i] = visited[i] = false;
      low[i] = disc[i] = -1;
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