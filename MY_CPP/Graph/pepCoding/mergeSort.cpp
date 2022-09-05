#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
   int a[mid - low + 1], b[high - mid];
   for (int i = low; i <= mid; i++)
   {
      a[i - low] = arr[i];
   }
   for (int i = mid + 1; i <= high; i++)
   {
      b[i - mid - 1] = arr[i];
   }
   int x = mid - low + 1;
   int y = high - mid;
   int i, j, k;
   i = j = k = 0;
   while (i < x && j < y)
   {
      if (a[i] < b[i])
      {
         arr[k++] = a[i++];
      }
      else
      {
         arr[k++] = b[j++];
      }
   }
   while (i < x)
   {
      arr[k++] = a[i++];
   }
   while (j < x)
   {
      arr[k++] = b[j++];
   }
}
void mergeSort(int arr[], int low, int high)
{
   if (low < high)
   {
      int mid = (low + high) / 2;
      mergeSort(arr, low, mid);
      mergeSort(arr, mid + 1, high);
      merge(arr, low, mid, high);
   }
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   mergeSort(arr, 0, n - 1);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}