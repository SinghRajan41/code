#include <iostream>
using namespace std;
struct tnode
{
   int data;
   tnode *left, *right;
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
tnode *Rinsert(tnode *, int);
void decolorise(tnode *, int);
tnode *Rotate(tnode *, int);
int node_height(tnode *n)
{
   if (n)
   {
      int hl, hr;
      hl = node_height(n->left);
      hr = node_height(n->right);
      return hl > hr ? hl + 1 : hr + 1;
   }
   else
   {
      return 0;
   }
}
int color_mismatch(tnode *n)
{
   if (node_height(n) <= 2)
   {
      return 0;
   }
   else
   {
      if (n->left)
      {
         if (n->left->left)
         {
            if (n->left->color == 'r' && n->left->left->color == 'r')
            {
               // Condition for LL
               return 1;
            }
         }
         if (n->left->right)
         {
            if (n->left->color == 'r' && n->left->right->color == 'r')
            {
               // Condition for LR Rotation
               return 2;
            }
         }
      }
      if (n->right)
      {

         if (n->right->right)
         {
            if (n->right->color == 'r' && n->right->right->color == 'r')
            {
               return 3;
               // Condition for RR
            }
         }
         if (n->right->left)
         {
            if (n->right->color == 'r' && n->right->left->color == 'r')
            {
               return 4;
               // Condition for RL
            }
         }
      }
      return 0;
   }
}
char uncle_color(tnode *n, int x)
{
   switch (x)
   {
   case 1:
      // LLRotation
      if (n->right == NULL)
      {
         return 'b';
      }
      else
      {
         return n->right->color;
      }
      break;
   case 2:
      // LRRotation
      if (n->right == NULL)
      {
         return 'b';
      }
      else
      {
         return n->right->color;
      }
      break;
   case 3:
      // RRRotation
      if (n->left == NULL)
      {
         return 'b';
      }
      else
      {
         return n->left->color;
      }
      break;
   case 4:
      // RL Rotation
      if (n->left == NULL)
      {
         return 'b';
      }
      else
      {
         return n->left->color;
      }
      break;
   }
}
void display(tnode *a)
{
   if (a->left)
   {
      display(a->left);
   }
   if (a)
   {
      cout << a->data << " " << a->color << "     ";
   }
   if (a->right)
   {
      display(a->right);
   }
}
tnode *Rinsert(tnode *n, int key)
{
   if (n == NULL)
   {
      tnode *temp = new tnode;
      temp->left = temp->right = NULL;
      temp->height = 1;
      temp->data = key;
      temp->color = 'r';
      if (root == NULL)
      {
         temp->color = 'b';
      }
      return temp;
   }
   else if (key < n->data)
   {
      n->left = Rinsert(n->left, key);
   }
   else if (key > n->data)
   {
      n->right = Rinsert(n->right, key);
   }
   n->height = node_height(n);
   int x = color_mismatch(n);
   if (x)
   {
      // Imbalance found
      if (uncle_color(n, x) == 'r')
      {
         decolorise(n, x);
      }
      else
      {
         n = Rotate(n, x);
      }
   }
   return n;
}
void decolorise(tnode *n, int x)
{
   cout << "\nDCL Called\n";
   n->color = 'r';
   n->left->color = n->right->color = 'b';
   if (n == root)
   {
      n->color = 'b';
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
   pl->color = 'b';
   pl->left->color = 'r';
   pl->right->color = 'r';
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
   a->left->color = 'r';
   a->right->color = 'r';
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
   pr->color = 'b';
   pr->left->color = 'r';
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
   a->left->color = 'r';
   a->right->color = 'r';
   if (root == p)
   {
      root = a;
      root->color = 'b';
   }
   return a;
}
tnode *Rotate(tnode *n, int x)
{
   switch (x)
   {
   case 1:
      // LL Rotation
      return LLRotation(n);
      break;
   case 2:
      // LR Rotation
      return LRRotation(n);
      break;
   case 3:
      // RR Rotation
      return RRRotation(n);
      break;
   case 4:
      // RL Rotation
      return RLRotation(n);
      break;
   }
}
int main()
{
   /*tnode *a, *b, *c, *d;
   a = new tnode;
   b = new tnode;
   c = new tnode;
   d = new tnode;
   d->left = d->right = NULL;
   d->color = 'b';
   a->right = d;
   a->data = b->data = c->data = 26;
   a->left = b;
   b->left = NULL;
   b->right = c;
   c->left = c->right = NULL;
   a->color = 'b';
   b->color = 'r';
   c->color = 'r';
   int x = color_mismatch(a);
   cout << uncle_color(a, x);*/
   root = Rinsert(root, 1);
   for (int i = 2; i < 16; i++)
   {
      Rinsert(root, i);
   }
   display(root);
   return 0;
}