#include <iostream>
#include <string>
using namespace std;
template <class X>
class node
{
public:
   node<X> *next;
   X data;
};
template <class X>
class queue
{
   int count, size;
   node<X> *f, *l, *a, *b, *head;

public:
   queue(int x)
   {
      size = x;
      count = 0;
      f = l = head = NULL;
      head = new node<X>;
      b = head;
      for (int i = 0; i < x - 1; i++)
      {
         a = new node<X>;
         b->next = a;
         b = a;
      }
      b->next = head;
   }
   void nq(X value);
   void dq();
   X peekfront();
   bool isEmpty();
};
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
      count++;
      f = l = head;
      f->data = value;
   }
   else
   {
      count++;
      l = l->next;
      l->data = value;
   }
}
template <class X>
void queue<X>::dq()
{
   if (count == 0)
   {
      cout << "\nQueue is empty";
      return;
   }
   else if (count == 1)
   {
      count = 0;
      f = l = NULL;
      count = 0;
   }
   else
   {
      f = f->next;
      count -= 1;
   }
}
template <class X>
bool queue<X>::isEmpty()
{
   return (count == 0) ? true : false;
}
template <class X>
X queue<X>::peekfront()
{
   X temp;
   if (count == 0)
   {
      cout << "\nQueue is empty";
      return temp;
   }
   else
   {
      temp = f->data;
      return temp;
   }
}
int main()
{
   queue<int> q(30);
   for (int i = 0; i < 30; i++)
   {
      q.nq(1 + i);
   }
   for (int i = 0; i < 35; i++)
   {
      cout << q.peekfront() << " ";
      q.dq();
   }

   return 0;
}