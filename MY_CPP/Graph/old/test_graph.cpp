#include <iostream>
#include <vector>
using namespace std;
//###########################################################################################################################
template <class Y>
class node
{
public:
   node *next;
   Y data;
};
template <class X>
class stack
{
   node<X> *top, *a, *b, *c;

public:
   stack()
   {
      top = NULL;
   }
   void push(X value);
   X pop();
   int isEmpty();
   X peektop();
};
template <class X>
int stack<X>::isEmpty()
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
template <class X>
void stack<X>::push(X value)
{
   a = new node<X>;
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
template <class X>
X stack<X>::peektop()
{
   if (top == NULL)
   {
      X junk;
      cout << "\nStack is empty\nReturning junk\n";
      return junk;
   }
   else
   {
      return top->data;
   }
}
template <class X>
X stack<X>::pop()
{
   if (top == NULL)
   {
      X junk;
      return junk;
   }
   else
   {
      X rvalue = top->data;
      a = top;
      top = top->next;
      delete a;
      return rvalue;
   }
}
template <class X>
class queue
{
   node<X> *first, *last, *a, *b;

public:
   queue()
   {
      first = last = NULL;
   }
   int isEmpty();
   void nq(X value);
   void dq();
   X peekfront();
};
template <class X>
void queue<X>::dq()
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
template <class X>
X queue<X>::peekfront()
{
   if (first == NULL)
   {
      X junk;
      cout << "\nReturning junk\n";
      return junk;
   }
   else
   {
      return first->data;
   }
}
template <class X>
void queue<X>::nq(X value)
{
   a = new node<X>;
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
template <class X>
int queue<X>::isEmpty()
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
//###########################################################################################################################
template <class X>
class graph
{
   node<X> **g = NULL, *a, *b;
   bool *visited;
   int size;

public:
   graph(int n)
   {
      size = n;
      visited = new bool[n + 1];
      for (int i = 0; i <= n; i++)
      {
         visited[i] = 0;
      }
      g = new node<X> *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         g[i] = NULL;
      }
   }
   void graphDisplay();
   void graphInput(int m);
   void bfs(int i, int n);
   void dfs(int i, int n);
   void emptyVisited();
};
template <class X>
void graph<X>::emptyVisited()
{
   for (int i = 0; i <= size; i++)
   {
      visited[i] = 0;
   }
}
template <class X>
void graph<X>::dfs(int i, int n)
{
   if (visited[i] == 0 && g[i] != NULL)
   {
      cout << i << " ";
      visited[i] = 1;
      a = g[i];
      while (a)
      {
         if (visited[a->data] != 1)
         {
            dfs(a->data, n);
         }
         a = a->next;
      }
   }
}
template <class X>
void graph<X>::bfs(int i, int n)
{
   // Writng a code for bfs
   queue<X> q;
   // Initialising the visited array
   for (int i = 0; i <= n; i++)
   {
      visited[i] = 0;
   }
   // Now visiting the starting node
   cout << i << " ";
   visited[i] = 1;
   q.nq(i);
   while (!q.isEmpty())
   {
      X cur = q.peekfront();
      if (g[cur] != NULL)
      {
         a = g[cur];
         while (a)
         {
            if (visited[a->data] == 0)
            {
               cout << a->data << " ";
               visited[a->data] = 1;
               q.nq(a->data);
            }
            a = a->next;
         }
      }
      q.dq();
   }
}
template <class X>
void graph<X>::graphDisplay()
{
   for (int i = 1; i <= size; i++)
   {
      cout << i << "->";
      if (g[i] != NULL)
      {
         a = g[i];
         while (a)
         {
            cout << a->data << " ";
            a = a->next;
         }
      }
      cout << endl;
   }
}
template <class X>
void graph<X>::graphInput(int m)
{
   for (int i = 0; i < m; i++)
   {
      int idx;
      X j;
      cin >> idx >> j;
      // creating a new node
      a = new node<X>;
      a->next = NULL;
      a->data = j;
      if (g[idx] == NULL)
      {
         g[idx] = a;
      }
      else if (g[idx]->next == NULL)
      {
         g[idx]->next = a;
      }
      else
      {
         b = g[idx];
         while (b->next != NULL)
         {
            b = b->next;
         }
         b->next = a;
      }
      // Part 2
      cin >> idx >> j;
      // creating a new node
      a = new node<X>;
      a->next = NULL;
      a->data = j;
      if (g[idx] == NULL)
      {
         g[idx] = a;
      }
      else if (g[idx]->next == NULL)
      {
         g[idx]->next = a;
      }
      else
      {
         b = g[idx];
         while (b->next != NULL)
         {
            b = b->next;
         }
         b->next = a;
      }
   }
}
int main()
{
   int n, m;
   cin >> n >> m;
   graph<int> g(n);
   g.graphInput(m);
   g.emptyVisited();
   g.bfs(1, n);
   return 0;
}
