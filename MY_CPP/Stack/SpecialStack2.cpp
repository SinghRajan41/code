// This special support getMiddle() and deleteMiddle(), pop(), push() and standard stack operations in O(1) time complexity
// The idea is to use a doubly linked list and maitain a middle pointer
#include <iostream>
using namespace std;
struct node
{
   int data;
   node *prev, *next;
};
class stack
{
   node *top, *mid, *a, *b;
   int size, count;

public:
   stack()
   {
      top = mid = NULL;
      size = count = 0;
   }
   void push(int value);
   int pop();
   bool isEmpty();
   int peektop();
   int getMiddle();
   void deleteMiddle();
};
int main()
{
   stack s;
   s.push(1);
   s.push(2);
   s.push(4);
   s.push(5);
   s.deleteMiddle();
   cout << s.getMiddle();

   return 0;
}
int stack::pop()
{
   int x;
   if (top == NULL)
   {
      return -1;
   }
   else if (size == 1)
   {
      x = top->data;
      delete top;
      top = mid = NULL;
      size = 0;
   }
   else if (size == 2)
   {
      mid = top->prev;
      a = top;
      top = top->prev;
      x = top->data;
      delete a;
      size -= 1;
      top->next = NULL;
      return x;
   }
   else
   {
      a = top;
      x = top->data;
      top = top->prev;
      if (size % 2 == 0)
      {
         mid = mid->prev;
      }
      size -= 1;
      delete a;
      return x;
   }
}
void stack::deleteMiddle()
{
   if (size == 0)
   {
      return;
   }
   else if (size == 1)
   {
      delete top;
      top = mid = NULL;
      size -= 1;
   }
   else if (size == 2)
   {
      mid = top->prev;
      a = top;
      top = top->prev;
      size -= 1;
      top->next = NULL;
      delete a;
   }
   else
   {
      mid->prev->next = mid->next;
      mid->next->prev = mid->prev;
      a = mid;
      if (size % 2)
      {
         mid = mid->next;
      }
      else
      {
         mid = mid->prev;
      }
      delete a;
   }
}
int stack::getMiddle()
{
   return mid->data;
}
void stack::push(int value)
{
   a = new node;
   a->data = value;
   if (top == NULL)
   {
      count = 0;
      a->next = a->prev = NULL;
      top = a;
      mid = top;

      size++;
   }
   else
   {
      a->prev = top;
      a->next = NULL;
      top->next = a;
      top = a;

      size++;
      if (size % 2 == 0)
      {
         mid = mid->next;
      }
   }
}