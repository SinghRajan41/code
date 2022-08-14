// ToDo Write code for drop 2 and grab2 and practice quicksort
#include <iostream>
using namespace std;
struct node
{
   node *next;
   int data;
};
void swap(int &x, int &y);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void RMergeSort(int arr[], int l, int h);
void merge(int arr[], int l, int m, int h);
void IMergeSort(int arr[], int n);
void countSort(int arr[], int n);
void binBucketSort(int arr[], int n);
void drop(node **b, int value);
void grab(node **b, int pos);
void shellSort(int arr[], int n);
void insert(int arr[], int gap, int i);
void radixSort(int arr[], int n);
void drop(node **b, int pos, int value);
void drop2(node **b, int pos, int value);
void grab2(node **b, int pos);
int main()
{
   int arr[100];
   for (int i = 100; i > 0; i--)
   {
      arr[100 - i] = i;
   }
   radixSort(arr, 100);
   printArray(arr, 100);
   return 0;
}
void drop2(node **b, int pos, int value)
{
   node *temp = new node;
   temp->next = NULL;
   temp->data = value;
   if (b[pos] == NULL)
   {
      b[pos] = temp;
      return;
   }
   else
   {
      node *c = b[pos];
      while (c->next != NULL)
      {
         c = c->next;
      }
      c->next = temp;
   }
}
void grab2(node **b, int pos)
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
      node *a = b[pos];
      b[pos] = a->next;
      delete a;
   }
}
void radixSort(int arr[], int n)
{
   int m = -999999, len = 0, den = 1;
   node **b = new node *[10];
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   while (m)
   {
      len++;
      m /= 10;
   }
   for (int i = 0; i < 10; i++)
   {
      b[i] = NULL;
   }
   while (len--)
   {
      for (int i = 0; i < n; i++)
      {
         int pos = (arr[i] / den) % 10;
         drop2(b, pos, arr[i]);
      }
      int k = 0;
      for (int i = 0; i < 10; i++)
      {
         while (b[i] != NULL)
         {
            arr[k++] = b[i]->data;
            grab2(b, i);
         }
      }
      den *= 10;
   }
}
void insert(int arr[], int gap, int i)
{
   if (i < 0)
   {
      return;
   }
   else
   {
      if (arr[i] < arr[i - gap] && i - gap >= 0)
      {
         swap(arr[i], arr[i - gap]);
         insert(arr, gap, i - gap);
      }
   }
}
void shellSort(int arr[], int n)
{
   int gap = n / 2;
   for (; gap >= 1; gap /= 2)
   {
      for (int i = gap; i < n; i++)
      {
         insert(arr, gap, i);
      }
   }
}
void grab(node **b, int pos)
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
      node *p, *q;
      p = b[pos];
      q = p->next;
      while (q->next != NULL)
      {
         p = q;
         q = q->next;
      }
      delete q;
      p->next = NULL;
   }
}
void drop(node **b, int value)
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
void binBucketSort(int arr[], int n)
{
   int m = INT32_MIN;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   node **b = new node *[m + 1];
   for (int i = 0; i <= m; i++)
   {
      b[i] = NULL;
   }
   // Dropping in bucket
   for (int i = 0; i < n; i++)
   {
      drop(b, arr[i]);
   }
   // Collecting back from bucket
   int k = 0;
   for (int i = 0; i <= m; i++)
   {
      if (b[i] != NULL)
      {
         while (b[i] != NULL)
         {
            arr[k++] = b[i]->data;
            grab(b, b[i]->data);
         }
      }
   }
   delete[] b;
   b = NULL;
}
void countSort(int arr[], int n)
{
   int m = INT32_MIN;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   int freq[m + 1] = {0};
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   int k = 0;
   for (int i = 0; i <= m; i++)
   {
      while (freq[i]--)
      {
         arr[k++] = i;
      }
   }
}
void IMergeSort(int arr[], int n)
{
   int p;
   for (p = 1; p <= n; p *= 2)
   {
      for (int i = 0; i < n; i += p)
      {
         int l = i;
         int h = l + p - 1;
         int m = (l + h) / 2;
         merge(arr, l, m, h);
      }
   }
   if (p / 2 < n)
   {
      merge(arr, 0, p / 2 - 1, n);
   }
}
void merge(int arr[], int l, int m, int h)
{
   int temp[h - l + 1], k = 0;
   int i = l, j = m + 1;
   while (i <= m && j <= h)
   {
      if (arr[i] < arr[j])
      {
         temp[k++] = arr[i++];
      }
      else
      {
         temp[k++] = arr[j++];
      }
   }
   while (i <= m)
   {
      temp[k++] = arr[i++];
   }
   while (j <= h)
   {
      temp[k++] = arr[j++];
   }
   for (int i = l; i <= h; i++)
   {
      arr[i] = temp[i - l];
   }
}
void RMergeSort(int arr[], int l, int h)
{
   if (l < h)
   {
      int m = (l + h) / 2;
      RMergeSort(arr, l, m);
      RMergeSort(arr, m + 1, h);
      merge(arr, l, m, h);
   }
}
void selectionSort(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int idx = i, cur = arr[i];
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < cur)
         {
            cur = arr[j];
            idx = j;
         }
      }
      swap(arr[i], arr[idx]);
   }
}
void insertionSort(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      int key = arr[i], idx = i, j = i - 1;
      while (key < arr[j] && j >= 0)
      {
         arr[j + 1] = arr[j];
         j -= 1;
      }
      arr[j + 1] = key;
   }
}
void swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}
void bubbleSort(int arr[], int n)
{
   int flag;
   for (int i = 0; i < n; i++)
   {
      flag = 0;
      for (int j = 0; j < n - i - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            swap(arr[j], arr[j + 1]);
            flag++;
         }
      }
      if (flag == 0)
      {
         break;
      }
   }
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}
