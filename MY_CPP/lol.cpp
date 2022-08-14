#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
template <class X>
class node
{
public:
   X data;
   node *next;
   node *prev;
};
template <class Y>
class queue
{
   node<Y> *first, *last, *a, *b;
   int size;

public:
   queue()
   {
      first = NULL;
      last = NULL;
   }
   void nq_front(Y value);
   void nq_back(Y value);
   void dq_front();
   void dq_back();
   void display();
};

// Member Function Definitions
template <class Y>
void queue<Y>::nq_front(Y value)
{
   a = new node<Y>;
   a->data = value;
   if (first == NULL)
   {
      first = a;
      last = a;
      first->next = NULL;
      first->prev = NULL;
   }
   else
   {
      a->next = first;
      first->prev = a;
      first = a;
      first->prev = NULL;
   }
}
template <class Y>
void queue<Y>::dq_front()
{
   if (first == NULL)
   {
      cout << "\nQueue is empty\nReturning from dq_front() function\n";
      return;
   }
   else if (first != NULL && first == last)
   {
      delete first;
      first = NULL;
      last = NULL;
   }
   else
   {
      a = first;
      first = first->next;
      first->prev = NULL;
      delete a;
   }
}
template <class Y>
void queue<Y>::nq_back(Y value)
{
   a = new node<Y>;
   a->data = value;
   if (first == NULL)
   {
      first = a;
      last = a;
      first->next = NULL;
      first->prev = NULL;
   }
   else
   {
      last->next = a;
      a->prev = last;
      last = a;
      a->next = NULL;
   }
}
template <class Y>
void queue<Y>::dq_back()
{
   if (first == NULL)
   {
      cout << "\nQueue is already empty\nReturning from dq_back() function\n";
      return;
   }
   else
   {
      a = last;
      last = last->prev;
      if (!last)
      {
         first = NULL;
      }
      delete a;
   }
}
template <class Y>
void queue<Y>::display()
{
   if (first == NULL)
   {
      cout << "\nQueue is empty\n";
      return;
   }
   else
   {
      a = first;
      cout << a->data << " ";
      a = a->next;
      while (a != NULL)
      {
         cout << a->data << " ";
         a = a->next;
      }
   }
}
int main()
{
   queue<int> q;
   q.nq_front(1);
   q.nq_back(2);
   q.nq_back(21);
   q.dq_front();
   q.nq_back(69);
   q.display();
   return 0;
}