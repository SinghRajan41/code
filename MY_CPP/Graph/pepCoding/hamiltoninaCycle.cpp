#include <iostream>
#include <vector>
#include <string>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph();
   void addNode(int x, int y);
   void hamilCycle(int src);
   void _hamiltonianCycle(int cur, bool visited[], int count, string path, int root);
};
int main()
{
   graph g;
   g.inputGraph();
   g.hamilCycle(0);
   return 0;
}
void graph::_hamiltonianCycle(int cur, bool visited[], int count, string path, int root)
{

   visited[cur] = true;
   path += to_string(cur);
   count++;
   if (count == v)
   {
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (adj[cur][i] == root)
         {
            cout << path << endl;
            visited[cur] = false;
            return;
         }
      }
   }
   for (int i = 0; i < adj[cur].size(); i++)
   {
      if (!visited[adj[cur][i]])
      {
         _hamiltonianCycle(adj[cur][i], visited, count, path, root);
      }
   }
   visited[cur] = false;
}
void graph::hamilCycle(int src)
{
   bool visited[v + 1] = {0};
   string path = "";
   int count = 0;
   _hamiltonianCycle(0, visited, count, path, src);
}
void graph::addNode(int x, int y)
{
   adj[x].push_back(y);
   adj[y].push_back(x);
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      addNode(x, y);
   }
}