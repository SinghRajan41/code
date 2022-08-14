#include <iostream>
#include <unordered_map>
using namespace std;
class hashMap
{
public:
   int *arr, size;
   void makeHash(int in[], int x);
   int findMax(int in[], int x);
};
class hashTable
{
   int *h, size;

public:
   hashTable(int x);
   int hfunc(int value);
   void insert(int value);
   bool isPresent(int value);
   void display();
   void reset();
};
class node
{
public:
   int data;
   node *left, *right;
} *root = NULL;
/*struct node
{
   int data;
   node *left, *right, *random;
} *root = NULL;*/
node *newNode(int value);
template <class X>
class Queue
{
   X *arr;
   int f, l, size, count;

public:
   Queue(int x)
   {
      size = x;
      arr = new X[size];
      f = l = -1;
      count = 0;
   }
   Queue()
   {
      size = 100;
      arr = new X[size];
      f = l = -1;
      count = 0;
   }
   void nq(X value);
   void dq();
   X peekfront();
   bool isEmpty();
};
template <class X>
class stack
{
   int size, top;
   X *arr;

public:
   stack()
   {
      // cout << "Default Size of the Stack is 5000\n";
      size = 5000;
      top = -1;
      arr = new X[size];
   }
   stack(int n)
   {
      // cout << "Size of the stack=" << n << endl;
      size = n;
      top = -1;
      arr = new X[size];
   }
   void destructor()
   {
      delete[] arr;
   }
   ~stack()
   {
      delete[] arr;
   }
   void push(X value);
   X pop();
   int isempty();
   X peektop();
};
void createTree();
void printPreOrder(node *p);
void printPostOrder(node *p);
void printInOrder(node *p);
void recursiveInOrder(node *root);
int height(node *p);
void levelOrder1(node *p);
void printLevel(node *p, int level);
void levelOrder2(node *p);
int diameter1(node *t);
int diameter2(node *t, int *w);
node *cloneLeftRight(node *p, unordered_map<node *, node *> &m);
void cloneRandom(node *p, unordered_map<node *, node *> &m);
node *cloneBTree(node *p);
int findRoot(int pre[], int key, int size);
node *createInPre(int in[], int pre[], int n);
int findPos(int key, int arr[], int size);
node *makeTree(int in[], int post[], hashMap &h, int n);
node *createInPost(int in[], int post[], int n);
void inOrder(node *p, int freq[], int level);
int widthTree(node *p);
bool printAncestor(node *root, int key)
{
   if (root = NULL)
   {
      return false;
   }
   if (key == root->data)
   {
      return true;
   }
   if (printAncestor(root->left, key) || printAncestor(root->right, key))
   {
      cout << root->data << " ";
      return true;
   }
   return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
   createTree();
   printAncestor(root, 5);
   return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class X>
bool Queue<X>::isEmpty()
{
   return (count == 0) ? true : false;
}
template <class X>
X Queue<X>::peekfront()
{
   if (count == 0)
   {
      cout << "\nQueue is empty";
   }
   else
   {
      return arr[f];
   }
}
template <class X>
void Queue<X>::dq()
{
   if (count == 0)
   {
      cout << "\nQueue is Empty";
   }
   else if (count == 1)
   {
      count = 0;
      f = l = -1;
   }
   else
   {
      count -= 1;
      f = (f + 1) % size;
   }
}
template <class X>
void Queue<X>::nq(X value)
{
   if (count == size)
   {
      cout << "\nQueue is full";
      return;
   }
   else if (count == 0)
   {
      arr[0] = value;
      f = l = 0;
      count++;
   }
   else
   {
      count++;
      l = (l + 1) % size;
      arr[l] = value;
   }
}
int hashMap::findMax(int in[], int x)
{
   int m = INT32_MIN;
   for (int i = 0; i < x; i++)
   {
      m = (m > in[i]) ? m : in[i];
   }
   return m;
}
void hashMap::makeHash(int in[], int x)
{
   int maxValue = findMax(in, x);
   arr = new int[maxValue + 1];
   size = maxValue + 1;
   for (int i = 0; i <= maxValue; i++)
   {
      arr[i] = 0;
   }
   for (int i = 0; i < x; i++)
   {
      arr[in[i]]++;
   }
}
hashTable::hashTable(int x)
{
   bool s[2 * x + 11];
   for (int i = 0; i < 2 * x + 11; i++)
   {
      s[i] = 0;
   }
   // Making seive of eratosthenes
   for (int i = 2; i <= 2 * x + 10; i++)
   {
      if (s[i] == 0)
      {
         for (int j = i * i; j <= 2 * x + 10; j += i)
         {
            s[j] = 1;
         }
      }
   }
   for (int i = 2 * x + 11; i > 0; i--)
   {
      if (s[i] == 0)
      {
         size = i;
         break;
      }
   }
   h = new int[size];
   for (int i = 0; i < size; i++)
   {
      h[i] = -1;
   }
}
int hashTable::hfunc(int value)
{
   return value % size;
}
void hashTable::insert(int value)
{
   int pos = hfunc(value);
   while (h[pos] != -1)
   {
      pos = (pos + 1) % size;
   }
   h[pos] = value;
}
bool hashTable::isPresent(int value)
{
   int pos = hfunc(value);
   if (h[pos] == value)
   {
      return true;
   }
   else if (h[pos] == -1)
   {
      return false;
   }
   else
   {
      while (h[pos] != -1)
      {
         if (h[pos] == value)
         {
            return true;
         }
         pos = (pos + 1) % size;
      }
      return false;
   }
}
void hashTable::display()
{
   for (int i = 0; i < size; i++)
   {
      cout << h[i] << " ";
   }
}
void hashTable::reset()
{
   for (int i = 0; i < size; i++)
   {
      h[i] = -1;
   }
}
node *newNode(int value)
{
   node *temp = new node;
   temp->data = value;
   temp->left = temp->right = NULL;
   return temp;
}
template <class X>
void stack<X>::push(X value)
{
   if (top == size - 1)
   {
      cout << "StackOverFlow\nReturning from pop\n";
      return;
   }
   else
   {
      top += 1;
      arr[top] = value;
   }
}
template <class X>
X stack<X>::pop()
{
   X obj;
   if (top == -1)
   {
      cout << "\nStack is Empty\tReturning garbage value from pop\n";
      return obj;
   }
   else
   {
      obj = arr[top];
      top -= 1;
      return obj;
   }
}
template <class X>
int stack<X>::isempty()
{
   if (top <= -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
template <class X>
X stack<X>::peektop()
{
   return arr[top];
}
void createTree()
{
   int x;
   Queue<node *> q(1000);
   node *a, *b;
   a = new node;
   a->right = a->left = NULL;
   cin >> x;
   a->data = x;
   q.nq(a);
   root = a;
   while (!q.isEmpty())
   {
      a = q.peekfront();
      cin >> x;
      if (x != -1)
      {
         b = new node;
         b->left = b->right = NULL;
         b->data = x;
         a->left = b;
         q.nq(b);
      }
      cin >> x;
      if (x != -1)
      {
         b = new node;
         b->left = b->right = NULL;
         b->data = x;
         a->right = b;
         q.nq(b);
      }
      q.dq();
   }
}
void printPreOrder(node *p)
{
   cout << p->data << " ";
   if (p->left)
   {
      printPreOrder(p->left);
   }
   if (p->right)
   {
      printPreOrder(p->right);
   }
}
void printPostOrder(node *p)
{
   if (p->left)
   {
      printPostOrder(p->left);
   }
   if (p->right)
   {
      printPostOrder(p->right);
   }
   cout << p->data << " ";
}
void printInOrder(node *p)
{
   if (p->left)
   {
      printInOrder(p->left);
   }
   cout << p->data << " ";
   if (p->right)
   {
      printInOrder(p->right);
   }
}
void recursiveInOrder(node *root)
{
   node *p = root;
   stack<node *> s;
   while (p != NULL || !s.isempty())
   {
      while (p != NULL)
      {
         s.push(p);
         p = p->left;
      }
      p = s.pop();
      cout << p->data << " ";
      p = p->right;
   }
}
/*node *cloneLeftRight(node *p, unordered_map<node *, node *> &m)
{
    if (p == NULL)
    {
       return NULL;
    }
    else
    {
       node *cur = newNode(p->data);
       m.insert({p, cur});
       cur->left = cloneLeftRight(p->left, m);
       cur->right = cloneLeftRight(p->right, m);
       return cur;
    }
}*/
/*void cloneRandom(node *p, unordered_map<node *, node *> &m)
{
   if (p == NULL)
   {
      return;
   }
   else
   {
      if (p->random != NULL)
      {
         m[p]->random = m[p->random];
      }
      cloneRandom(p->left, m);
      cloneRandom(p->right, m);
   }
}
node *cloneBTree(node *p)
{
   if (p == NULL)
   {
      return NULL;
   }
   else
   {
      unordered_map<node *, node *> m;
      node *clone = cloneLeftRight(p, m);
      cloneRandom(root, m);
      return clone;
   }
}*/
node *createInPre(int in[], int pre[], int n)
{
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *p = newNode(pre[0]);
      return p;
   }
   else
   {
      int pos = findRoot(in, pre[0], n);
      int x, y;
      x = pos;
      y = n - pos - 1;
      int leftin[x], leftpre[x], rightin[y], rightpre[y];
      // Left left part
      for (int i = 0; i < x; i++)
      {
         leftin[i] = in[i];
         leftpre[i] = pre[i + 1];
      }
      // Right part
      for (int i = 0; i < y; i++)
      {
         rightin[i] = in[i + pos + 1];
         rightpre[i] = pre[i + x + 1];
      }
      node *p = newNode(pre[0]);
      p->left = createInPre(leftin, leftpre, x);
      p->right = createInPre(rightin, rightpre, y);
      return p;
   }
}
int findRoot(int pre[], int key, int size)
{
   for (int i = 0; i < size; i++)
   {
      if (pre[i] == key)
      {
         return i;
      }
   }
}
int diameter2(node *t, int *w)
{
   if (t != NULL)
   {
      int l = diameter2(t->left, w);
      int r = diameter2(t->right, w);
      *w = (*w > l + r + 1) ? *w : l + r + 1;
      return (l > r) ? l + 1 : r + 1;
   }
   else
   {
      return 0;
   }
}
int diameter1(node *t)
{
   if (t == NULL)
   {
      return 0;
   }
   int l, r, x, y;
   l = height(t->left);
   r = height(t->right);
   x = diameter1(t->left);
   y = diameter1(t->right);
   return max(l + r + 1, max(x, y));
}
void levelOrder2(node *p)
{
   int h = height(p);
   for (int i = 1; i <= h; i++)
   {
      printLevel(p, i);
   }
}
void printLevel(node *p, int level)
{
   if (p == NULL)
   {
      return;
   }
   if (level == 1)
   {
      cout << p->data << " ";
      return;
   }
   else
   {
      printLevel(p->left, level - 1);
      printLevel(p->right, level - 1);
   }
}
void levelOrder1(node *p)
{
   Queue<node *> q;
   q.nq(p);
   while (!q.isEmpty())
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
int height(node *p)
{
   return (p == NULL) ? 0 : max(height(p->left) + 1, height(p->right) + 1);
}
int findPos(int key, int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == key)
      {
         return i;
      }
   }
}
node *makeTree(int in[], int post[], hashMap &h, int n)
{
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *p = newNode(post[0]);
      return p;
   }
   else
   {
      int pos = h.arr[post[n - 1]];
      int x, y;
      x = pos;
      y = n - pos - 1;
      int leftin[x], leftpost[x], rightin[y], rightpost[y];
      for (int i = 0; i < x; i++)
      {
         leftin[i] = in[i];
         leftpost[i] = post[i];
      }
      for (int i = 0; i < y; i++)
      {
         rightin[i] = in[pos + 1 + i];
         rightpost[i] = post[i + pos];
      }
      node *p = newNode(post[n - 1]);
      p->left = makeTree(leftin, leftpost, h, x);
      p->right = makeTree(rightin, rightpost, h, y);
      return p;
   }
}
int widthTree(node *p)
{
   if (p == NULL)
   {
      return 0;
   }
   else
   {
      int h = height(p);
      int freq[h + 1] = {0};
      int level = 0;
      inOrder(root, freq, level + 1);
      int maxWidth = INT32_MIN;
      for (int i = 1; i <= h; i++)
      {
         maxWidth = (maxWidth > freq[i]) ? maxWidth : freq[i];
      }
      return maxWidth;
   }
}
void inOrder(node *p, int freq[], int level)
{
   if (p == NULL)
   {
      return;
   }
   else
   {
      freq[level]++;
      inOrder(p->left, freq, level + 1);
      inOrder(p->right, freq, level + 1);
   }
}
node *createInPost(int in[], int post[], int n)
{
   // Write code here
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *p = newNode(post[0]);
      return p;
   }
   else
   {
      hashMap h;
      h.makeHash(in, n);
      node *tree = makeTree(in, post, h, n);
      return tree;
   }
}