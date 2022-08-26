#include <iostream>
#include <vector>
#include <string>
using namespace std;
class graph
{
   int v, e;
   vector<vector<int>> adj;

public:
   void inputGraph();
   void addNode(int x, int y);
   void printShortest(int src, int dest);
   void _printShortest(int src, int dest, int &minWt, int curWt, string path, string &resPath, bool visited[]);
   void printLargest(int src, int dest);
   void _printLargest(int src, int dest, int curWt, int maxWt, string curPath, string &resPath, bool visited[]);
};
int main()
{
   graph g;
   g.inputGraph();
   int src, dest;
   cin >> src >> dest;
   g.printLargest(src, dest);
   return 0;
}
void graph::_printLargest(int src, int dest, int curWt, int maxWt, string curPath, string &resPath, bool visited[])
{
   if (src == dest)
   {
      if (curWt > maxWt)
      {
         maxWt = curWt;
         resPath = curPath;
      }
      return;
   }
   visited[src] = true;
   for (int i = 0; i <= v; i++)
   {
      if (adj[src][i] != -1)
      {
         if (!visited[i])
         {
            _printLargest(i, dest, curWt + adj[src][i], maxWt, curPath + to_string(src), resPath, visited);
         }
      }
   }
   visited[src] = false;
}
void graph::printLargest(int src, int dest)
{
   if (src == dest)
   {
      cout << src;
      return;
   }
   int curWt = 0;
   int maxWt = INT32_MIN;
   string curPath = "";
   string resPath = "";
   bool visited[v + 1] = {0};
   _printShortest(src, dest, curWt, maxWt, curPath, resPath, visited);
   cout << resPath << dest << endl;
}
void graph::printShortest(int src, int dest)
{
   if (src == dest)
   {
      cout << src;
      return;
   }
   string path = to_string(src);
   int curWt = 0;
   string resPath = "";
   int minWt = INT32_MAX;
   bool visited[v + 1] = {0};
   _printShortest(src, dest, minWt, curWt, path, resPath, visited);
   cout << resPath;
   return;
}
void graph::_printShortest(int src, int dest, int &minWt, int curWt, string path, string &resPath, bool visited[])
{
   if (src == dest)
   {
      if (minWt > curWt)
      {
         minWt = curWt;
         resPath = path;
      }
      return;
   }
   visited[src] = true;
   for (int i = 0; i <= v; i++)
   {
      if (adj[src][i] != -1)
      {
         if (!visited[i])
         {
            _printShortest(i, dest, minWt, curWt + adj[src][i], path + to_string(i), resPath, visited);
         }
      }
   }
   visited[src] = false;
}
void graph::inputGraph()
{
   cin >> v >> e;
   for (int i = 0; i <= v; i++)
   {
      vector<int> temp(v + 1, -1);
      adj.push_back(temp);
   }
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x][y] = w;
      adj[y][x] = w;
   }
}