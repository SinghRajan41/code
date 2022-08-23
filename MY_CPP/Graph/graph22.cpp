#include <iostream>
#include <vector>
using namespace std;
vector<int> *adj;
int v, e;
void inputGraph();
bool detectCycle();
int main()
{
   inputGraph();
   if (detectCycle())
   {
      cout << "\nCycle Detected";
   }
   else
   {
      cout << "\nCycle not Detected";
   }
   return 0;
}
// Detect Cycle in undirected Graph
bool _detectCycle(bool visited[], int cur, int par)
{
   visited[cur] = 1;
   for (int i = 0; i < adj[cur].size(); i++)
   {
      if (visited[adj[cur][i]] == 1 && adj[cur][i] != par)
      {
         return true;
      }
      if (visited[adj[cur][i]] == 0)
      {
         return _detectCycle(visited, adj[cur][i], cur);
      }
   }
   return false;
}
bool detectCycle()
{
   bool visited[v + 1] = {0};
   for (int i = 0; i < v; i++)
   {
      if (visited[i] == 0 && _detectCycle(visited, i, -1))
      {
         return true;
      }
   }
   return false;
}
void inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < v; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}