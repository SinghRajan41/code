#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
// Count the number of strongly connected components in a given directed graph
class graph
{
   int v, e;
   vector<pair<int, int>> *adj;

public:
   void inputGraph();
   int kosaraju();
   void dfs(int cur, bool visited[], stack<int> &s);
   void dfs2(int cur, bool visited[], vector<pair<int, int>> adj[]);
};
int main()
{
   graph g;
   g.inputGraph();
   cout << g.kosaraju();
   return 0;
}
void graph::dfs(int cur, bool visited[], stack<int> &s)
{
   if (!visited[cur])
   {
      visited[cur] = true;
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (!visited[adj[cur][i].first])
         {
            dfs(adj[cur][i].first, visited, s);
         }
      }
      s.push(cur);
   }
}
void graph::dfs2(int cur, bool visited[], vector<pair<int, int>> adj[])
{
   if (!visited[cur])
   {
      visited[cur] = true;
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (!visited[adj[cur][i].first])
         {
            dfs2(adj[cur][i].first, visited, adj);
         }
      }
   }
}
int graph::kosaraju()
{
   int count = 0;
   stack<int> s;
   // Filling the stack
   bool visited[v];
   memset(visited, false, v);
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         dfs(i, visited, s);
      }
   }
   // Creating a new adjajency list with reverse edges
   vector<pair<int, int>> rev[v];
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         rev[adj[i][j].first].push_back(make_pair(i, adj[i][j].second));
      }
   }
   memset(visited, false, v);
   while (!s.empty())
   {
      int cur = s.top();
      s.pop();
      if (!visited[cur])
      {
         dfs2(cur, visited, rev);
         count++;
      }
   }
   return count;
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v];
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back(make_pair(y, w));
   }
}
/*
11 13
0 1 0
1 2 0
2 3 0
3 0 0
3 4 0
4 5 0
5 6 0
6 7 0
7 4 0
7 8 0
8 10 0
10 9 0
9 8 0
*/