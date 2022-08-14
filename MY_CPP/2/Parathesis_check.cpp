#include <iostream>
using namespace std;
template <class X>
class node
{
public:
   X data;
   node<X> *next;
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
   X peektop();
   bool isEmpty();
};

template <class X>
void stack<X>::push(X value)
{
   a = new node<X>;
   a->data = value;
   a->next = NULL;
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
X stack<X>::pop()
{
   X junk;
   if (top != NULL)
   {
      junk = top->data;
      a = top;
      top = top->next;
      delete a;
   }
   return junk;
}
template <class X>
bool stack<X>::isEmpty()
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
X stack<X>::peektop()

{
   return top->data;
}
int main()
{
   return 0;
}