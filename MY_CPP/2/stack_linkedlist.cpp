#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
class stack
{
   node *top, *a, *b;

public:
   stack() { top = NULL; }
   void push(int value);
   int pop();
   int isFull();
   int isEmpty();
   void display();
   int peektop()
   {
      return top->data;
   }
   void displayr(node *a);
   node *getTop();
   void reverseStack(int x);
   void insertBottom(int value);
   void sortStack(int cur);
   void sortedInsert(int key);
};

int main()
{
   stack s;
   s.push(6);
   s.push(19);
   s.push(2);
   s.push(91);
   s.push(3);
   s.push(23);

   int x = s.pop();
   s.sortStack(x);
   s.display();
   return 0;
}
void stack::sortStack(int cur)
{
   int x = pop();
   if (!isEmpty())
   {
      sortStack(x);
   }
   else
   {
      push(x);
   }
   sortedInsert(cur);
}
void stack::sortedInsert(int key)
{
   int x = -1;
   if (!isEmpty() && key < peektop())
   {
      x = pop();
      sortedInsert(key);
   }
   else
   {
      push(key);
   }
   if (x != -1)
      push(x);
}
void stack::insertBottom(int value)
{
   bool flag = false;
   int x;
   if (!isEmpty())
   {
      x = pop();
      flag = true;
      insertBottom(value);
   }
   if (flag)
   {
      push(x);
   }
   else
   {
      push(value);
   }
}
void stack::reverseStack(int cur)
{
   if (!isEmpty())
   {
      int x = pop();
      reverseStack(x);
   }
   insertBottom(cur);
}
void stack::push(int value)
{
   a = new node;
   if (a == NULL)
   {
      cout << "Stack OverFlow\n";
      return;
   }
   else
   {
      a->data = value;
      a->next = top;
      top = a;
   }
}
int stack::pop()
{
   int x = -1;
   if (top != NULL)
   {
      a = top;
      top = top->next;
      x = a->data;
   }
   return x;
}

void stack::display()
{
   if (top == NULL)
   {
      cout << "Stack is Empty\n";
      return;
   }
   else
   {
      a = top;
      while (a != NULL)
      {
         cout << a->data << " ";
         a = a->next;
      }
   }
}

int stack::isFull()
{
   a = new node;
   int x = a ? 0 : 1;
   delete a;
   return x;
}
void stack::displayr(node *a)
{
   if (a != NULL)
   {
      displayr(a->next);
      cout << a->data << " ";
   }
}
node *stack::getTop()
{
   return top;
}
int stack::isEmpty()
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