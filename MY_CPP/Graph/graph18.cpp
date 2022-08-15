/*Given an undirected tree with some marked nodes and a positive number K.
We need to print the count of all such nodes which have
distance from all marked nodes less than or equal to K that means every node whose distance
from all marked nodes is less than or equal to K, should be counted in the result.*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e;
vector<int> *adj;
void inputGraph();
int countKDist(int marked[], int k, int d);
void bfsMark(int node, int d, int freq[], bool visited[]);
int main()
{
   inputGraph();
   int k;
   cin >> k;
   int marked[k];
   for (int i = 0; i < k; i++)
   {
      cin >> marked[i];
   }
   int d;
   cin >> d;
   cout << countKDist(marked, k, d);
   return 0;
}
void bfsMark(int node, int d, int freq[], bool visited[])
{
   visited[node] = 1;
   queue<int> q;
   queue<int> level;
   q.push(node);
   level.push(0);
   while (!q.empty())
   {
      int cur = q.front();
      int curLevel = level.front();
      q.pop();
      level.pop();
      if (curLevel <= d && cur != node)
      {
         freq[cur]++;
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (visited[adj[cur][i]] == 0)
         {
            level.push(curLevel + 1);
            q.push(adj[cur][i]);
            visited[adj[cur][i]] = 1;
         }
      }
   }
}
int countKDist(int marked[], int k, int d)
{
   int freq[v + 1] = {0};
   for (int i = 0; i < k; i++)
   {
      bool visited[v + 1] = {0};
      bfsMark(marked[i], d, freq, visited);
   }
   int count = 0;
   for (int i = 0; i < v + 1; i++)
   {
      if (freq[i] = k)
      {
         count++;
      }
   }
   return count;
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