#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
node *newNode(int x);
node *insert(int value, node *x);
int main()
{
   int v, e;
   cin >> v >> e;
   node **g;
   g = new node *[v + 1];
   for (int i = 0; i < v + 1; i++)
   {
      g[i] = NULL;
   }
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x] = insert(y, g[x]);
      g[y] = insert(x, g[y]);
   }
   for (int i = 1; i < v + 1; i++)
   {
      node *temp = g[i];
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }
      cout << endl;
   }
   return 0;
}
node *insert(int value, node *x)
{
   node *a = x;
   if (x == NULL)
   {
      return newNode(value);
   }
   while (x->next != NULL && x->data != value)
   {
      // This function doesn't duplicate values to be inserted
      x = x->next;
   }
   if (x->data == value)
   {
      return a;
   }
   else
   {
      x->next = newNode(value);
   }
   return a;
}
node *newNode(int x)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = x;
   return temp;
}