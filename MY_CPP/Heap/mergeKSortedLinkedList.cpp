#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
node *newNode(int value);
void printLL(node *head);
node *arrayToLinked(int temp[], int size);
class minHeap
{
public:
   node **harr;
   int n, size;
   minHeap()
   {
      harr = new node *[10000];
      size = 10;
      n = -1;
   }
   void insert(node *head)
   {
      if (n == size - 1)
      {
         cout << "\nHeap is Full\n";
         return;
      }
      harr[++n] = head;
      int i = n;
      while (i > 0)
      {
         if (harr[i]->data < harr[(i - 1) / 2]->data)
         {
            swap(harr[i], harr[(i - 1) / 2]);
         }
         i = (i - 1) / 2;
      }
   }
   void pushDown(int i)
   {
      int j = 2 * j + 1;
      if (j + 1 <= n && harr[j + 1]->data < harr[j]->data)
      {
         j++;
      }
      if (j <= n && harr[j]->data < harr[(j - 1) / 2]->data)
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
      }
   }
   void deleteRoot()
   {
      if (n <= -1)
      {
         return;
      }
      else if (n == 0)
      {
         n--;
      }
      else
      {
         swap(harr[0], harr[n]);
         n--;
         pushDown(0);
      }
   }
   void mergeKLL(node *arr[], int r, int c)
   {
      for (int i = 0; i < r; i++)
      {
         insert(arr[i]);
      }
      while (n != 0)
      {
         cout << harr[0]->data << " ";
         harr[0] = harr[0]->next;
         if (harr[0] == NULL)
         {
            deleteRoot();
         }
         else
         {
            pushDown(0);
         }
      }
      node *a = harr[0];
      while (a != NULL)
      {
         cout << a->data << " ";
         a = a->next;
      }
   }
   void showHeap()
   {
      for (int i = 0; i <= n; i++)
      {
         cout << harr[i]->data << " ";
      }
   }
};
int main()
{
   int r, c;
   // cout << "\nEnter the number of rows=\n";
   cin >> r;
   // cout << "\nEnter the number of columns=\n";
   cin >> c;
   node *arr[r]; // Array of linked list
   for (int i = 0; i < r; i++)
   {
      int temp[c];
      for (int i = 0; i < c; i++)
      {
         cin >> temp[i];
      }
      arr[i] = arrayToLinked(temp, c);
   }
   minHeap h;
   h.mergeKLL(arr, r, c);

   return 0;
}
node *arrayToLinked(int temp[], int size)
{
   if (size == 0)
   {
      return NULL;
   }
   node *h = newNode(temp[0]);
   node *last = h;
   for (int i = 1; i < size; i++)
   {
      last->next = newNode(temp[i]);
      last = last->next;
   }
   return h;
}
node *newNode(int value)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = value;
   return temp;
}
void printLL(node *head)
{
   node *a = head;
   while (a != NULL)
   {
      cout << a->data << " ";
      a = a->next;
   }
   cout << endl;
}