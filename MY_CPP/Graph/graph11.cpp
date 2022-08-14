#include <iostream>
#include <vector>
// Count the number of trees in a forest
using namespace std;
vector<int> *adj;
int v, e;
void insertNode(int x, int y);
int countTrees();
void dfs(bool visited[], int i);
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
   cout << countTrees();
   return 0;
}
void dfs(bool visited[], int i)
{
   if (visited[i] == 0)
   {
      visited[i] = 1;
      for (int j = 0; j < adj[i].size(); j++)
      {
         if (visited[adj[i][j]] == 0)
         {
            dfs(visited, adj[i][j]);
         }
      }
   }
}
int countTrees()
{
   int count = 0;
   bool visited[v] = {0};
   for (int i = 0; i < v; i++)
   {
      if (visited[i] == 0)
      {
         dfs(visited, i);
         count++;
      }
   }
   return count;
}
void insertNode(int x, int y)
{
   adj[x].push_back(y);
}