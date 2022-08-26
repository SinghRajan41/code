#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Using BFS
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph();
   void insertNode(int x, int y);
   void printPaths(int x, int y);
   void printPath(vector<int> &path);
   bool nodeNotPresent(int key, vector<int> &path);
};
int main()
{
   graph g;
   g.inputGraph();
   g.printPaths(1, 10);
   return 0;
}
bool graph::nodeNotPresent(int key, vector<int> &path)
{
   for (int i = 0; i < path.size(); i++)
   {
      if (path[i] == key)
      {
         return false;
      }
   }
   return true;
}
void graph::printPath(vector<int> &path)
{
   for (int i = 0; i < path.size(); i++)
   {
      cout << path[i] << " ";
   }
   cout << endl;
}
void graph::printPaths(int src, int dest)
{
   if (src == dest)
   {
      cout << src;
      return;
   }
   queue<vector<int>> q;
   vector<int> temp, path;
   path.push_back(src);
   q.push(path);
   while (!q.empty())
   {
      path = q.front();
      q.pop();
      int cur = path[path.size() - 1];
      if (cur == dest)
      {
         printPath(path);
         continue;
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (nodeNotPresent(adj[cur][i], path))
         {
            temp = path;
            temp.push_back(adj[cur][i]);
            q.push(temp);
         }
      }
   }
}
void graph::insertNode(int x, int y)
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
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}