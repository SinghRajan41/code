#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int *wt;
int v, e;
void inputGraph();
int minTreeDiff();
void evaluateMinSum(bool visited[], int i, int &res, int &curSum, int &sum);
void findTotalSum(int cur, int &sum, bool visited[]);
int main()
{
   inputGraph();
   int minDiff = minTreeDiff();
   cout << minDiff;
   return 0;
}
void findTotalSum(int cur, int &sum, bool visited[])
{
   if (!visited[cur])
   {
      visited[cur] = true;
      sum += wt[cur];
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (!visited[adj[cur][i]])
         {
            findTotalSum(adj[cur][i], sum, visited);
         }
      }
   }
}
int minTreeDiff()
{
   int sum = 0;
   bool visited[v + 1] = {false};
   findTotalSum(0, sum, visited);
   // Utility function to find the sum of all nodes of the tree
   for (int i = 0; i <= v; i++)
   {
      visited[i] = 0;
   }
   int curSum = 0;
   int res = INT32_MAX - 100;
   evaluateMinSum(visited, 0, res, curSum, sum);
   return res;
}
void evaluateMinSum(bool visited[], int i, int &res, int &curSum, int &sum)
{
   if (!visited[i])
   {
      visited[i] = 1;
      curSum += wt[i];
      res = res > (sum - curSum) && sum - curSum != 0 ? sum - curSum : res;
      for (int j = 0; j < adj[i].size(); j++)
      {
         if (!visited[adj[i][j]])
         {
            evaluateMinSum(visited, adj[i][j], res, curSum, sum);
         }
      }
   }
}
void inputGraph()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   wt = new int[v + 1];
   for (int i = 0; i <= v; i++)
   {
      wt[i] = 0;
   }
   int x, y, wx, wy;
   for (int i = 0; i < e; i++)
   {
      cin >> x >> y >> wx >> wy;
      adj[x].push_back(y);
      adj[y].push_back(x);
      wt[x] = wx;
      wt[y] = wy;
   }
}