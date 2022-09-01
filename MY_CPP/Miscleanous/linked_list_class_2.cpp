#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
class linked_list
{
   node *first, *last, *a, *b, *c, *temp, *d, *x, *y;

public:
   linked_list()
   {
      cout << "Welcome to the linked list Class\n";
      first = NULL;
      last = NULL;
   }
   void append(int value);
   node *getfirst();
   void display();
   void create(int arr[], int n);
   void insert(int pos, int value);
   int count();
   int countr(node *a);
   void displayr(node *a);
   int sum();
   int sumr(node *a);
   int max();
   int maxr(node *a);
   void remove(int key);
   void dlt(int pos);
   bool check_sorted();
   void remove_dup();
   void remove_dup2();
   void reverse1();
   void reverse2(node *a, node *b = NULL);
   void reverse3();
   void concatenate(linked_list &obj);
   void merge(linked_list &obj); // Definition of the function is commented temporarily
   void sortedMerge(linked_list &obj);
   void swap(int n1, int n2);
};

//#############################################
int main()
{
   linked_list ll, kk;
   int a[] = {1, 2, 3};
   int b[] = {4, 5, 6};
   ll.create(a, 3);
   kk.create(b, 3);
   ll.sortedMerge(kk);
   return 0;
}
//####################################################

void linked_list::sortedMerge(linked_list &obj)
{
   a = this->getfirst();
   b = obj.getfirst();
   node *dummy, *tail;
   tail = dummy;

   while (a != NULL && b != NULL)
   {
      if (a->data < b->data)
      {
         tail->next = a;
         a = a->next;
      }
      else
      {
         tail->next = b;
         b = b->next;
      }
      tail = tail->next;
   }
   // while (a != NULL)
   // {
   //    tail->next = a;
   //    a = a->next;
   //    tail = tail->next;
   // }
   // while (b != NULL)
   // {
   //    tail->next = b;
   //    b = b->next;
   //    tail = tail->next;
   // }
   tail->next = NULL;
   // displayr(dummy->next);
}
void linked_list::swap(int n1, int n2)
{
   b = d = first;
   c = a = NULL;
   int zz = n1;
   if (n1 > n2)
   {
      n1 = n2;
      n2 = zz;
   }
   while (b->data != n1)
   {
      a = b;
      b = b->next;
   }
   while (d->data != n2)
   {
      c = d;
      d = d->next;
   }
   // Element not present
   if (a->next == NULL && b == NULL)
   {
      return;
   }
   if (d == NULL && c->next == NULL)
   {
      return;
   }
   if (d == NULL && b == NULL && c->next == NULL && a->next == NULL)
   {
      return;
   }
   if (!a && b == c && b->next == d)
   {
      // First and adjacent
      y = d->next;
      d->next = b;
      b->next = y;
      first = d;
      return;
   }
   if (a == NULL && b->next->data != n2 && b && c && d)
   {
      // First and not adjacent
      y = d->next;
      d->next = c;
      c->next = b;
      b->next = y;
      first = d;
      cout << "lol";
      return;
   }
   if (b == c && c->next == d && a->next == b && a && b && c && d)
   {
      // Swapping for in between adjacent case
      x = c->next;
      y = d->next;
      a->next = x;
      d->next = b;
      b->next = y;
      return;
   }
   // Swapping in general case
   x = b->next;
   y = d->next;
   a->next = d;
   c->next = b;
   d->next = x;
   b->next = y;
}
// void linked_list::merge(linked_list &obj)
// {
//    a = this->first;
//    b = obj.getfirst();
//    c = a->data < b->data ? a : b;
//    this->first = c;
//    while (a != NULL && b != NULL)
//    {
//       if (a->data < b->data)
//       {
//          c->next = a;
//          c = a;
//          a = a->next;
//       }
//       else
//       {
//          c->next = b;
//          c = b;
//          b = b->next;
//       }
//    }
//    if (b == NULL)
//    {
//       c->next = a;
//    }
//    else
//    {
//       c->next = b;
//    }
// }
void linked_list::concatenate(linked_list &obj)
{
   a = this->first;
   while (a->next != NULL)
   {
      a = a->next;
   }
   a->next = obj.getfirst();
}
void linked_list::reverse2(node *a, node *b)
{
   if (a != NULL)
   {
      reverse2(a->next, a);
      a->next = b;
   }
   else
   {
      first = b;
   }
}
void linked_list::reverse3()
{
   a = first;
   b = NULL;
   c = NULL;
   while (a != NULL)
   {
      c = b;
      b = a;
      a = a->next;
      b->next = c;
   }
   first = b;
}
void linked_list::reverse1()
{
   a = first;
   int n = 0;
   while (a != NULL)
   {
      n++;
      a = a->next;
   }
   int arr[--n];
   n = 0;
   a = first;
   while (a != NULL)
   {
      arr[n++] = a->data;
      a = a->next;
   }
   n--;
   a = first;
   while (a != NULL)
   {
      a->data = arr[n--];
      a = a->next;
   }
}
void linked_list::remove_dup2()
{
   a = first;
   b = NULL;
   c = NULL;
   while (a != NULL)
   {
      b = a->next;
      c = a;
      while (b != NULL)
      {
         if (b->data != a->data)
         {
            c = b;
            b = b->next;
         }
         else
         {
            c->next = b->next;
            temp = b;
            b = b->next;
            delete temp;
         }
      }
      a = a->next;
   }
}
void linked_list::remove_dup()
{
   short int hash[10000] = {0};
   a = first;
   while (a != NULL)
   {
      hash[a->data]++;
      a = a->next;
   }
   a = first;
   b = first;
   while (a != NULL)
   {
      if (hash[a->data] == 1)
      {
         b = a;
         a = a->next;
      }
      else if (hash[a->data] > 1)
      {
         hash[a->data] = -1;
         b = a;
         a = a->next;
      }
      else if (hash[a->data] == -1)
      {
         b->next = a->next;
         c = a;
         a = a->next;
         delete c;
      }
   }
}
bool linked_list::check_sorted()
{
   a = first;
   b = first;
   while (a != NULL)
   {
      if (a->data < b->data)
      {
         return false;
      }
      else
      {
         b = a;
         a = a->next;
      }
   }
   return true;
}
void linked_list::dlt(int pos)
{
   a = first;
   b = first;
   if (pos == 0)
   {
      first = first->next;
      delete a;
      return;
   }
   while (a != NULL && pos--)
   {
      b = a;
      a = a->next;
   }
   if (a)
   {
      b->next = a->next;
      delete a;
   }
}
void linked_list::remove(int key)
{
   a = first;
   b = first;
   while (a != NULL and a->data != key)
   {
      b = a;
      a = a->next;
   }
   if (a == NULL)
   {
      return;
   }
   if (a == b)
   {
      first = first->next;
      delete a;
   }
   else
   {
      b->next = a->next;
      if (a->next == NULL)
         ;
      {
         last = b;
      }
      delete a;
   }
}

int linked_list::maxr(node *a)
{
   if (a == NULL)
   {
      return -1111111;
   }
   int m = maxr(a->next);
   return a->data > m ? a->data : m;
}
int linked_list::max()
{
   a = first;
   int m = -11111111;
   while (a != NULL)
   {
      m = m > a->data ? m : a->data;
      a = a->next;
   }
   return m;
}
int linked_list::sumr(node *a)
{
   return a == NULL ? 0 : a->data + sumr(a->next);
}
int linked_list::sum()
{
   a = first;
   int s = 0;
   if (first == NULL)
   {
      return 0;
   }
   while (a != NULL)
   {
      s += a->data;
      a = a->next;
   }
   return s;
}
void linked_list::displayr(node *a)
{
   if (a == NULL)
   {
      return;
   }
   cout << a->data << " ";
   displayr(a->next);
}
int linked_list::countr(node *a)
{
   return a == NULL ? 0 : 1 + countr(a->next);
}
int linked_list::count()
{
   if (first == NULL)
   {
      return 0;
   }
   int n = 0;
   a = first;
   while (a != NULL)
   {
      n++;
      a = a->next;
   }
   return n;
}
void linked_list::insert(int pos, int value)
{
   if (pos == 0)
   {
      a = new node;
      a->data = value;
      a->next = first;
      first = a;
      return;
   }
   a = first;
   b = NULL;
   while (a != NULL && pos--)
   {
      b = a;
      a = a->next;
   }
   if (a == NULL)
   {
      c = new node;
      c->next = NULL;
      c->data = value;
      b->next = c;
      last = c;
   }
   else
   {
      c = new node;
      c->data = value;
      c->next = a;
      b->next = c;
   }
}
void linked_list::create(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      append(arr[i]);
   }
}
void linked_list::display()
{
   a = first;
   while (a != NULL)
   {
      cout << a->data << " ";
      a = a->next;
   }
}
node *linked_list::getfirst()
{
   return first;
}
void linked_list::append(int value)
{
   a = new node;
   a->next = NULL;
   a->data = value;
   if (first == NULL)
   {
      first = a;
      last = a;
   }
   else
   {
      b = first;
      while (b->next != NULL)
      {
         b = b->next;
      }
      b->next = a;
   }
}
