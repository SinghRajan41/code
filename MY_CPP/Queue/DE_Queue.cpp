#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next, *prev;
};
class dequeue
{
   node *f, *l, *head, *a, *b;
   int size;

public:
   dequeue(int x)
   {
      size = x;
      head = new node;
      a = head;
      for (int i = 1; i < x; i++)
      {
         b = new node;
         a->next = b;
         b->prev = a;
         a = b;
      }
      a->next = head;
      head->prev = a;
      f = l = NULL;
   }
   void check()
   {
      a = head;
      while (a)
      {
         cout << a->data << " ";
         a = a->next;
      }
   }
   void insertFront(int value);
   void deleteFront();
   int peekFront();
   void insertLast(int value);
   void deleteLast();
   int peekLast();
   bool isEmpty();
   bool isFull();
};
void maxInWindow(int arr[], int n, int k)
{
   dequeue q(k);
   for (int i = 0; i < k; i++)
   {
      while (!q.isEmpty() && (arr[i] > arr[q.peekLast()]))
      {
         q.deleteLast();
      }
      q.insertLast(i);
   }
   for (int i = k; i < n; i++)
   {
      cout << arr[q.peekFront()] << " ";
      // Removing out of the window elements
      while (!q.isEmpty() && (q.peekFront() <= i - k))
      {
         q.deleteFront();
      }
      // Inserting arr[i] into the queue from back
      while (!q.isEmpty() && (arr[i] > arr[q.peekLast()]))
      {
         q.deleteLast();
      }
      q.insertLast(i);
   }
}
int main()
{
   int n, k;
   cin >> n >> k;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   // maxInWindow(arr, n, k);
   return 0;
}
int dequeue::peekLast()
{
   if (l == NULL)
   {
      cout << "\nDequeue is Empty";
      return -1;
   }
   else
   {
      return l->data;
   }
}
void dequeue::deleteLast()
{
   if (l == NULL)
   {
      cout << "\n Dequeue is Emppty";
   }
   else if (f == l && f != NULL)
   {
      f = l = NULL;
   }
   else
   {
      l = l->prev;
   }
}
void dequeue::insertLast(int value)
{
   if (l == NULL)
   {
      f = l = head;
      l->data = value;
   }
   else if (l->next == f)
   {
      cout << "\nDequeue is full";
      return;
   }
   else
   {
      l = l->next;
      l->data = value;
   }
}
void dequeue::insertFront(int value)
{
   if (f == NULL)
   {
      f = l = head;
      f->data = value;
   }
   else if (f->prev == l)
   {
      cout << "\nDEQUEUE IS FULL ";
      return;
   }
   else
   {
      f = f->prev;
      f->data = value;
   }
}
bool dequeue::isFull()
{
   return (f->prev == l) ? true : false;
}
bool dequeue::isEmpty()
{
   return (f == NULL) ? true : false;
}
int dequeue::peekFront()
{
   if (f == NULL)
   {
      cout << "\nQUEUE IS EMPTY\tRETURNING JUNK ";
      return -1;
   }
   else
   {
      return f->data;
   }
}
void dequeue::deleteFront()
{
   if (f == NULL)
   {
      cout << "\nDEQUEUE IS ALREADY EMPTY ";
   }
   else if (f == l && f != NULL)
   {
      f = l = NULL;
   }
   else
   {
      f = f->next;
   }
}