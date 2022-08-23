// Detect Cycle in Directed Graph
// Run a DFS for every node
// if the DFS returns to the starting node return true
#include <vector>
#include <iostream>
using namespace std;
class graph
{
public:
   vector<int> *adj;
   int v, e;
   void inputGraph();
   void insertNode(int x, int y);
   bool DFS();
   bool _detectCycle(int root, bool visited[], int cur);
};
int main()
{
   graph g;
   g.inputGraph();
   bool arr[g.v + 1] = {0};
   if (g._detectCycle(0, arr, 0))
   {
      cout << "\nCycle Detected";
   }
   else
   {
      cout << "\nCycle not detected";
   }
   return 0;
}
bool graph::_detectCycle(int root, bool visited[], int cur)
{
   visited[cur] = 1;
   for (int i = 0; i < adj[cur].size(); i++)
   {
      if (root == adj[cur][i])
      {
         return true;
      }
      if (visited[adj[cur][i]] == 0 && _detectCycle(root, visited, adj[cur][i]))
      {
         return true;
      }
   }
   return false;
}
bool graph::DFS()
{
   bool visited[v + 1] = {0};
   for (int i = 0; i < v; i++)
   {
      if (visited[i] == 0)
      {
         bool arr[v + 1] = {0};
         if (_detectCycle(i, arr, i))
         {
            return true;
         }
      }
   }
   return false;
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < v; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
   }
}