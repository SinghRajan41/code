#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
class graph
{
   int v, e;
   vector<int> *adj;

public:
   void inputGraph();
   bool isBipartite();
   bool _isBipartite(int cur, int visited[]);
   bool isCyclic();
   bool _isCyclic(int src, int visited[]);
   bool isCyclicDFS();
   bool _isCyclicDFS(int src, bool visited[], bool path[]);
   void iterativeDFS();
   void _iterativeDFS(int src, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   g.iterativeDFS();
   return 0;
}
void graph::iterativeDFS()
{
   bool visited[v];
   for (int i = 0; i < v; i++)
   {
      visited[i] = false;
   }
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         _iterativeDFS(i, visited);
      }
   }
}
void graph::_iterativeDFS(int cur, bool visited[])
{
   stack<int> s;
   s.push(cur);
   while (!s.empty())
   {
      cur = s.top();
      s.pop();
      if (!visited[cur])
      {
         cout << cur << " ";
         visited[cur] = true;
         for (int i = 0; i < adj[cur].size(); i++)
         {
            s.push(adj[cur][i]);
         }
      }
   }
}
bool graph::_isCyclicDFS(int src, bool visited[], bool path[])
{
   visited[src] = path[src] = true;
   for (int i = 0; i < adj[src].size(); i++)
   {
      if (path[adj[src][i]])
      {
         return true;
      }
      if (!visited[adj[src][i]] && _isCyclicDFS(adj[src][i], visited, path))
      {
         return true;
      }
   }
   path[src] = false;
   return false;
}
bool graph::isCyclicDFS()
{
   bool visited[v];
   bool path[v];
   for (int i = 0; i < v; i++)
   {
      visited[i] = path[i] = false;
   }
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         if (_isCyclicDFS(i, visited, path))
         {
            return true;
         }
      }
   }
   return false;
}
bool graph::_isCyclic(int cur, int visited[])
{
   queue<int> q;
   q.push(cur);
   while (!q.empty())
   {
      int a = q.front();
      q.pop();
      if (visited[a] != -1)
      {
         return true;
      }
      else
      {
         visited[a] = 1;
         for (int i = 0; i < adj[a].size(); i++)
         {
            if (visited[adj[a][i]] == -1)
            {
               q.push(adj[a][i]);
            }
         }
      }
   }
   return false;
}
bool graph::isCyclic()
{
   int visited[v] = {-1};
   for (int i = 0; i < v; i++)
   {
      visited[i] = -1;
   }
   for (int i = 0; i < v; i++)
   {
      if (visited[i] == -1)
      {
         if (_isCyclic(i, visited))
         {
            return true;
         }
      }
   }
   return false;
}
bool graph::isBipartite()
{
   int visited[v] = {-1};
   for (int i = 0; i < v; i++)
   {
      visited[i] = -1;
   }
   for (int i = 0; i < v; i++)
   {
      if (visited[i] == -1)
      {
         if (_isBipartite(i, visited) == false)
         {
            return false;
         }
      }
   }
   return true;
}
bool graph::_isBipartite(int cur, int visited[])
{
   if (adj[cur].size() == 0)
   {
      return false;
   }
   queue<pair<int, int>> q;
   q.push(make_pair(cur, 0));
   while (!q.empty())
   {
      pair<int, int> curPair = q.front();
      q.pop();
      if (visited[curPair.first] == -1)
      {
         visited[curPair.first] = curPair.second;
      }
      else
      {
         // This pair has already been visited
         if (visited[curPair.first] != curPair.second)
         {
            return false;
         }
      }
      cur = curPair.first;
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (visited[adj[cur][i]] == -1)
         {
            q.push(make_pair(adj[cur][i], curPair.second + 1));
         }
      }
   }
   return true;
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