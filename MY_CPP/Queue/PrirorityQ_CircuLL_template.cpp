#include <iostream>
#include <string>
#include <vector>
using namespace std;
//############   NODE FOR QUEUE    #########
template <class X>
class node
{
public:
   X data;
   node<X> *next;
};
template <class X>
class queue
{
   node<X> *f, *l, *a, *b, *head, *c;
   int size, count;

public:
   queue(int x)
   {
      size = x;
      count = 0;
      f = l = head = NULL;
      head = new node<X>;
      head->next = NULL;
      a = head;
      for (int i = 0; i < size - 1; i++)
      {
         b = new node<X>;
         a->next = b;
         a = b;
      }
      a->next = head;
   }
   queue()
   {
      size = 100;
      count = 0;
      f = l = head = NULL;
      head = new node<X>;
      head->next = NULL;
      a = head;
      for (int i = 0; i < size - 1; i++)
      {
         b = new node<X>;
         a->next = b;
         a = b;
      }
      a->next = head;
   }
   void nq(X value);
   bool isEmpty();
   void dq();
   X peekMax();
   node<X> *findMax();
   void display();
};
template <class X>
void queue<X>::display()
{
   if (!f)
   {
      return;
   }
   else
   {
      a = f;
      while (a != l->next)
      {
         cout << a->data << " ";
         a = a->next;
      }
   }
}
template <class X>
node<X> *queue<X>::findMax()
{
   a = f;
   int maX = INT32_MIN;
   c = a;
   while (a != l->next)
   {
      if (a->data > maX)
      {
         maX = a->data;
         c = a;
      }
      a = a->next;
   }
   return c;
}
template <class X>
void queue<X>::dq()
{
   if (count == 0)
   {

      cout << "\nEmpty queue";
      return;
   }
   else if (count == 1)
   {

      f = l = NULL;
      count = 0;
   }
   else if (count == 2)
   {

      if (l->data > f->data)
      {
         l = f;
      }
      else
      {
         f = l;
      }
      count -= 1;
   }
   else
   {

      node<X> *i = findMax();
      count -= 1;

      if (i == f)
      {
         f = f->next;
      }
      else if (i == l)
      {
         a = f;
         while (a->next != l)
         {
            a = a->next;
         }
         l = a;
      }
      else
      {
         node<X> *cur, *next;
         cur = next = i;
         while (next != l)
         {
            next = cur->next;
            cur->data = next->data;
            cur = next;
         }
      }
   }
}
template <class X>
bool queue<X>::isEmpty()
{
   return (count == 0) ? true : false;
}
template <class X>
void queue<X>::nq(X value)
{
   if (count == size)
   {
      cout << "\nQueue is full";
      return;
   }

   else if (count == 0)
   {
      f = l = head;
      head->data = value;
      count++;
   }
   else
   {
      l = l->next;
      l->data = value;
      count++;
   }
}
int main()
{

   queue<int> q(2100);
   for (int i = 0; i < 2100; i++)
   {
      q.nq(i + 1);
   }
   for (int i = 0; i < 2000; i++)
   {
      cout << int(q.findMax()) << "    ";
      q.dq();
   }

   return 0;
}