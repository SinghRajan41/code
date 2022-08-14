#include <iostream>
#include <vector>
using namespace std;
vector<int> *adj;
int v;
int e;
void insertNode(int x, int y)
{
   adj[x].push_back(y);
}
struct node
{
   int data;
   node *next;
};
node *newNode(int x)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = x;
   return temp;
}
class stack
{
   node *top;

public:
   int peekTop()
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
   void push(int x)
   {
      if (top == NULL)
      {
         top = newNode(x);
      }
      else
      {
         node *a = newNode(x);
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
      else if (top->next == NULL)
      {
         int rvalue = top->data;
         delete top;
         top = NULL;
      }
      else
      {
         int rvalue = top->data;
         node *a = top;
         top = top->next;
         delete a;
         return rvalue;
      }
   }
   bool empty()
   {
      return top == NULL ? true : false;
   }
};
void iterDFS(int root)
{
   bool visited[v + 1] = {0};
   stack s;
   s.push(root);
   visited[root] = 1;
   while (!s.empty())
   {
      root = s.pop();
      if (visited[root] == true)
         cout << root << " ";
      for (int i = 0; i < adj[root].size(); i++)
      {
         if (visited[adj[root][i]] == 0)
         {
            visited[adj[root][i]] = 1;
            s.push(adj[root][i]);
         }
      }
   }
}
int main()
{
   cin >> v >> e;
   adj = new vector<int>[v];
   int i;
   for (i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(x, y);
   }
   iterDFS(0);
   return 0;
}