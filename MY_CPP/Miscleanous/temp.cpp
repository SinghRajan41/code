#include <iostream>
using namespace std;
struct node
{
   node *next;
   int data;
};
void insert(node **b, int value);
void removee(node **b, int pos);
void bucketSort(int arr[], int n)
{
   int m = -99999;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   node **b = new node *[m + 1];
   for (int i = 0; i <= m; i++)
   {
      b[i] = NULL;
   }
   for (int i = 0; i < n; i++)
   {
      insert(b, arr[i]);
   }
   int k = 0;
   for (int i = 0; i <= m; i++)
   {
      if (b[i] != NULL)
      {
         while (b[i] != NULL)
         {
            arr[k++] = b[i]->data;
            removee(b, b[i]->data);
         }
      }
   }

   // Debugging code
   // for (int i = 0; i <= m; i++)
   // {
   //    if (b[i] != NULL)
   //    {
   //       if (b[i]->next == NULL)
   //       {
   //          cout << b[i]->data << " ";
   //       }
   //    }
   // }
   delete[] b;
   b = NULL;
}
void removee(node **b, int pos)
{
   if (b[pos] == NULL)
   {
      return;
   }
   else if (b[pos]->next == NULL)
   {
      delete b[pos];
      b[pos] = NULL;
   }
   else
   {
      node *l, *m;
      l = b[pos];
      m = l->next;
      while (m->next != NULL)
      {
         l = m;
         m = m->next;
      }
      delete m;
      l->next = NULL;
   }
}
void insert(node **b, int value)
{
   node *temp = new node;
   temp->data = value;
   temp->next = NULL;
   if (b[value] == NULL)
   {
      b[value] = temp;
   }
   else
   {
      node *a = b[value];
      while (a->next != NULL)
      {
         a = a->next;
      }
      a->next = temp;
   }
}
int main()
{
   int arr[12] = {12, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 1};
   bucketSort(arr, 12);
   for (int i = 0; i < 12; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}