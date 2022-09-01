#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
node *create(int arr[], int n);
void printLL(node *head);
node *insert(node *head, int value);
node *sortedInsert(int value, node *head);
void split(node *head, node **h1, node **h2);
int main()
{
   // int arr[5] = {1, 2, 3, 4, 5};
   // node *head = create(arr, 5);
   // head = sortedInsert(6, head);
   // head = sortedInsert(7, head);
   // printLL(head);
   node *head = NULL;
   head = sortedInsert(5, head);
   head = sortedInsert(6, head);
   head = sortedInsert(4, head);
   head = sortedInsert(21, head);
   head = sortedInsert(23, head);
   node *h1, *h2;
   printLL(head);
   split(head, &h1, &h2);

   cout << endl;
   printLL(h1);
   cout << endl;
   printLL(h2);
   return 0;
}
void split(node *head, node **h1, node **h2)
{
   node *s, *f;
   s = f = head;
   while (f->next != head && f->next->next != head)
   {
      f = f->next->next;
      s = s->next;
   }
   if (f->next->next == head)
   {
      f = f->next;
   }
   *h1 = head;
   *h2 = s->next;
   f->next = s->next;
   s->next = head;
}
node *sortedInsert(int value, node *head)
{
   node *a = new node;
   a->data = value;
   if (head == NULL)
   {
      a->next = a;
      return a;
   }
   else
   {
      node *i = head;
      if (value <= head->data)
      {

         while (i->next != head)
         {
            i = i->next;
         }
         i->next = a;
         a->next = head;
         head = a;
         return head;
      }

      else
      {
         while (value > i->next->data && i->next != head)
         {
            i = i->next;
         }
         a->next = i->next;
         i->next = a;
         return head;
      }
   }
}
void printLL(node *head)
{
   node *i = head;
   do
   {
      cout << i->data << " ";
      i = i->next;
   } while (i != head);
}
node *insert(node *head, int value)
{
   node *a = new node;
   a->data = value;
   a->next = NULL;
   if (head == NULL)
   {
      head = a;
      a->next = a;
      return head;
   }
   else
   {
      a->next = head->next;
      head->next = a;
      return head;
   }
}
node *create(int arr[], int n)
{

   node *a, *b, *c;
   a = new node;
   a->next = NULL;
   a->data = arr[0];
   c = a;
   if (n == 0)
   {
      return a;
   }
   else if (n == 1)
   {
      c->next = a;
      return c;
   }
   else
   {
      for (int i = 1; i < n; i++)
      {
         b = new node;
         b->next = NULL;
         b->data = arr[i];
         c->next = b;
         c = b;
      }
   }
   c->next = a;
   return a;
}
