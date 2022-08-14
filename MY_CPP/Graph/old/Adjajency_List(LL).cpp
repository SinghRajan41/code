#include <iostream>
#include <vector>
using namespace std;
struct node
{
   int data;
   node *next;
};
class graph
{
   node **arr, size;

public:
   graph(int n)
   {
      arr = new node *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         arr[i] = NULL;
      }
      size = n;
   }
   void input();
   void display();
   void graphInsert(int pos, int value);
};
void graph::display()
{
   for (int i = 1; i <= size; i++)
   {
      if (arr[i] != NULL)
      {
         node *a = arr[i];
         while (a != NULL)
         {
            cout << a->data << " ";
            a = a->next;
         }
         cout << endl;
      }
   }
}
void graphInsert(int pos, int value)
{
   node *temp = new node;
   temp->data = value;
   temp->next = NULL;
   if (arr[pos] == NULL)
   {
      arr[pos] = temp;
   }
   else
   {
      node *a = arr[pos];
      while (a->next != NULL)
      {
         a = a->next;
      }
      a->next = temp;
   }
}
void graph::input()
{
   int temp;
   for (int i = 1; i <= size; i++)
   {
      cin >> temp;
      while (temp != -1)
      {
         graphInsert(i, temp);
         cin >> temp;
      }
   }
}
int main()
{
   cout << "Enter the number of elements in the graph=";
   int n;
   cin >> n;
   graph g(n);
   g.input();
   g.display();
   return 0;
}