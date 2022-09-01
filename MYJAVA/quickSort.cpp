#include <iostream>
using namespace std;
void printArray(int arr[], int n);
int partition(int arr[], int low, int high, int pivot)
{
   int i = low;
   int j = high;
   while (i < j)
   {
      while (arr[i] <= pivot && i <= high)
      {
         i++;
      }
      while (arr[j] > pivot)
      {
         j--;
      }
      if (i < j)
      {
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[low], arr[j]);
   return j;
}
void quickSort(int arr[], int low, int high)
{
   if (low < high)
   {
      int pivot = arr[low];
      int j = partition(arr, low, high, pivot);
      quickSort(arr, low, j - 1);
      quickSort(arr, j + 1, high);
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
   quickSort(arr, 0, n - 1);
   printArray(arr, n);
   return 0;
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}