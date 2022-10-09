#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph()
   {
      cin >> v >> e;
      adj = new vector<int>[v];
      for (int i = 0; i < e; i++)
      {
         int x, y;
         cin >> x >> y;
         adj[x].push_back(y);
      }
   }
   void topologicalSort();
   void dfs(int i, bool visited[], stack<int> &s);
};
void graph::topologicalSort()
{
   stack<int> s;
   bool visited[v];
   for (int i = 0; i < v; i++)
   {
      visited[i] = false;
   }
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         dfs(i, visited, s);
      }
   }
   while (!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
}
void graph::dfs(int i, bool visited[], stack<int> &s)
{
   if (!visited[i])
   {
      visited[i] = true;
      for (int j = 0; j < adj[i].size(); j++)
      {
         dfs(adj[i][j], visited, s);
      }
      s.push(i);
   }
}
int main()
{
   graph g;
   g.inputGraph();
   g.topologicalSort();
   return 0;
}