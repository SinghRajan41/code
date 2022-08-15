// Height of generic tree from parent array
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int heightFromPArr(int parr[], int n);
int main()
{
   int n;
   cin >> n;
   int parr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> parr[i];
   }
   cout << heightFromPArr(parr, n);
   return 0;
}
int heightFromPArr(int parr[], int n)
{
   int root;
   for (int i = 0; i < n; i++)
   {
      if (parr[i] == -1)
      {
         root = i;
         break;
      }
   }
   vector<int> adj[n + 1];
   for (int i = 0; i < n; i++)
   {
      if (parr[i] != -1)
      {
         adj[parr[i]].push_back(i);
      }
   }
   // Perform a BFS and find the height of the tree
   queue<int> q;
   queue<int> level;
   level.push(0);
   q.push(root);
   int curLevel;
   bool visited[n + 1] = {0};
   visited[root] = 1;
   int res = -1;
   while (!q.empty())
   {
      root = q.front();
      curLevel = level.front();
      res = res > curLevel ? res : curLevel;
      q.pop();
      level.pop();
      for (int i = 0; i < adj[root].size(); i++)
      {
         if (visited[adj[root][i]] == 0)
         {
            q.push(adj[root][i]);
            level.push(curLevel + 1);
         }
      }
   }
   return res;
}