#include <iostream>
#include <cstring>
using namespace std;
struct tnode
{
   tnode *left, *right;
   // Data stored by the tree node will be integer type
   int data;
   int height;
} *root = NULL;
struct node
{
   // This is a simple node used in Stack and Queues
   node *next;
   tnode *data;
};
class stack
{
   node *top, *a, *b;

public:
   stack()
   {
      top = NULL;
   }
   void push(tnode *n);
   tnode *pop();
   int isempty();
   tnode *peektop();
};
class queue
{
   node *first, *last, *a;

public:
   queue() { first = last = NULL; }
   void nq(tnode *n);
   void dq();
   int isempty();
   tnode *peekfront();
};
tnode *Rinsert(tnode *p, int key);
void level_order_display(tnode *root);
void preorder_display(tnode *t);
tnode *Delete_Node(tnode *t, int key);
tnode *q = NULL;
int height(tnode *p);
tnode *inorder_succ(tnode *p);
tnode *inorder_pred(tnode *p);

int main()
{
   root = Rinsert(root, 100);
   Rinsert(root, 20);
   Rinsert(root, 200);
   Rinsert(root, 10);
   Rinsert(root, 30);
   Rinsert(root, 150);
   Rinsert(root, 250);
   root = Delete_Node(root, 100);
   preorder_display(root);

   return 0;
}

int height(tnode *p)
{
   if (p)
   {
      int x, y;
      x = height(p->left);
      y = height(p->right);
      return x > y ? x + 1 : y + 1;
   }
   else
   {
      return 0;
   }
}
tnode *inorder_succ(tnode *p)
{
   while (p && p->left)
   {
      p = p->left;
   }
   return p;
}
tnode *inorder_pred(tnode *p)
{
   while (p && p->right)
   {
      p = p->right;
   }
   return p;
}
tnode *Delete_Node(tnode *t, int key)
{
   if (t == NULL)
   {
      return NULL;
   }
   if (t->left == NULL && t->right == NULL)
   {
      delete t;
      return NULL;
   }
   if (key < t->data)
   {
      t->left = Delete_Node(t->left, key);
   }
   else if (key > t->data)
   {
      t->right = Delete_Node(t->right, key);
   }
   else
   {
      // It means key is found
      if (height(t->left) > height(t->right))
      {
         // Write a code to find the inorder predecessor and delete
         q = inorder_pred(t->left);
         t->data = q->data;
         t->left = Delete_Node(t->left, q->data);
      }
      else
      {
         // Write a code to find the inorder successor and delete it
         q = inorder_succ(t->right);
         t->data = q->data;
         t->right = Delete_Node(t->right, q->data);
      }
   }
   return t;
}
void preorder_display(tnode *t)
{
   stack s;
   while (t != NULL || !s.isempty())
   {
      if (t)
      {
         s.push(t);
         t = t->left;
      }
      else
      {
         t = s.pop();
         cout << t->data << " ";
         t = t->right;
      }
   }
}
void level_order_display(tnode *p)
{
   if (p == NULL)
   {
      return;
   }
   else
   {
      queue q;
      q.nq(p);
      while (!q.isempty())
      {
         p = q.peekfront();
         cout << p->data << " ";
         if (p->left)
         {
            q.nq(p->left);
         }
         if (p->right)
         {
            q.nq(p->right);
         }
         q.dq();
      }
   }
}
tnode *Rinsert(tnode *p, int key)
{
   if (p == NULL)
   {
      tnode *t = new tnode;
      t->left = t->right = NULL;
      t->data = key;
      return t;
   }
   else if (key < p->data)
   {
      p->left = Rinsert(p->left, key);
   }
   else if (key > p->data)
   {
      p->right = Rinsert(p->right, key);
   }
   return p;
}
void stack::push(tnode *n)
{
   a = new node;
   a->next = NULL;
   a->data = n;
   if (top == NULL)
   {
      top = a;
      return;
   }
   else
   {
      a->next = top;
      top = a;
   }
}
tnode *stack::pop()
{
   tnode *temp = NULL;
   if (top == NULL)
   {
      return NULL;
   }
   else
   {
      a = top;
      top = top->next;
      temp = a->data;
      delete a;
      return temp;
   }
}
int stack::isempty()
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
tnode *stack::peektop()
{
   if (top == NULL)
   {
      return NULL;
   }
   else
   {
      return top->data;
   }
}
void queue::nq(tnode *n)
{
   a = new node;
   a->next = NULL;
   a->data = n;
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
void queue::dq()
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
int queue::isempty()
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
tnode *queue::peekfront()
{
   if (first == NULL)
   {
      return NULL;
   }
   else
   {
      return first->data;
   }
}
