#include <iostream>
using namespace std;
struct tnode
{
   tnode *left, *right;
   int data;
   int height;

} *root = NULL, *q = NULL;
struct node
{
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
   void push(tnode *n)
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
   tnode *pop()
   {
      tnode *temp = NULL;
      if (top == NULL)
      {
         return temp;
      }
      else
      {
         a = top;
         temp = a->data;
         top = top->next;
         delete a;
         return temp;
      }
   }
   int isempty()
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
   tnode *peektop()
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
};
class queue
{
   node *first, *last, *a, *b;

public:
   queue()
   {
      first = last = a = b = NULL;
   }
   void nq(tnode *n)
   {
      a = new node;
      a->next = NULL;
      a->data = n;
      if (first == NULL)
      {
         first = last = a;
         return;
      }
      else
      {
         last->next = a;
         last = a;
      }
   }
   void dq()
   {
      if (first == NULL)
      {
         return;
      }
      else if (first == last && first != NULL)
      {
         delete first;
         first = last = NULL;
         return;
      }
      else
      {
         a = first;
         first = first->next;
         delete a;
         return;
      }
   }
   int isempty()
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
   tnode *peekfront()
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
};
int NodeHeight(tnode *t)
{
   if (t)
   {
      int hl, hr;
      hl = NodeHeight(t->left);
      hr = NodeHeight(t->right);
      return hl > hr ? hl + 1 : hr + 1;
   }
   else
   {
      return 0;
   }
}
int BalanceFactor(tnode *t)
{
   int hl, hr;
   hl = NodeHeight(t->left);
   hr = NodeHeight(t->right);
   return hl - hr;
}

tnode *LLRotation(tnode *p)
{
   tnode *pl, *b;
   pl = p->left;
   b = pl->right;
   pl->right = p;
   p->left = b;
   pl->height = NodeHeight(pl);
   p->height = NodeHeight(p);
   if (p == root)
   {
      root = pl;
   }
   return pl;
}
tnode *LRRotation(tnode *p)
{
   tnode *pl, *a, *c, *d;
   pl = p->left;
   a = pl->right;
   c = a->left;
   d = a->left;
   a->left = pl;
   pl->right = c;
   a->right = p;
   p->left = d;
   a->height = NodeHeight(a);
   pl->height = NodeHeight(pl);
   p->height = NodeHeight(p);
   if (p == root)
   {
      root = a;
   }
   return a;
}
tnode *RRRotation(tnode *p)
{
   tnode *pr, *b;
   pr = p->right;
   b = pr->left;
   pr->left = p;
   p->right = b;
   pr->height = NodeHeight(pr);
   p->height = NodeHeight(p);
   if (root == p)
   {
      root = pr;
   }
   return pr;
}
tnode *RLRotation(tnode *p)
{
   tnode *pr, *a, *c, *d;
   pr = p->right;
   a = pr->left;
   c = a->left;
   d = a->right;
   a->left = p;
   a->right = pr;
   p->right = c;
   pr->left = d;
   a->height = NodeHeight(a);
   p->height = NodeHeight(p);
   pr->height = NodeHeight(pr);
   if (root == p)
   {
      root = a;
   }
   return a;
}
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
   t->height = NodeHeight(t);
   if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == 1)
   {
      // LL Rotation
      return LLRotation(t);
   }
   else if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == -1)
   {
      // LRRotation
      return LRRotation(t);
   }
   else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == -1)
   {
      // RRRotation
      return RRRotation(t);
   }
   else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == 1)
   {
      // RL Rotation
      return RLRotation(t);
   }
   return t;
}
void display(tnode *t)
{
   if (t)
   {
      display(t->left);
   }
   if (t)
   {
      cout << t->data << " ";
   }
   if (t)
   {
      display(t->right);
   }
}
tnode *In_Succ(tnode *t)
{
   while (t && t->left)
   {
      t = t->left;
   }
   return t;
}
tnode *In_Pred(tnode *t)
{
   while (t && t->right)
   {
      t = t->right;
   }
   return t;
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
      // Node found
      if (NodeHeight(t->left) > NodeHeight(t->right))
      {
         q = In_Pred(t->left);
         t->data = q->data;
         t->left = DeleteNode(t->left, q->data);
         goto check_rotate;
      }
      else
      {
         q = In_Succ(t->right);
         t->data = q->data;
         t->right = DeleteNode(t->right, q->data);
         goto check_rotate;
      }
   check_rotate:
   {
      t->height = NodeHeight(t);
      if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == 1)
      {
         // LL Rotation
         return LLRotation(t);
      }
      else if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == -1)
      {
         // LRRotation
         return LRRotation(t);
      }
      else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == -1)
      {
         // RRRotation
         return RRRotation(t);
      }
      else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == 1)
      {
         // RL Rotation
         return RLRotation(t);
      }
   }
   }
   return t;
}
int main()
{
   root = Rinsert(root, 100);
   Rinsert(root, 30);
   Rinsert(root, 150);
   Rinsert(root, 10);
   Rinsert(root, 40);
   Rinsert(root, 130);
   Rinsert(root, 160);
   root = DeleteNode(root, 160);
   display(root);
   return 0;
}
