#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
class linked_list
{
   node *first = NULL, *last = NULL, *temp = NULL, *p, *a, *b, *c, *d, *x, *y;

public:
   linked_list()
   {
      cout << "Welcome to linked list class!\n";
   }
   void append(int value);
   void display();
   void create(int arr[], int n);
   void insert(int pos, int value);
   int count();
   int countr(node *p);
   void displayr(node *p);
   node *getfirst() { return first; }
   int sum();
   int sumr(node *p);
   int max();
   int maxr(node *p);
   void insert_sorted(int value);
   void remove(int key);
   void dlt(int pos);
   bool check_sorted(node *p);
   void remove_dup();
   void remove_dup2();
   void reverse1();
   void reverse2();
   void reverse3(node *a, node *b = NULL);
   void concatenate(linked_list a);
   void merge(linked_list &obj);
};

// MAIN FUNCTION ############################ MAIN FUNCTION #########################MAIN FUNCTION  #######################  MAIN FUNCTION
int main()
{
   linked_list ll;
   for (int i = 0; i < 20; i++)
   {
      ll.append(i + 1);
   }
   ll.display();
   return 0;
}
// MAIN FUNCTION ############################ MAIN FUNCTION #########################MAIN FUNCTION  #######################  MAIN FUNCTION

void linked_list::swap(int n1, int n2)
{
   a = first;
   c = first;
   d = b = first;
   a = c = NULL;
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
   x = b->next;
   y = d->next;
   a->next = d;
   c->next = b;
   d->next = x;
   b->next = y;
}
void linked_list::merge(linked_list &obj)
{
   a = this->first;
   b = obj.getfirst();
   c = a->data < b->data ? a : c;
}
void linked_list::concatenate(linked_list a)
{
   this->p = this->first;
   while (this->p->next != NULL)
   {
      this->p = this->p->next;
   }
   this->p->next = a.getfirst();
}
void linked_list::reverse3(node *a, node *b)
{
   if (a != NULL)
   {
      reverse3(a->next, a);
      a->next = b;
   }
   else
   {
      first = b;
   }
}
void linked_list::reverse1()
{
   int n = 0;
   p = first;
   while (p != NULL)
   {
      n++;
      p = p->next;
   }
   int *arr = new int[--n];
   n = 0;
   p = first;
   while (p != NULL)
   {
      *(arr + n++) = p->data;
      p = p->next;
   }
   n--;
   p = first;
   while (p != NULL)
   {
      p->data = *(arr + n--);
      p = p->next;
   }
   delete[] arr;
}
void linked_list::reverse2()
{
   node *a, *b, *c;
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
void linked_list::remove_dup2()
{
   node *a, *b, *c;
   a = first;
   b = first;
   c = first;
   while (a != NULL)
   {
      b = a->next;
      while (b != NULL)
      {
         if (b->data == a->data)

         {
            c->next = b->next;
            temp = b;
            b = b->next;
            delete temp;
         }
         else
         {
            // Write a Code to Continue
            c = b;
            b = b->next;
         }
      }
      a = a->next;
      c = a;
   }
}
void linked_list::remove_dup()
{
   short int hash[10000] = {0};
   p = first;
   while (p != NULL)
   {
      hash[p->data]++;
      p = p->next;
   }

   p = first;
   while (p != NULL)
   {

      if (hash[p->data] == 1)
      {
         if (p != *a)
         {
            *a = p;
            p = p->next;
            continue;
         }
         p = p->next;
         continue;
      }
      else if (hash[p->data] > 1)
      {
         hash[p->data] = -1;
         if*a != p)
            {
               *a = p;
               p = p->next;
               continue;
            }
         p = p->next;
         continue;
      }
      else if (hash[p->data] == -1)
      {
         *a->next = p->next;
         temp = p;
         p = p->next;
         delete temp;
         continue;
      }
   }
}
bool linked_list::check_sorted(node *p)
{
   int prev = -32576;
   while (p != NULL)
   {
      if (prev > p->data)
      {
         return 0;
      }
      else
      {
         prev = p->data;
         p = p->next;
      }
   }
   return 1;
}
void linked_list::dlt(int pos)
{
   if (first == NULL)
   {
      cout << "Empty Linked List\n";
      return;
   }
   if (pos == 1)
   {
      temp = first;
      first = first->next;
      delete temp;
   }
   p = first;
   temp = first;
   pos--;
   while (pos-- && p != NULL)
   {
      temp = p;
      p = p->next;
   }
   if (p == NULL)
   {
      return;
   }
   temp->next = p->next;
   delete p;
}
void linked_list::remove(int key)
{
   if (first == NULL)
   {
      cout << "Empty Linked List!\n";
      return;
   }
   p = first;
   temp = first;
   if (first->data == key)
   {
      first = first->next;
      delete p;
      return;
   }
   while (p != NULL && p->data != key)
   {
      temp = p;
      p = p->next;
   }
   if (p == NULL)
   {
      return;
   }
   else
   {
      temp->next = p->next;
      delete p;
   }
}

void linked_list::insert_sorted(int value)
{

   if (first == NULL)
   {
      append(value);
      return;
   }
   p = first;
   *a = first;
   temp = new node;
   while (value > p->data && p != NULL)
   {
      *a = p;
      p = p->next;
   }
   *a->next = temp;
   temp->data = value;
   temp->next = p;
}
int linked_list::maxr(node *p)
{
   if (p == NULL)
   {
      return -11111111;
   }
   int m = maxr(p->next);
   m = m > p->data ? m : p->data;
   return m;
}

int linked_list::max()
{
   int m = -32765;
   p = first;
   while (p != NULL)
   {
      m = m > p->data ? m : p->data;
      p = p->next;
   }
   return m;
}
int linked_list::sum()
{
   int rvalue = 0;
   p = first;
   while (p != NULL)
   {
      rvalue += p->data;
      p = p->next;
   }
   return rvalue;
}
int linked_list::sumr(node *p)
{
   if (p == NULL)
   {
      return 0;
   }
   return p->data + sumr(p->next);
}

int linked_list::countr(node *p)
{
   if (p == NULL)
   {
      return 0;
   }
   return 1 + countr(p->next);
}

void linked_list::displayr(node *p)
{

   if (p == NULL)
   {
      return;
   }
   cout << p->data << " ";
   displayr(p->next);
}
int linked_list::count()
{
   int c = 0;
   p = first;
   if (p == NULL)
   {
      return 0;
   }
   else
   {
      while (p != NULL)
      {
         c++;
         p = p->next;
      }
   }
   return c;
}

void linked_list::insert(int pos, int value)
{
   if (first == NULL)
   {
      append(value);
      return;
   }

   if (pos == 0)
   {
      temp = new node;
      temp->next = first;
      temp->data = value;
      first = temp;
      return;
   }
   temp = first;
   p = first;
   while (pos-- && p != NULL)
   {
      temp = p;
      p = p->next;
   }
   *a = new node;
   temp->next *a;
   *a->data = value;
   *a->next = p;
}
void linked_list::create(int *arr, int n)
{
   if (first == NULL)
   {
      append(arr[0]);
      create(arr + 1, n - 1);
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         temp = new node;
         temp->next = NULL;
         temp->data = arr[i];
         last->next = temp;
         last = temp;
      }
   }
}
void linked_list::append(int value)
{
   temp = new node;
   if (first == NULL)
   {

      first = temp;
      last = first;
      first->next = NULL;
      first->data = value;
      return;
   }
   else
   {
      temp->next = NULL;
      temp->data = value;
      last->next = temp;
      last = temp;
   }
}
void linked_list::display()
{
   if (first == NULL)
   {
      cout << "Empty Linked List\n";
      return;
   }
   temp = first;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
}