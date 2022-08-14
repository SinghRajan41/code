#include <iostream>
#include <vector>
using namespace std;
class stack
{
   int arr[1000], top;

public:
   stack()
   {
      top = -1;
   }
   void push(int value);
   int pop();
   int isEmpty();
   int peekTop();
};
bool **g = NULL;
bool *visited;
void stack::push(int value)
{
   if (top == 1000)
   {
      cout << "\nStack OverFlow\n";
      return;
   }
   else
   {
      arr[++top] = value;
   }
}
int stack::isEmpty()
{
   if (top < 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int stack::pop()
{
   if (top == -1)
   {
      return -1;
   }
   else
   {
      int rvalue = arr[top];
      top -= 1;
      return rvalue;
   }
}
int stack::peekTop()
{
   if (top < 0)
   {
      return -1;
   }
   else
   {
      return arr[top];
   }
}
void initialise(int n)
{
   g = new bool *[n + 1];
   visited = new bool[n + 1];
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
   visited = new bool[n + 1];
   for (int i = 0; i <= n; i++)
   {
      visited[i] = 0;
   }
}
void display(int n)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         if (g[i][j] == 1)
         {
            cout << j << " ";
         }
      }
      cout << endl;
   }
}
void graphInput(int n)
{
   int temp;
   for (int i = 1; i <= n; i++)
   {
      vector<int> q;
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
void dfs(int y, int n);
int main()
{
   int n;
   cin >> n;
   initialise(n);
   graphInput(n);
   dfs(2, n);
   return 0;
}
void dfs(int i, int n)
{
   if (visited[i] == 0)
   {
      cout << i << " ";
      visited[i] = 1;
      for (int j = 1; j <= n; j++)
      {
         if (g[i][j] == 1 && visited[j] == 0)
         {
            dfs(j, n);
         }
      }
   }
}
