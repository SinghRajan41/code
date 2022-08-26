#include <iostream>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph();
   bool hasPath(int src, int dest);
   bool _hasPath(int src, int dest, bool visited[]);
};
// The function hasPath finds whether a path exists betwenn source and destination
// using DFS
int main()
{
   graph g;
   g.inputGraph();
   int src, dest;
   cin >> src >> dest;
   if (g.hasPath(src, dest))
   {
      cout << "\nPath Exist";
   }
   else
   {
      cout << "\nPath doesn't exist";
   }
   return 0;
}
bool graph::_hasPath(int src, int dest, bool visited[])
{
   if (src == dest)
   {
      return true;
   }
   visited[src] = true;
   for (int i = 0; i < adj[src].size(); i++)
   {
      if (!visited[adj[src][i]])
      {
         if (_hasPath(adj[src][i], dest, visited))
         {
            return true;
         }
      }
   }
   return false;
}
bool graph::hasPath(int src, int dest)
{
   bool visited[v + 1] = {0};
   return _hasPath(src, dest, visited);
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}