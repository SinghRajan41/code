#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct node
{
   pair<int, int> data;
   node *left, *right;
} *root = NULL;
node *LLRotation(node *p);
node *LRRotation(node *p);
node *RRRotation(node *p);
node *RLRotation(node *p);
int height(node *root);
void printInorder(node *root);
bool isGreater(pair<int, int> a, pair<int, int> b);
node *newNode(pair<int, int> p);
node *insert(node *root, pair<int, int> p);
bool isGreater(pair<int, int> a, pair<int, int> b);
void freqSort(int arr[], int n);
int balanceFactor(node *root);
void storeInorder(node *root, vector<pair<int, int>> &inorder);
int main()
{
   cout << "a\n";
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   freqSort(arr, n);
   return 0;
}
void storeInorder(node *root, vector<pair<int, int>> &inorder)
{
   if (root == NULL)
   {
      return;
   }
   storeInorder(root->left, inorder);
   inorder.push_back(root->data);
   storeInorder(root->right, inorder);
}
int balanceFactor(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return height(root->left) - height(root->right);
}
bool isGreater(pair<int, int> a, pair<int, int> b)
{
   if (b.second == a.second)
   {
      return a.first < b.first;
   }
   else
   {
      return a.second > b.second;
   }
}
node *insert(node *root, pair<int, int> p)
{
   if (root == NULL)
   {
      return newNode(p);
   }
   if (isGreater(p, root->data))
   {
      root->right = insert(root->right, p);
   }
   else
   {
      root->left = insert(root->left, p);
   }
   int a, b, c;
   a = balanceFactor(root->left);
   b = balanceFactor(root);
   c = balanceFactor(root->right);
   if (a == 1 && b == 2)
   {
      root = LLRotation(root);
   }
   else if (a == -1 && b == 2)
   {
      root = LRRotation(root);
   }
   else if (b == -2 && c == -1)
   {
      root = RRRotation(root);
   }
   else if (b == -2 && c == 1)
   {
      root = RRRotation(root);
   }
   return root;
}
void printInorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   printInorder(root->left);
   cout << root->data.first << " " << root->data.second << endl;
   printInorder(root->right);
}
void freqSort(int arr[], int n)
{
   int hash[100001] = {0};
   for (int i = 0; i < n; i++)
   {
      hash[arr[i]]++;
   }
   for (int i = 0; i < 100001; i++)
   {
      if (hash[i] > 0)
      {
         root = insert(root, make_pair(i, hash[i]));
      }
   }
   vector<pair<int, int>> inorder;
   storeInorder(root, inorder);
   int i = inorder.size() - 1;
   while (i >= 0)
   {
      cout << inorder[i].first << " " << inorder[i].second << endl;
      i--;
   }
}
node *LRRotation(node *p)
{
   if (p == NULL)
   {
      return NULL;
   }
   node *pl = p->left;
   node *x = pl->right;
   node *y = x->left;
   node *z = x->right;
   x->left = pl;
   pl->right = y;
   x->right = p;
   p->left = z;

   if (root == p)
   {
      root = x;
   }
   return x;
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
   if (root == a)
   {
      root = c;
   }
   return c;
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
   if (root == a)
   {
      root = b;
   }
   return b;
}
node *LLRotation(node *p)
{
   node *pl, *T2;
   pl = p->left;
   T2 = pl->right;
   pl->right = p;
   p->left = T2;
   if (root == p)
   {
      root = pl;
   }
   return pl;
}
int height(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   else
   {
      return max(height(root->left) + 1, height(root->right) + 1);
   }
}
node *newNode(pair<int, int> p)
{
   node *temp = new node;
   temp->left = temp->right = NULL;
   temp->data = p;
   return temp;
}