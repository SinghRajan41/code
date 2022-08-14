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
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main()
{
   createTree();
   cout << root->data;
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