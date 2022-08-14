#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
class hashTable
{
   node **arr;
   int size;

public:
   hashTable(int n)
   {
      arr = new node *[n];
      for (int i = 0; i < n; i++)
      {
         arr[i] = NULL;
      }
      size = n;
   }
   int hash_func(int n);
   void sortedInsert(int value);
   void sortedDelete(int value);
   void displayHash();
};
int main()
{
   hashTable h(10);
   for (int i = 1; i <= 100; i++)
   {
      h.sortedInsert(i);
   }
   h.displayHash();
   return 0;
}
void hashTable::sortedDelete(int value)
{
   int idx = hash_func(value);
   if (arr[idx] == NULL)
   {
      return;
   }
   else
   {
      node *a = arr[idx];
      node *b = a;
      if (a->data == value)
      {
         arr[idx] = a->next;
         return;
      }
      else
      {
         while (a->data != value && a != NULL)
         {
            b = a;
            a = a->next;
         }
         if (a)
         {
            if (a == b)
            {
               delete a;
               arr[idx] = NULL;
            }
            b->next = a->next;
            delete a;
            return;
         }
      }
   }
}
void hashTable::displayHash()
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] != NULL)
      {
         node *a = arr[i];
         cout << i << " :: ";
         while (a)
         {
            cout << a->data << " ";
            a = a->next;
         }
         cout << endl;
      }
      else
      {
         cout << i << "::\n";
      }
   }
}
void hashTable::sortedInsert(int value)
{
   int idx = hash_func(value);
   node *temp = new node;
   temp->next = NULL;
   temp->data = value;
   if (arr[idx] == NULL)
   {
      arr[idx] = temp;
      arr[idx]->next = NULL;
      return;
   }
   else
   {
      if (arr[idx]->data >= value)
      {
         temp->next = arr[idx];
         arr[idx] = temp;
         return;
      }
      node *a = arr[idx];
      node *b = a;
      while (a != NULL && a->data < value)
      {
         b = a;
         a = a->next;
      }
      b->next = temp;
      temp->next = a;
   }
}
int hashTable::hash_func(int n)
{
   return n % 10;
}
