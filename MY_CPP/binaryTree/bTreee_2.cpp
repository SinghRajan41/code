#include <iostream>
using namespace std;
class node
{
public:
   int data;
   node *left, *right;
} *root = NULL;
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
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main()
{
   createTree();
   int x = INT32_MIN;
   diameter2(root, &x);
   cout << "\ndiameter=" << x << endl;
   return 0;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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