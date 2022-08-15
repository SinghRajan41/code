#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// Given a graph
// Print all the paths from source to destination
vector<int> *adj;
int v, e;
void inputGraph();
void printAllPaths(int src, int dest);
void printPath(vector<int> &p);
bool pathIsNotPresent(vector<int> &path, int value);
int main()
{
   inputGraph();
   int x, y;
   cin >> x >> y;
   printAllPaths(x, y);
   return 0;
}
bool nodeIsNotPresent(vector<int> &path, int value)
{
   for (int i = 0; i < path.size(); i++)
   {
      if (path[i] == value)
      {
         return false;
      }
   }
   return true;
}
void printAllPaths(int src, int dest)
{
   if (src == dest)
   {
      cout << src << endl;
      return;
   }

   vector<int> path, temp;
   path.push_back(src);
   queue<vector<int>> q;
   q.push(path);
   while (!q.empty())
   {
      path = q.front();
      q.pop();
      if (path[path.size() - 1] == dest)
      {
         printPath(path);
         continue;
      }
      int cur = path[path.size() - 1];
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (nodeIsNotPresent(path, adj[cur][i]))
         {
            temp = path;
            temp.push_back(adj[cur][i]);
            q.push(temp);
         }
      }
   }
}
void printPath(vector<int> &p)
{
   for (auto i : p)
   {
      cout << i << " ";
   }
   cout << endl;
}
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