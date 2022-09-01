#include <iostream>
using namespace std;
struct tnode
{
   int data;
   tnode *left, *right, *parent;
   char color;
   int height;
} *root = NULL;
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
void decolorise(tnode *n, int x)
{
   n->color = 'r';
   n->left->color = 'b';
   n->right->color = 'b';
   if (n == root)
   {
      n->color = 'b';
   }
}
int node_height(tnode *n);
char uncle_color(tnode *n, int x)
{
   switch (x)
   {
   case 1:
      if (n->left == NULL)
      {
         return 'b';
      }
      return n->left->color;
      break;
   case 2:
      if (n->left == NULL)
      {
         return 'b';
      }
      return n->left->color;
      break;
   case 3:
      if (n->right == NULL)
      {
         return 'b';
      }
      return n->right->color;
      break;
   case 4:
      if (n->right == NULL)
      {
         return 'b';
      }
      return n->right->color;
      break;
   }
}
tnode *LLRotation(tnode *p)
{
   tnode *pl, *b;
   pl = p->left;
   b = pl->right;
   pl->right = p;
   p->left = b;
   pl->height = node_height(pl);
   p->height = node_height(p);
   b->parent = p;
   p->parent = pl;
   if (p == root)
   {
      root = pl;
      root->color = 'b';
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
   a->height = node_height(a);
   pl->height = node_height(pl);
   p->height = node_height(p);
   a->color = 'b';
   pl->color = 'r';
   p->color = 'r';
   pl->parent = a;
   p->parent = p;
   d->parent = p;
   c->parent = pl;
   if (p == root)
   {
      root = a;
      root->color = 'b';
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
   pr->height = node_height(pr);
   p->height = node_height(p);
   p->parent = pr;
   pr->right->parent = pr;
   if (b)
   {
      b->parent = p;
   }
   pr->color = 'b';
   p->color = 'r';
   pr->right->color = 'r';
   if (root == p)
   {
      root = pr;
      root->color = 'b';
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
   a->height = node_height(a);
   p->height = node_height(p);
   pr->height = node_height(pr);
   a->color = 'b';
   p->color = 'r';
   pr->color = 'r';
   c->parent = p;
   d->parent = pr;
   pr->parent = a;
   p->parent = a;
   if (root == p)
   {
      root = a;
      a->color = 'b';
   }
   return a;
}
int color_mismatch(tnode *t)
{
   if (node_height(t) <= 2)
   {
      return 0;
   }
   else
   {
      if ((t->right && t->right->right))
      {
         if (t->right->color == t->right->right->color == 'r')
         {
            return 1;
         }
      }
      if (t->right && t->right->left)
      {
         if (t->right->color == t->right->left->color == 'r')
         {
            return 2;
         }
      }
      if (t->left && t->left->left)
      {
         if (t->left->color == t->left->left->color == 'r')
         {
            return 3;
         }
      }
      if (t->left && t->left->right)
      {
         if (t->left->color == t->left->right->color == 'r')
         {
            return 4;
         }
      }
      return 0;
   }
}
int node_height(tnode *n)
{
   if (n)
   {
      int hl = node_height(n->left);
      int hr = node_height(n->right);
      return hl > hr ? hl + 1 : hr + 1;
   }
   else
   {
      return 0;
   }
}
tnode *Rinsert(tnode *n, int key, tnode *parent = NULL)
{
   if (n == NULL)
   {
      tnode *temp = new tnode;
      temp->left = temp->right = NULL;
      temp->height = 1;
      temp->color = 'r';
      temp->data = key;
      temp->parent = parent;
      if (root == NULL)
      {
         temp->color = 'b';
      }
      return temp;
   }
   else if (key < n->data)
   {
      n->left = Rinsert(n->left, key, n);
   }
   else if (key > n->data)
   {
      n->right = Rinsert(n->right, key, n);
   }
   n->height = node_height(n);
   int x = color_mismatch(n);
   cout << " " << x << " ";
   if (x)
   {
      // Here we determine the type of color mismatch and take appropriate steps
      if (uncle_color(n, x) == 'r')
      {
         // Write code for Decolorising
         decolorise(n, x);
      }
      else
      {
         // Write code for rotation
         switch (x)
         {
         case 1:
            // Perform RR Rotation
            n = RRRotation(n);
            break;
         case 2:
            // Perform RL Rotation
            n = RLRotation(n);
            break;

         case 3:
            n = LLRotation(n);
            break;
         case 4:
            n = LRRotation(n);
            break;
            // Perform LR Rotation
         }
      }
   }
   else
   {
      // No color mismatch found
      return n;
   }
   return n;
}
void display(tnode *n)
{
   if (n)
   {
      cout << n->data << " " << n->color << "     ";
   }
   if (n->left)
   {
      display(n->left);
   }
   if (n->right)
   {
      display(n->right);
   }
}
void level_display(tnode *n)
{
   queue q;
   q.nq(n);
   while (!q.isempty())
   {
      n = q.peekfront();
      cout << n->data << " " << n->color << "    ";
      if (n->left)
      {
         q.nq(n->left);
      }
      if (n->right)
      {
         q.nq(n->right);
      }
      q.dq();
   }
}
int main()
{
   root = NULL;
   root = Rinsert(root, 21);
   root = Rinsert(root, 39);
   root = Rinsert(root, 99);
   /*Rinsert(root, 211);
   Rinsert(root, 420);
   Rinsert(root, 150);
   Rinsert(root, 5);*/
   level_display(root);
   return 0;
}