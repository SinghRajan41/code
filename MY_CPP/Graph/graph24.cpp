#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class graph
{
public:
   vector<int> *adj;
   int v, e;
   void inputGraph();
   void addNode(int x, int y);
   bool findCycle();
   bool _findCycle(int cur, bool visited[], bool path[]);
};
int main()
{
   graph g;
   g.inputGraph();
   if (g.findCycle())
   {
      cout << "\nCycle Detected";
   }
   else
   {
      cout << "\nCycle not detected";
   }
   return 0;
}
bool graph::_findCycle(int cur, bool visited[], bool path[])
{
   visited[cur] = path[cur] = true;
   for (int i = 0; i < adj[cur].size(); i++)
   {
      if (path[adj[cur][i]])
      {
         return true;
      }
      if (!visited[adj[cur][i]])
      {
         return _findCycle(adj[cur][i], visited, path);
      }
   }
   path[cur] = false;
   return false;
}
bool graph::findCycle()
{
   bool path[v + 1] = {0};
   bool visited[v + 1] = {0};
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         if (_findCycle(i, visited, path))
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
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
   }
}