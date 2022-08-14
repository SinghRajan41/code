/*#include <iostream>
using namespace std;
struct node
{
   node *next;
   int data;
};
void insert(node **b, int value);
void remove(node **b, int pos);
void bucketSort(int arr[], int n)
{
   int m = -999999;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   node **b;
   b = new node *[m + 1];
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
            remove(b, i);
         }
      }
   }
   delete[] b;
   b = NULL;
}
void insert(node **b, int value)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = value;
   if (b[value] == NULL)
   {
      b[value] = temp;
      return;
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
void remove(node **b, int pos)
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
      node *a, *c;
      a = b[pos];
      c = a->next;
      while (c->next != NULL)
      {
         a = c;
         c = c->next;
      }
      delete c;
      a->next = NULL;
   }
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      arr[i] = 100000 - i;
   }
   bucketSort(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}*/

#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
void insert(node **b, int value);
void remove(node **b, int value);
void binBucketSort(int arr[], int n);
void insert(node **b, int value)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = value;
   if (b[value] == NULL)
   {
      b[value] = temp;
      return;
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
void remove(node **b, int value)
{
   if (b[value] == NULL)
   {
      cout << "x";
      return;
   }
   else if (b[value]->next = NULL)
   {
      cout << "y";
      delete b[value];
      b[value] = NULL;
   }
   else
   {
      cout << "z";
      node *a, *c;
      a = b[value];
      c = a->next;
      while (c->next != NULL)
      {
         a = c;
         c = c->next;
      }
      delete c;
      a->next = NULL;
   }
}
void binBucketSort(int arr[], int n)
{
   int m = -999999, k = 0;
   node **b = NULL;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   b = new node *[m + 1];
   for (int i = 0; i <= m; i++)
   {
      b[i] = NULL;
   }
   for (int i = 0; i < n; i++)
   {
      insert(b, arr[i]);
   }

   for (int i = 1; i <= m; i++)
   {
      if (b[i] != NULL)
      {
         while (b[i] != NULL)
         {
            cout << "Hola";
            arr[k++] = i;
            cout << "Hola";
            remove(b, i);
         }
      }
   }
}
int main()
{
   int arr[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   int n = sizeof(arr) / sizeof(arr[0]);
   binBucketSort(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}