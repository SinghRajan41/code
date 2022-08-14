#include <iostream>
#include <queue>
using namespace std;
struct node
{
   int data, height;
   node *left, *right;
} *root = NULL;
node *newNode(int x);
int height(node *root);
node *insert(node *root, int key);
node *LLRotation(node *root);
node *LRRotation(node *root);
node *RRRotation(node *root);
node *RLRotation(node *root);
void levelOrderLinebyLine(node *root);
int balanceFactor(node *root);
node *deleteNode(node *root, int key);
int ccc = 0;
int main()
{
   // root = newNode(5);
   // root->left = newNode(4);
   // root->left->left = newNode(3);
   // root->left->left->left = newNode(2);
   // root->left->left->right = newNode(1);
   // root->right = newNode(6);
   // root->left->right = newNode(7);
   // // levelOrderLinebyLine(root);
   // cout << endl;
   // root = LLRotation(root);
   // // levelOrderLinebyLine(root);
   // cout << balanceFactor(root);
   for (int i = 0; i < 10000; i++)
   {
      root = insert(root, i + 1);
      cout << i + 1 << " inserted\n";
   }
   for (int i = 0; i < 2000; i++)
   {
      root = deleteNode(root, i + 1);
      root = deleteNode(root, 9000 - i);
   }
   levelOrderLinebyLine(root);
   cout << endl
        << endl
        << ccc;

   return 0;
}
node *deleteNode(node *root, int key)
{
   if (root == NULL)
   {
      return NULL;
   }
   if (key < root->data)
   {
      root->left = deleteNode(root->left, key);
   }
   if (key > root->data)
   {
      root->right = deleteNode(root->right, key);
   }
   if (root->data == key)
   {
      if (root->left == NULL && root->right == NULL)
      {
         delete root;
         return NULL;
      }
      if (height(root->left) > height(root->right))
      {
         node *pred = root->left;
         while (pred != NULL && pred->right != NULL)
         {
            pred = pred->right;
         }
         if (pred)
         {
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data);
         }
      }
      else
      {
         node *suc = root->right;
         while (suc != NULL && suc->left != NULL)
         {
            suc = suc->left;
         }
         if (suc)
         {
            root->data = suc->data;
            root->right = deleteNode(root->right, suc->data);
         }
      }
   }
   int a, b, c;
   a = balanceFactor(root->left);
   b = balanceFactor(root);
   c = balanceFactor(root->right);
   if (a >= 0 && b >= 2)
   {
      return LLRotation(root);
   }
   else if (b >= 2 && a <= 0)
   {
      return LRRotation(root);
   }
   else if (b <= -2 && c <= 0)
   {
      return RRRotation(root);
   }
   else if (b <= -2 && c <= 0)
   {
      return RLRotation(root);
   }
   root->height = height(root);
   return root;
}
node *insert(node *root, int value)
{
   if (root == NULL)
   {
      return newNode(value);
   }
   if (value < root->data)
   {
      root->left = insert(root->left, value);
   }
   if (value > root->data)
   {
      root->right = insert(root->right, value);
   }
   int a, b, c;
   a = balanceFactor(root->left);
   b = balanceFactor(root);
   c = balanceFactor(root->right);
   if (a == 1 && b == 2)
   {
      return LLRotation(root);
   }
   else if (b == 2 && a == -1)
   {
      return LRRotation(root);
   }
   else if (b == -2 && c == -1)
   {
      return RRRotation(root);
   }
   else if (b == -2 && c == 1)
   {
      return RLRotation(root);
   }
   root->height = height(root);
   return root;
}
void levelOrderLinebyLine(node *root)
{
   if (root == NULL)
   {
      return;
   }
   queue<node *> q;
   q.push(root);
   int count = 1;
   while (!q.empty())
   {
      int x = 0;
      while (count--)
      {
         node *cur = q.front();
         q.pop();
         cout << height(cur) << " ";
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
      count = x;
      cout << endl
           << endl
           << endl;
   }
}
node *LLRotation(node *a)
{
   if (a == NULL)
   {
      return NULL;
   }
   node *b = a->left;
   node *d = b->right;
   b->right = a;
   a->left = d;
   b->height = height(b);
   a->height = height(a);
   if (a == root)
   {
      root = b;
   }
   ccc++;
   return b;
}
int balanceFactor(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return (height(root->left) - height(root->right));
}
node *RRRotation(node *a)
{
   if (a == NULL)
   {
      return NULL;
   }
   node *b = a->right;
   node *c = b->right;
   node *d = b->left;
   b->left = a;
   a->right = d;
   a->height = height(a);
   b->height = height(b);
   if (root == a)
   {
      root = b;
   }
   ccc++;
   return b;
}
node *RLRotation(node *a)
{
   if (a == NULL)
   {
      return NULL;
   }
   node *b, *c, *d, *e;
   b = a->right;
   c = b->left;
   d = c->left;
   e = c->right;
   c->left = a;
   a->right = d;
   c->right = b;
   b->left = e;
   a->height = height(a);
   b->height = height(b);
   c->height = height(c);
   if (root == a)
   {
      root = c;
   }
   ccc++;
   return c;
}
node *LRRotation(node *a)
{
   if (a == NULL)
   {
      return NULL;
   }
   node *b, *c, *d, *e;
   b = a->left;
   c = b->right;
   d = c->left;
   e = c->right;
   c->left = b;
   b->right = d;
   c->right = a;
   a->left = e;
   c->height = height(c);
   b->height = height(b);
   a->height = height(a);
   if (a == root)
   {
      root = c;
   }
   ccc++;
   return c;
}
// A utitlity function to get of the tree
int height(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   else
   {
      int l, r;
      l = height(root->left);
      r = height(root->right);
      return l > r ? l + 1 : r + 1;
   }
}
node *newNode(int x)
{
   node *temp = new node;
   temp->left = temp->right = NULL;
   temp->data = x;
   temp->height = 1;
   return temp;
}
