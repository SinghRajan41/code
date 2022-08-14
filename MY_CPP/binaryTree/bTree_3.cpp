// Clone a binary tree having a random pointer pointing to any node
#include <iostream>
#include <unordered_map>
using namespace std;
class hashTable
{
   int *h, size;

public:
   hashTable(int x)
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
   int hfunc(int value)
   {
      return value % size;
   }
   void insert(int value)
   {
      int pos = hfunc(value);
      while (h[pos] != -1)
      {
         pos = (pos + 1) % size;
      }
      h[pos] = value;
   }
   bool isPresent(int value)
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
   void display()
   {
      for (int i = 0; i < size; i++)
      {
         cout << h[i] << " ";
      }
   }
   void reset()
   {
      for (int i = 0; i < size; i++)
      {
         h[i] = -1;
      }
   }
};
/*class node
{
public:
   int data;
   node *left, *right;
} *root = NULL;*/
struct node
{
   int data;
   node *left, *right, *random;
} *root = NULL;
node *newNode(int value)
{
   node *temp = new node;
   temp->data = value;
   temp->left = temp->right = temp->random = NULL;
   return temp;
}
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
      cout << "Default Size of the Stack is 5000\n";
      size = 5000;
      top = -1;
      arr = new X[size];
   }
   stack(int n)
   {
      cout << "Size of the stack=" << n << endl;
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
int height(node *p)
{
   return (p == NULL) ? 0 : max(height(p->left) + 1, height(p->right) + 1);
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
void levelOrder2(node *p)
{
   int h = height(p);
   for (int i = 1; i <= h; i++)
   {
      printLevel(p, i);
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
node *cloneLeftRight(node *p, unordered_map<node *, node *> &m)
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
}
void cloneRandom(node *p, unordered_map<node *, node *> &m)
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
}
int main()
{
   root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->left->left->random = root;
   root->left->right->random = root->right;
   root->random = root->left->right;
   node *clone = cloneBTree(root);
   levelOrder1(clone);
   return 0;
}
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