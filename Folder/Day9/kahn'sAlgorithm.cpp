#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
class graph
{
public:
   int v, e;
   vector<int> *adj;
   void inputGraph();
   void kahnAlgo();
   void topoSort();
   void dfs(int i, stack<int> &s, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   g.kahnAlgo();
   cout << endl;
   g.topoSort();
   return 0;
}
void graph::dfs(int i, stack<int> &s, bool visited[])
{
   if (!visited[i])
   {
      visited[i] = true;
      for (int j = 0; j < adj[i].size(); j++)
      {
         dfs(adj[i][j], s, visited);
      }
      s.push(i);
   }
}
void graph::topoSort()
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
         dfs(i, s, visited);
      }
   }
   while (!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[e];
   for (int i = 0; i < e; i++)
   {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
   }
}
void graph::kahnAlgo()
{
   vector<int> arr(v, 0);
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         arr[adj[i][j]] += 1;
      }
   }
   queue<int> q, res;
   for (int i = 0; i < v; i++)
   {
      if (!arr[i])
      {
         q.push(i);
      }
   }
   while (!q.empty())
   {
      int cur = q.front();
      q.pop();
      res.push(cur);
      for (int i = 0; i < adj[cur].size(); i++)
      {
         arr[adj[cur][i]] -= 1;
         if (arr[adj[cur][i]] == 0)
         {
            q.push(adj[cur][i]);
         }
      }
   }
   if (res.size() == v)
   {
      while (!res.empty())
      {
         cout << res.front() << " ";
         res.pop();
      }
   }
   else
   {
      cout << "\nThe given graph is not directed acyclic\n";
   }
}