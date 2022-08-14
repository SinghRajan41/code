// Print level of every node in a binary tree using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int v, e;
void insertNode(int x, int y);
void printLevel()
{
   queue<int> q, level;
   q.push(0);
   level.push(0);
   int cur, curLevel;
   bool visited[v + 1] = {0};
   while (!q.empty())
   {
      cur = q.front();
      q.pop();
      curLevel = level.front();
      level.pop();
      if (visited[cur] == 0)
      {
         cout << cur << " -> " << curLevel << endl;
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (visited[adj[cur][i]] == 0)
         {
            q.push(adj[cur][i]);
            level.push(curLevel + 1);
         }
      }
   }
}
int main()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(x, y);
   }
   printLevel();
   return 0;
}
void insertNode(int x, int y)
{
   adj[x].push_back(y);
}