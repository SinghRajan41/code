// Best First Search
// Visit the nodes which have lesser cost first
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e;
vector<pair<int, int>> *adj;
void inputGraph();
class heap
{
public:
   vector<int> *harr;
   int n, size;
   heap()
   {
      harr = new vector<int>[1000];
      n = -1;
      size = 1000;
   }
   void insert(vector<int> value);
   vector<int> peekRoot();
   bool isEmpty();
   void deleteRoot();
   bool isSmaller(vector<int> &a, vector<int> &b);
   void pushDown(int i);
};
void bestFirstSearch(int src, int dest);
void printPath(vector<int> path);
int main()
{
   inputGraph();
   int src, dest;
   cin >> src >> dest;
   bestFirstSearch(src, dest);
   return 0;
}
bool isNotPresent(vector<int> &path, int key)
{
   for (auto i : path)
   {
      if (i == key)
      {
         return false;
      }
   }
   return true;
}
void printPath(vector<int> path)
{
   for (auto i : path)
   {
      cout << i << " ";
   }
   cout << endl;
}
void bestFirstSearch(int src, int dest)
{
   if (src == dest)
   {
      cout << src << endl;
      return;
   }
   heap h; // Used as a priority queue
   vector<int> path, temp;
   path.push_back(src);
   h.insert(path);
   while (!h.isEmpty())
   {
      path = h.peekRoot();
      h.deleteRoot();
      int cur = path[path.size() - 1];
      if (cur == dest)
      {
         printPath(path);
         return;
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (isNotPresent(path, adj[cur][i].second))
         {
            temp = path;
            temp.push_back(adj[cur][i].second);
            h.insert(temp);
         }
      }
   }
}
vector<int> heap::peekRoot()
{
   vector<int> res;
   if (n != -1)
   {
      res = harr[0];
   }
   return res;
}
bool heap::isEmpty()
{
   return n == -1 ? true : false;
}
void heap::pushDown(int i)
{
   int j = 2 * j + 1;
   if (j + 1 <= n && isSmaller(harr[j + 1], harr[j]))
   {
      j++;
   }
   if (j <= n && isSmaller(harr[j], harr[(j - 1) / 2]))
   {
      swap(harr[j], harr[(j - 1) / 2]);
      pushDown(j);
   }
}
void heap::deleteRoot()
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
bool heap::isSmaller(vector<int> &a, vector<int> &b)
{
   int cost1, cost2;
   int x, y;
   x = a[a.size() - 1];
   y = a[a.size() - 2];
   int xx, yy;
   xx = b[b.size() - 1];
   yy = b[b.size() - 2];
   for (int i = 0; i < adj[x].size(); i++)
   {
      if (adj[x][i].second == y)
      {
         cost1 = adj[x][i].first;
      }
   }
   for (int i = 0; i < adj[xx].size(); i++)
   {
      if (adj[xx][i].second == yy)
      {
         cost2 = adj[xx][i].first;
      }
   }
   return cost1 < cost2 ? true : false;
}
void heap::insert(vector<int> value)
{
   if (n == size - 1)
   {
      cout << "\nHeap is Full";
   }
   else
   {
      harr[++n] = value;
      int i = n;
      while (i > 0)
      {
         if (isSmaller(harr[i], harr[(i - 1) / 2]))
         {
            swap(harr[i], harr[(i - 1) / 2]);
         }
         i = (i - 1) / 2;
      }
   }
}
void inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y, cost;
      cin >> x >> y >> cost;
      adj[x].push_back(make_pair(cost, y));
      adj[y].push_back(make_pair(cost, x));
   }
}