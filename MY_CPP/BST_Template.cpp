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
int NodeHeight(tnode *t);
tnode *Rinsert(tnode *t, int key)
{
   if (t == NULL)
   {
      tnode *temp = new tnode;
      temp->left = temp->right = NULL;
      temp->data = key;
      temp->height = 1;
      return temp;
   }
   if (key < t->data)
   {
      t->left = Rinsert(t->left, key);
   }
   else if (key > t->data)
   {
      t->right = Rinsert(t->right, key);
   }
   else if (t->data == key)
   {
      return t;
   }
   t->height = NodeHeight(t);
   /*//Now checking for unbalanced nodes and balancing them
   if(BalanceFactor(t)==2 && BalanceFactor(t->left)==1)
   {
      //LL Rotation
   }
   else if(BalanceFactor(t)==2 && BalanceFactor(t->left)==-1)
   {
      //LR Rotation
   }
   else if(BalanceFactor(t)==-2 && BalanceFactor(t->right)==-1)
   {
      //RR Rotation
   }
   else if(BalanceFactor(t)==-2 && BalanceFactor(t->right)==1)
   {
      //RL Rotation
   }*/
   return t;
}
int NodeHeight(tnode *t)
{
   if (t)
   {
      int x, y;
      x = NodeHeight(t->left);
      y = NodeHeight(t->right);
      return x > y ? x + 1 : y + 1;
   }
   else
   {
      return 0;
   }
}
tnode *InorderPred(tnode *t)
{
   while (t && t->right)
   {
      t = t->right;
   }
   return t;
}
tnode *InorderSucc(tnode *t)
{
   while (t && t->left)
   {
      t = t->left;
   }
   return t;
}
int BalanceFactor(tnode *t)
{
   int x, y;
   x = NodeHeight(t->left);
   y = NodeHeight(t->right);
   return x - y;
}
tnode *DeleteNode(tnode *t, int key)
{
   if (t == NULL)
   {
      return NULL;
   }
   else if (t->left == NULL && t->right == NULL && t->data == key)
   {
      delete t;
      return NULL;
   }
   else if (key < t->data)
   {
      t->left = DeleteNode(t->left, key);
   }
   else if (key > t->data)
   {
      t->right = DeleteNode(t->right, key);
   }
   else
   {
      // Node has been found
      tnode *q = NULL;
      if (NodeHeight(t->left) > NodeHeight(t->right))
      {
         // Find Inorder Predecessor
         q = InorderPred(t->left);
         t->data = q->data;
         /*if (t == root)
         {
            root = q;
         }*/
         t->left = DeleteNode(t->left, q->data);
      }
      else
      {
         // Find Inorder Successor
         q = InorderSucc(t->right);
         t->data = q->data;
         /*if (t == root)
         {
            root = q;
         }*/
         t->right = DeleteNode(t->right, q->data);
      }
   }
   return t;
}
void inorder_display(tnode *t)
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
void preorder_display(tnode *t)
{
   if (t)
   {
      cout << t->data << " ";
   }
   if (t->left)
   {
      preorder_display(t->left);
   }
   if (t->right)
   {
      preorder_display(t->right);
   }
   if (t == NULL)
   {
      return;
   }
}
int main()
{

   root = Rinsert(root, 100);
   Rinsert(root, 20);
   Rinsert(root, 200);
   Rinsert(root, 30);
   Rinsert(root, 10);
   Rinsert(root, 150);
   Rinsert(root, 250);

   root = DeleteNode(root, 100);
   preorder_display(root);
   return 0;
}