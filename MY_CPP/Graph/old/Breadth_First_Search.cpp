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
   node *first, *last, *a, *b, *c;

public:
   queue()
   {
      first = last = NULL;
   }
   void nq(int value);
   void dq();
   int peekfront();
   int isEmpty();
   void display();
};
bool **g = NULL;
bool *visited = NULL;
void display(int n)
{
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         if (g[i][j] == 0)
         {
            cout << 0 << " ";
         }
         else
         {
            cout << 1 << " ";
         }
      }
      cout << endl;
   }
}
void initialise(int n)
{
   g = new bool *[n + 1];
   visited = new bool[n + 1];
   for (int i = 0; i <= n; i++)
   {
      visited[i] = 0;
   }
   for (int i = 0; i <= n; i++)
   {
      g[i] = new bool[n + 1];
   }
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         g[i][j] = 0;
      }
   }
}
void queue::dq()
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
void queue::display()
{
   a = first;
   while (a != NULL)
   {
      cout << a->data << " ";
      a = a->next;
   }
}
int queue::isEmpty()
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
int queue::peekfront()
{
   if (first == NULL)
   {
      cout << "\nQueueu is empty\nreturning -1\n";
      return -1;
   }
   else
   {
      return first->data;
   }
}
void queue::nq(int value)
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
void graphInput(int n)
{
   for (int i = 1; i <= n; i++)
   {
      vector<int> q;
      int temp;
      cin >> temp;
      while (temp != -1)
      {
         q.push_back(temp);
         cin >> temp;
      }
      for (int j = 0; j < q.size(); j++)
      {
         g[i][q[j]] = 1;
      }
   }
}
void bfs(int y, int n)
{
   queue q;
   q.nq(y);
   visited[y] = 1;
   cout << y << " ";
   while (!q.isEmpty())
   {
      int cur = q.peekfront();
      for (int i = 1; i <= n; i++)
      {
         if (g[cur][i] == 1 && visited[i] != 1)
         {
            cout << i << " ";
            visited[i] = 1;
            q.nq(i);
         }
      }
      q.dq();
   }
}
void dfs(int i,int n)
{
   
}
int main()
{
   int n;
   cin >> n;
   initialise(n);
   graphInput(n);
   bfs(5, n);
   return 0;
}