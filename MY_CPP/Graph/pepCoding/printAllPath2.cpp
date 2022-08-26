#include <iostream>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph()
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
   void printPath(int src, int dest);
   void _printPath(int src, int dest, bool visited[], string path)
   {
      if (src == dest)
      {
         path.append(to_string(src));
         cout << path << endl;
         return;
      }
      visited[src] = true;
      for (int i = 0; i < adj[src].size(); i++)
      {
         if (!visited[adj[src][i]])
         {
            _printPath(adj[src][i], dest, visited, path + to_string(src));
         }
      }
      visited[src] = false;
   }
};
int main()
{
   graph g;
   g.inputGraph();
   int src, dest;
   cin >> src >> dest;
   g.printPath(src, dest);
   return 0;
}
void graph::printPath(int src, int dest)
{
   if (src == dest)
   {
      cout << src;
      return;
   }
   bool visited[v + 1] = {0};
   string path = "";
   _printPath(src, dest, visited, path);
}