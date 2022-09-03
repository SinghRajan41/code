#include <iostream>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<vector<int>> g;

public:
   void inputGraph()
   {
      cin >> v >> e;
      for (int i = 0; i <= v; i++)
      {
         vector<int> temp(v + 1, -1);
         g.push_back(temp);
      }
      for (int i = 0; i < e; i++)
      {
         int x, y, w;
         cin >> x >> y >> w;
         g[x][y] = g[y][x] = w;
      }
   }
   void dijkstra(int src);
};
class priorityQueue
{
public:
   pair<int, int> *harr;
   int size, n;
   priorityQueue()
   {
      size = 2500;
      harr = new pair<int, int>[size];
      n = -1;
   }
   void insert(pair<int, int> value)
   {
      harr[++n] = value;
      int i = n;
      while (i > 0)
      {
         if (harr[i].second < harr[(i - 1) / 2].second)
         {
            swap(harr[i], harr[(i - 1) / 2]);
         }
         i = (i - 1) / 2;
      }
   }
   int length()
   {
      return n + 1;
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
   pair<int, int> peekRoot()
   {
      return n == -1 ? harr[0] : harr[n];
   }
   void pushDown(int i)
   {
      int j = 2 * i + 1;
      if (j + 1 <= n && harr[j].second > harr[j + 1].second)
      {
         j++;
      }
      if (j <= n && harr[j].second < harr[(j - 1) / 2].second)
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
      }
   }
   void deleteRoot()
   {
      if (n == -1)
      {
         return;
      }
      else if (n == 0)
      {
         n--;
      }
      else
      {
         swap(harr[0], harr[n]);
         n--;
         pushDown(0);
      }
   }
};
int main()
{
   graph g;
   g.inputGraph();
   g.dijkstra(0);
   return 0;
}
void graph::dijkstra(int src)
{
   priorityQueue pq;
   pq.insert(make_pair(src, 0));
   int dist[v];
   for (int i = 0; i < v; i++)
   {
      dist[i] = INT32_MAX;
   }
   dist[src] = 0;
   while (!pq.empty())
   {
      pair<int, int> curNode = pq.peekRoot();
      pq.deleteRoot();
      int node = curNode.first;
      int wsf = curNode.second;
      for (int i = 0; i < v; i++)
      {
         if (g[node][i] != -1)
         {
            if (wsf + g[node][i] < dist[i])
            {
               dist[i] = wsf + g[node][i];
               pq.insert(make_pair(i, dist[i]));
            }
         }
      }
   }
   cout << endl;
   for (int i = 0; i < v; i++)
   {
      cout << i << " -> " << dist[i] << endl;
   }
}