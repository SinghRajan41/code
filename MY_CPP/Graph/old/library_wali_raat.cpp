#include <iostream>
#include <vector>
using namespace std;
struct node
{
   int data;
   node *next;
};
class queue
{
   node *first, *last, *a, *b;

public:
   queue()
   {
      first = last = NULL;
   }
   void nq(int value)
   {
      a = new node;
      a->next = NULL;
      a->data = value;
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
   void dq()
   {
      if (first == NULL)
      {
         return;
      }
      else
      {
         a = first;
         first = first->next;
         delete a;
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
   int peekfront()
   {
      if (first == NULL)
      {
         return -1;
      }
      else
      {
         return first->data;
      }
   }
};
class stack
{
   node *top, *a, *b;

public:
   stack()
   {
      top = NULL;
   }
   void push(int value)
   {
      a = new node;
      a->next = NULL;
      a->data = value;
      if (top == NULL)
      {
         top = a;
      }
      else
      {
         a->next = top;
         top = a;
      }
   }
   int pop()
   {
      if (top == NULL)
      {
         return -1;
      }
      else
      {
         int rvalue = top->data;
         a = top;
         top = top->next;
         delete a;
         return rvalue;
      }
   }
   int isEmpty()
   {
      if (top == NULL)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   int peektop()
   {
      if (top == NULL)
      {
         return -1;
      }
      else
      {
         return top->data;
      }
   }
};
class graph
{
   int **g, size;
   bool *visited;

public:
   graph(int n)
   {
      g = new int *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         g[i] = new int[n + 1];
      }
      for (int i = 0; i <= n; i++)
      {
         for (int j = 0; j <= n; j++)
         {
            g[i][j] = 0;
         }
      }
      visited = new bool[n + 1];
      for (int i = 0; i <= n; i++)
      {
         visited[i] = 0;
      }
      size = n;
   }
   void inputGraph(int n, int m)
   {
      int i, j, w;
      for (int z = 0; z < m; z++)
      {
         cin >> i >> j >> w;
         g[i][j] = w;
         cin >> i >> j >> w;
         g[i][j] = w;
      }
   }
   void displayGraph()
   {
      for (int i = 1; i <= size; i++)
      {
         // cout << i << "->";
         for (int j = 1; j <= size; j++)
         {

            cout << g[i][j] << " ";
         }
         cout << endl;
      }
   }
   void bfs(int i, int n)
   {
      for (int i = 0; i <= n; i++)
      {
         visited[i] = 0;
      }
      queue q;
      cout << i << " ";
      q.nq(i);
      visited[i] = 1;
      while (!q.isEmpty())
      {
         int cur = q.peekfront();
         for (int z = 1; z <= n; z++)
         {
            if (visited[z] == 0 && g[cur][z] != 0)
            {
               cout << z << " ";
               visited[z] = 1;
               q.nq(z);
            }
         }
         q.dq();
      }
   }
   void dfs(int i, int n)
   {
      if (visited[i] == 0)
      {
         cout << i << " ";
         visited[i] = 1;
         for (int j = 1; j <= n; j++)
         {
            if (g[i][j] != 0 && visited[j] == 0)
            {
               dfs(j, n);
            }
         }
      }
   }
   void detectCycle(int start, int prev, int n)
   {
      // Initialise visited array
      for (int i = 1; i <= n; ++i)
      {
         visited[i] = 0;
      }
      queue q1, q2;
      q1.nq(start);
      q2.nq(prev);
      int a, b, i;
      while (!q1.isEmpty())
      {
         a = q1.peekfront();
         b = q2.peekfront();
         for (int j = 1; j <= n; j++)
         {
            if (visited[j] == 1 && g[a][j] == 1 &&)
         }
      }
   }
};
int main()
{
   int n, m;
   cin >> n >> m;
   graph g(n);
   g.inputGraph(n, m);
   if (g.detectCylce(1, -1, n))
   {
      cout << "\nCycle Present";
   }
   else
   {
      cout << "\nCycle not present";
   }
   return 0;
}