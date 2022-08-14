#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
node *temp;
node *create(int arr[], int n);
void printLL(node *head);
node *getLast(node *head);
node *reverseLL(node *head);
void reverseLL2(node *i, node *j, node **head);
bool detectCycle1(node *head);
bool detectCycle2(node *head);
bool detectCycle3(node *head);
node *addLL(node *h1, node *h2);
node *addLL2(node *h1, node *h2);
node *rotateLL(node *head, int k);
node *groupedReverse(node *head, int k);
template <class X>
class snode
{
public:
   snode<X> *next;
   X data;
};
template <class X>
class stack
{
   snode<X> *top, *a, *b;

public:
   stack()
   {
      top = NULL;
   }
   void push(X value);
   X pop();
   X peektop();
   int isEmpty();
};
class hashh
{
   int size;
   int *h;

public:
   hashh(int x)
   {
      x *= 2;
      x += 10;
      bool temp[x + 1];
      for (int i = 0; i <= x; i++)
      {
         temp[i] = 0;
      }
      for (int i = 2; i <= x; i++)
      {
         if (temp[i] == 0)
         {
            for (int j = i * i; j <= x; j += i)
            {
               temp[j] = 1;
            }
         }
      }
      for (int i = x; i >= 1; i--)
      {
         if (temp[i] == 0)
         {
            size = i;
            break;
         }
      }
      h = new int[size + 1];
      for (int i = 0; i <= size; i++)
      {
         h[i] = -1;
      }
   }
   int hfunc(int x)
   {
      return x % size;
   }
   void insert(int value);
   void display();
   bool elementPresent(int x);
};
//###########################START OF MAIN FUNCTION

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
   node *head = create(arr, 14);
   // head = groupedReverse(head, 4);
   printLL(head);

   return 0;
}

//#####################################END OF MAIN FUNCTION
node *groupedReverse(node *head, int k)
{
   if (head == NULL || head->next == NULL)
   {
      return head;
   }
   node *prev, *cur, *next;
   cur = head;
   next = head;
   prev = next = NULL;
   int count = 0;
   while (next != NULL && count < k)
   {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      count++;
   }
   if (next != NULL)
   {
      head->next = groupedReverse(next, k);
   }
   return prev;
}
void reverseLL2(node *i, node *j, node **head)
{
   if (j->next != NULL)
   {
      reverseLL2(j, j->next, head);
   }
   if (j->next == NULL)
   {
      *head = j;
   }
   j->next = i;
}
node *rotateLL(node *head, int k)
{
   node *i, *l, *x;
   l = head;
   i = head;
   while (l->next != NULL)
   {
      l = l->next;
   }
   l->next = i;
   k -= 1;
   for (; k--;)
   {
      i = i->next;
   }
   x = i->next;
   i->next = NULL;
   return x;
}
node *addLL2(node *h1, node *h2)
{
   stack<int> s1, s2, s3;
   node *i, *j;
   i = h1;
   j = h2;
   while (i)
   {
      s1.push(i->data);
      i = i->next;
   }
   while (j)
   {
      s2.push(j->data);
      j = j->next;
   }
   int carry = 0;
   while (!s1.isEmpty() || !s2.isEmpty())
   {
      int ans = 0;
      ans += carry;
      if (!s1.isEmpty())
      {
         ans += s1.pop();
      }
      if (!s2.isEmpty())
      {
         ans += s2.pop();
      }
      s3.push(ans % 10);
      carry = ans / 10;
   }
   if (carry != 0)
   {
      while (carry != 0)
      {
         s3.push(carry);
         carry = carry / 10;
      }
   }
   node *res = new node;
   res->next = NULL;
   res->data = s3.pop();
   node *last = res;
   while (!s3.isEmpty())
   {
      node *temp = new node;
      temp->next = NULL;
      temp->data = s3.pop();
      last->next = temp;
      last = temp;
   }
   return res;
}
template <class X>
void stack<X>::push(X value)
{
   a = new snode<X>;
   a->next = NULL;
   a->data = value;
   if (top == NULL)
   {
      top = a;
   }
   else
   {
      a->next = top;
      top = a;
   }
}
template <class X>
X stack<X>::pop()
{
   X junk;
   if (top != NULL)
   {
      junk = top->data;
      a = top;
      top = top->next;
      delete a;
   }
   return junk;
}
template <class X>
X stack<X>::peektop()
{
   if (top == NULL)
   {
      X junk;
      return junk;
   }
   else
   {
      return top->data;
   }
}
template <class X>
int stack<X>::isEmpty()
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
node *addLL(node *h1, node *h2)
{
   h1 = reverseLL(h1);
   h2 = reverseLL(h2);
   int carry = 0;
   node *res = new node;
   res->next = NULL;
   node *last = res;
   node *i, *j;
   i = h1;
   j = h2;
   while (i || j)
   {
      int ans = 0;
      if (i)
      {
         ans += i->data;
         i = i->next;
      }
      if (j)
      {
         ans += j->data;
         j = j->next;
      }
      // Writing code for pushing back in the end of result
      node *temp = new node;
      temp->next = NULL;
      temp->data = ans % 10;
      last->next = temp;
      last = temp;
      carry = ans / 10;
   }
   res = reverseLL(res->next);
   return res;
}

node *reverseLL(node *head)
{
   if (!head)
   {
      return NULL;
   }
   else if (head->next == NULL)
   {
      return head;
   }
   else
   {
      node *prev, *cur, *next;
      next = head;
      prev = cur = NULL;
      while (next != NULL)
      {
         prev = cur;
         cur = next;
         next = next->next;
         cur->next = prev;
      }
      return cur;
   }
}
bool detectCycle3(node *head)
{
   hashh h(100);
   node *i = head;
   h.insert(int(i));
   bool ok = false;
   while (i != NULL)
   {

      if (i->next)
      {
         cout << "x";

         if (h.elementPresent(int(i->next)))
         {

            i->next = NULL;
            return true;
         }
         else
         {
            i = i->next;
         }
      }
      else
      {

         return false;
      }
   }
}
bool hashh::elementPresent(int x)
{
   x = hfunc(x);
   return h[x] == -1 ? false : true;
}
void hashh::display()
{
   for (int i = 1; i <= size; i++)
   {
      cout << h[i] << " ";
   }
}
void hashh::insert(int value)
{
   int x = hfunc(value);
   if (h[x] == -1)
   {
      h[x] = value;
   }
   else
   {
      while (h[x] != -1 && x < size)
      {
         x++;
      }
      if (x >= size)
      {
         cout << "\nHash Table is full";
      }
      else
      {
         h[x] = value;
      }
   }
}
node *create(int arr[], int n)
{
   node *a, *b, *c;
   a = new node;
   a->next = NULL;
   a->data = arr[0];
   b = a;
   for (int i = 1; i < n; i++)
   {
      c = new node;
      c->data = arr[i];
      c->next = NULL;
      b->next = c;
      b = c;
   }
   return a;
}
void printLL(node *head)
{
   while (head)
   {
      cout << head->data << " ";
      head = head->next;
   }
}
node *getLast(node *head)
{
   node *i = head;
   while (i->next != NULL)
   {
      i = i->next;
   }
   return i;
}
bool detectCycle2(node *head)
{
   // Using a visited array to check for cycle
   bool v[10000] = {0};
   node *i = head;
   v[i->data] = 1;
   while (i != NULL)
   {
      if (i->next)
      {
         if (v[i->next->data] == 0)
         {
            i = i->next;
            v[i->data] = 1;
         }
         else
         {
            break;
         }
      }
      else
      {
         i = NULL;
         break;
      }
   }
   if (i)
   {
      i->next = NULL;
      return true;
   }
   else
   {
      return false;
   }
}
bool detectCycle1(node *head)
{
   node *p, *fast, *slow, *i, *x, *l;
   bool cycle = false, ok = false;
   fast = slow = head;
   while (fast && slow)
   {
      slow = slow->next;
      if (fast->next)
      {
         fast = fast->next;
      }
      else
      {
         return false;
      }
      if (fast->next)
      {
         fast = fast->next;
      }
      else
      {
         return false;
      }
      if (fast == slow)
      {
         p = fast;
         cycle = true;
         break;
      }
   }
   // Cycle has been detected
   i = head;
   while (i)
   {
      x = p;
      ok = false;
      while (x->next != p)
      {
         if (x == i)
         {
            ok = true;
            break;
         }
         else
         {
            x = x->next;
         }
      }
      if (ok)
      {
         l = i;
         break;
      }
      else
      {
         i = i->next;
      }
   }
   x = l;
   while (x->next != l)
   {
      x = x->next;
   }
   x->next = NULL;
   return cycle;
}