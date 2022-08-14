#include <iostream>
using namespace std;
void mergeSort(int arr[], int n);
void merge(int arr[], int l, int m, int h);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   mergeSort(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}
void mergeSort(int arr[], int n)
{
   int p;
   for (p = 1; p <= n; p *= 2)
   {
      for (int i = 0; i < n; i++)
      {
         int l = i;
         int h = i + p - 1;
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
   int *b = new int[h - l + 1];
   int i = l, j = m + 1, k = 0;
   while (i <= m && j <= h)
   {
      if (arr[i] < arr[j])
      {
         b[k++] = arr[i++];
      }
      else
      {
         b[k++] = arr[j++];
      }
   }
   while (i <= m)
   {
      b[k++] = arr[i++];
   }
   while (j <= h)
   {
      b[k++] = arr[j++];
   }
   for (int i = l; i <= h; i++)
   {
      arr[i] = b[i - l];
   }
}