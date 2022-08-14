#include <iostream>
#include <queue>
using namespace std;
struct node
{
   int data;
   node *left, *right;
   char color;
} *root = NULL;
node *newNode(int x);
node *insert(node *p, int value);
void levelOrderLinebyLine(node *root);
node *recolor(node *x);
node *RRRotation(node *x);
node *RLRotation(node *x);
node *LRRotation(node *x);
node *LLRotation(node *x);
void printInorder(node *root);
int main()
{
   int keys[] = {20, 19, 28, 63, 87, 51, 69, 84, 43, 49, 112, 250};
   int n = sizeof(keys) / sizeof(keys[0]);
   for (int i = 0; i < n; i++)
      root = insert(root, keys[i]);
   levelOrderLinebyLine(root);
   return 0;
}
void printInorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   node *cur = root;
   while (cur != NULL)
   {
      if (cur->left == NULL)
      {
         cout << cur->data << " ";
         cur = cur->right;
      }
      else
      {
         node *pre = cur->left;
         while (pre->right != NULL && pre->right != cur)
         {
            pre = pre->right;
         }
         if (pre->right == NULL)
         {
            pre->right = cur;
            cur = cur->left;
         }
         else
         {
            pre->right = NULL;
            cout << cur->data << " ";
            cur = cur->right;
         }
      }
   }
}
void levelOrderLinebyLine(node *root)
{
   if (root == NULL)
   {
      return;
   }
   queue<node *> q;
   int count = 1;
   q.push(root);
   while (!q.empty())
   {
      int x = 0;
      while (count--)
      {
         node *cur = q.front();
         q.pop();
         cout << cur->data << " ";
         if (cur->left)
         {
            q.push(cur->left);
            x++;
         }
         if (cur->right)
         {
            q.push(cur->right);
            x++;
         }
      }
      cout << endl
           << endl
           << endl;
      count = x;
   }
}

node *insert(node *p, int value)
{
   if (p == NULL)
   {
      return newNode(value);
   }
   if (value < p->data)
   {
      p->left = insert(p->left, value);
   }
   else
   {
      p->right = insert(p->right, value);
   }
   if (p->left && p->left->left && p->left->color == 'R' && p->left->left->color == 'R')
   {
      if (p->right == NULL || p->right->color == 'B')
      {
         // Rotation is required
         p = LLRotation(p);
      }
      if (p->right && p->right->color == 'R')
      {
         // Recoloring is required
         p = recolor(p);
      }
   }
   if (p->left && p->left->right && p->left->color == 'R' && p->left->right->color == 'R')
   {
      if (p->right == NULL || p->right->color == 'B')
      {
         // Rotation is required
         p = LRRotation(p);
      }
      if (p->right && p->right->color == 'R')
      {
         // Recoloring is reuiqred
         p = recolor(p);
      }
   }
   if (p->right && p->right->right && p->right->color == 'R' && p->right->right->color == 'R')
   {
      if (p->left == NULL || p->left->color == 'B')
      {
         // Rotation is required
         p = RRRotation(p);
      }
      if (p->left && p->left->color == 'R')
      {
         // Recoloring is reuired
         p = recolor(p);
      }
   }
   if (p->right && p->right->left && p->right->color == 'R' && p->right->left->color == 'R')
   {
      if (p->left == NULL || p->left->color == 'B')
      {
         // Reotation is required
         p = RLRotation(p);
      }
      if (p->left && p->left->color == 'R')
      {
         // Recoloring is reuiqred
         p = recolor(p);
      }
   }

   return p;
}
node *newNode(int x)
{
   node *temp = new node;
   temp->left = temp->right = NULL;
   temp->data = x;
   temp->color = 'R';
   return temp;
}
node *recolor(node *x)
{
   if (x == NULL)
   {
      return NULL;
   }
   x->color = 'R';
   x->left->color = 'B';
   x->right->color = 'B';
   if (x == root)
   {
      x->color = 'B';
   }
   return x;
}
node *RRRotation(node *x)
{
   if (!x)
   {
      return NULL;
   }
   node *y = x->right;
   node *T4 = y->left;
   y->left = x;
   x->right = T4;
   y->color = 'B';
   x->color = y->right->color = 'R';
   if (x == root)
   {
      root = y;
      y->color = 'B';
   }
   return y;
}
node *RLRotation(node *x)
{
   if (x == NULL)
   {
      return NULL;
   }
   node *y, *z, *T2, *T3;
   y = x->right;
   z = y->left;
   T2 = z->left;
   T3 = z->right;
   x->right = T2;
   z->left = x;
   z->right = y;
   y->left = T3;
   x->color = y->color = 'R';
   z->color = 'B';
   if (root == x)
   {
      root = z;
      z->color = 'B';
   }
   return z;
}
node *LRRotation(node *x)
{
   if (x == NULL)
   {
      return NULL;
   }
   node *y = x->left;
   node *z = y->right;
   node *T2 = z->left;
   node *T3 = z->right;
   y->right = T2;
   z->left = y;
   z->right = x;
   x->left = T3;
   z->color = 'B';
   x->color = y->color = 'R';
   if (x == root)
   {
      root = z;
      z->color = 'B';
   }
   return z;
}
node *LLRotation(node *x)
{
   if (x == NULL)
   {
      return NULL;
   }
   node *y = x->left;
   node *T3 = y->right;
   y->right = x;
   x->left = T3;
   y->color = 'B';
   x->color = y->left->color = 'R';
   if (root == x)
   {
      root = y;
      y->color = 'B';
   }
   return y;
}