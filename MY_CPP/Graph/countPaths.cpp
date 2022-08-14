#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int v, e;
vector<int> *adj;
void insertNode(int x, int y);
void iterDFS(int root);
int countPath(int src, int dest);
void _countPath(int &count, bool visited[], int src, int dest)
{
   visited[src] = 1;
   if (src == dest)
   {
      count++;
   }
   else
   {
      for (int i = 0; i < adj[src].size(); i++)
      {
         if (visited[adj[src][i]] == 0)
         {
            _countPath(count, visited, adj[src][i], dest);
         }
      }
   }
   visited[src] = 0;
}
int main()
{
   cin >> v >> e;
   adj = new vector<int>[v];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(x, y);
   }
   cout << countPath(0, 2);
   return 0;
}
int countPath(int src, int dest)
{
   int count = 0;
   bool visited[v] = {0};
   _countPath(count, visited, src, dest);
   return count;
}
void insertNode(int x, int y)
{
   adj[x].push_back(y);
}
void iterDFS(int root)
{
   bool visited[v] = {0};
   stack<int> s;
   s.push(root);
   visited[root] = 1;
   while (!s.empty())
   {
      int cur = s.top();
      s.pop();
      if (visited[cur] == 1)
      {
         cout << cur << " ";
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (visited[adj[cur][i]] == 0)
         {
            visited[adj[cur][i]] = 1;
            s.push(adj[cur][i]);
         }
      }
   }
}