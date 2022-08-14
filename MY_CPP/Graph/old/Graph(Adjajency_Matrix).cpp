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
int main()
{
   cout << "Hello World";
   return 0;
}