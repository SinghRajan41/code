#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next, *prev;
};
node *append(node *head, int value);
node *create(int arr[], int n);
void printLL(node *head);
node *remove(node *head, int key);
void reverseLL(node *i, node *j, node **head);
node *reverseLL2(node *head);

int main()
{
   node *head = NULL;
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   head = create(arr, 7);
   head = reverseLL2(head);
   printLL(head);
   return 0;
}
node *reverseLL2(node *head)
{
   if (head == NULL)
   {
      return head;
   }
   else if (head->next == NULL)
   {
      return head;
   }
   else
   {
      node *i, *j, *temp;
      i = head;
      j = head->next;
      while (j != NULL)
      {
         // Swap i's prev and next
         temp = i->next;
         i->next = i->prev;
         i->prev = temp;
         i = j;
         j = j->next;
      }
      temp = i->next;
      i->next = i->prev;
      i->prev = temp;
      return i;
   }
}
void reverseLL(node *i, node *j, node **head)
{
   if (j != NULL)
   {
      reverseLL(j, j->next, head);
   }
   if (j == NULL)
   {
      *head = i;
   }
   // Swapping previous and next of i
   node *temp = i->next;
   i->next = i->prev;
   i->prev = temp;
}
node *remove(node *head, int key)
{
   if (head == NULL)
   {
      return head;
   }
   else if (head->next == NULL)
   {
      if (head->data == key)
      {
         delete head;
         head = NULL;
         return head;
      }
      else
      {
         return head;
      }
   }
   node *i = head;
   while (i != NULL && i->data != key)
   {

      i = i->next;
   }
   if (i == NULL)
   {
      return head;
   }
   else if (head == i)
   {
      head = head->next;
      if (head)
         head->prev = NULL;
      delete i;
      return head;
   }

   else if (i->next == NULL)
   {
      i->prev->next = NULL;
      delete i;
      return head;
   }
   else if (i->next != NULL && i->prev != NULL)
   {
      i->prev->next = i->next;
      i->next->prev = i->prev;
      delete i;
      return head;
   }
}
node *create(int arr[], int n)
{
   node *a, *b, *c;
   a = new node;
   a->next = a->prev = NULL;
   a->data = arr[0];
   c = a;
   for (int i = 1; i < n; i++)
   {
      b = new node;
      b->data = arr[i];
      b->next = b->prev = NULL;
      c->next = b;
      b->prev = c;
      c = b;
   }
   return a;
}
void printLL(node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
}
node *append(node *head, int value)
{
   node *a = new node;
   a->data = value;
   a->next = a->prev = NULL;
   if (head == NULL)
   {
      head = a;
   }
   else
   {
      node *b = head;
      while (b->next != NULL)
      {
         b = b->next;
      }
      b->next = a;
      a->prev = b;
   }
   return head;
}