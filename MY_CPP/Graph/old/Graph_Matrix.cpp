#include <iostream>
#include <vector>
using namespace std;
#define X INT32_MAX
struct node
{
   node *next;
   int parent, child;
};
class queue
{
   node *first, *last, *a, *b;

public:
   queue()
   {
      first = last = NULL;
   }
   void nq(node value)
   {
      a = new node;
      *a = value;
      a->next = NULL;
      if (first == NULL)
      {
         first = last = a;
      }
      else
      {
         last->next = a;
         last = a;
      }
   }
   int isEmpty()
   {
      if (first == NULL)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   void dq()
   {
      if (first == NULL)
      {
         return;
      }
      else if (first == last && first != NULL)
      {
         delete first;
         first = last = NULL;
      }
      else
      {
         a = first;
         first = first->next;
         delete a;
      }
   }
   node *peekfront()
   {
      if (first == NULL)
      {
         cout << "Returning junk node\n";
         a = new node;
         return a;
      }
      else
      {
         return first;
      }
   }
};
class graph
{
   int **g, size, flag, *near, **t, k, e, *edges[3], *s;
   bool *visited, *included;

public:
   graph(int n, int m)
   {
      k = 0;
      size = n;
      e = m;
      g = new int *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         g[i] = new int[n + 1];
      }
      visited = new bool[n + 1];
      for (int i = 0; i <= n; i++)
      {
         visited[i] = 0;
      }
      for (int i = 0; i <= n; i++)
      {
         for (int j = 0; j <= n; j++)
         {
            g[i][j] = X;
         }
      }
      included = new bool[e];
      for (int i = 0; i < e; i++)
      {
         included[i] = 0;
      }
      near = new int[n + 1];
      t = new int *[2];
      t[0] = new int[n + 1];
      t[1] = new int[n + 1];
      for (int i = 0; i < 3; i++)
      {
         edges[i] = new int[e];
      }
      s = new int[e + 1];
      for (int i = 0; i <= e; i++)
      {
         s[i] = -1;
      }
   }
   void primsAlgo();
   void setFlag()
   {
      flag = 0;
   }
   int getFlag()
   {
      return flag;
   }
   void displayEdges()
   {
      for (int i = 0; i < e; i++)
      {
         cout << edges[0][i] << " " << edges[1][i] << " " << edges[2][i] << endl;
      }
   }
   void inputGraph(int n, int m)
   {
      int i, j, w;
      e = m;
      for (int z = 0; z < m; z++)
      {
         cin >> i >> j >> w;
         g[i][j] = w;
         g[j][i] = w;
         edges[0][z] = i;
         edges[1][z] = j;
         edges[2][z] = w;
      }
   }
   void displayGraph()
   {
      for (int i = 1; i <= size; i++)
      {
         for (int j = 1; j <= size; j++)
         {
            cout << g[i][j] << " ";
         }
         cout << endl;
      }
   }
   void setVisited()
   {
      for (int i = 0; i <= size; i++)
      {
         visited[i] = 0;
      }
   }
   int find_parent(int x)
   {
      while (s[x] > 0)
      {
         x = s[x];
      }
      return x;
   }
   void Myunion(int x, int y)
   {
      if (s[x] < s[y])
      {
         s[x] += s[y];
         s[y] = x;
      }
      else
      {
         s[y] += s[x];
         s[x] = y;
      }
   }
   int detectCycleBFS(int i, int n)
   {
      queue q;
      node a;
      a.next = NULL;
      a.child = i;
      a.parent = -1;
      visited[i] = 1;
      q.nq(a);
      while (!q.isEmpty())
      {
         node *b = q.peekfront();
         int cur, par;
         cur = b->child;
         par = b->parent;
         for (int j = 1; j <= size; j++)
         {
            if (visited[j] == 0 && g[cur][j] != 0)
            {
               // Visit the node and nq in the queue
               visited[j] = 1;
               node c;
               c.next = NULL;
               c.parent = cur;
               c.child = j;
               q.nq(c);
            }
            else if (visited[j] == 1 && g[cur][j] != 0 && par != j)
            {
               return 1;
            }
         }
         q.dq();
      }
      return 0;
   }

   void detectCycleDFS(int cur, int par)
   {
      // Continue from here
      if (visited[cur] == 0)
      {
         visited[cur] = 1;
         for (int i = 1; i <= size; i++)
         {
            if (g[cur][i] != 0 && visited[i] == 1 && par != i)
            {
               flag++;
               return;
            }
            else if (visited[i] == 0 && g[cur][i] != 0)
            {
               detectCycleDFS(i, cur);
            }
         }
      }
   }
   void kruskal_algo()
   {
      vector<pair<int, int>> t;
      int y = 0;
      while (y < size - 1)
      {
         // Find minimum cost edge
         int cost = X, u, v, k;
         for (int i = 0; i < e; i++)
         {
            if (edges[2][i] < cost && included[i] == 0)
            {
               cost = edges[2][i];
               u = edges[0][i];
               v = edges[1][i];
               k = i;
            }
         }
         included[k] = 1;
         if (find_parent(u) != find_parent(v))
         {
            t.push_back(make_pair(u, v));
            Myunion(find_parent(u), find_parent(v));
            y++;
         }
      }
      for (int i = 0; i < t.size(); i++)
      {
         cout << t[i].first << " " << t[i].second << endl;
      }
   }
};

int main()
{
   int n, m;
   cin >> n >> m;
   graph g(n, m);
   g.inputGraph(n, m);
   g.kruskal_algo();
   return 0;
}
void graph::primsAlgo()
{

   vector<pair<int, int>> V;
   int x, y, u, v, cost, k = 0, n;
   for (int i = 1; i <= size; i++)
   {
      for (int j = 1; j <= size; j++)
      {
         if (cost > g[i][j])
         {
            cost = g[i][j];
            u = i;
            v = j;
         }
      }
   }
   t[0][k] = u;
   t[1][k] = v;
   k++;
   n = size - 2;
   cout << u << " " << v << endl;
   while (n--)
   {
      // Update the near array
      for (int temp = 0; temp < k; temp++)
      {
         near[t[0][temp]] = near[t[1][temp]] = 0;
      }
      u = t[0][k - 1];
      v = t[1][k - 1];
      for (int i = 1; i <= size; i++)
      {
         if (near[i] != 0)
         {

            if (g[i][u] < g[i][v])
            {
               near[i] = u;
            }
            else
            {
               near[i] = v;
            }
         }
      }
      // Near array updated
      cost = X;
      for (int i = 1; i <= size; i++)
      {
         if (near[i] != 0)
         {
            if (cost > g[i][near[i]])
            {
               cost = g[i][near[i]];
               x = i;
               y = near[i];
            }
         }
      }
      cout << x << " " << y << endl;
      if (u == x)
      {
         t[0][k] = v;
         t[1][k] = y;
      }
      else if (u == y)
      {
         t[0][k] = v;
         t[1][k] = x;
      }
      else if (v == x)
      {
         t[0][k] = u;
         t[1][k] = y;
      }
      else if (v == y)
      {
         t[0][k] = u;
         t[1][k] = x;
      }
      k++;
   }
}
// 7 9 1 6 5 6 1 5 1 2 25 2 1 25 6 5 20 5 6 20 5 7 18 7 5 18 7 2 10 2 7 10 4 5 16 5 4 16 4 3 8 3 4 8 2 3 12 3 2 12 4 7 14 7 4 14
// 4 6 1 2 3 2 1 3 2 3 101 3 2 101 3 4 101 4 3 101 1 4 101 4 1 101 1 3 4 3 1 4 2 4 103 4 2 103