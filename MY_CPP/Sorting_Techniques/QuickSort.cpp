#include <iostream>
using namespace std;
void swap(int &x, int &y);
int partition(int arr[], int l, int h);
void quickSort(int arr[], int l, int h);
int main()
{
   int arr[21];
   for (int i = 0; i < 21; i++)
   {
      arr[i] = 154 - i;
   }
   quickSort(arr, 0, 21);
   for (int i = 0; i < 21; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}
void swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}
int partition(int arr[], int l, int h)
{
   int pivot = arr[l];
   int i = l, j = h;
   do
   {
      do
      {
         i++;
      } while (arr[i] <= pivot);
      do
      {
         j--;
      } while (arr[j] > pivot);
      if (i < j)
      {
         swap(arr[i], arr[j]);
      }

   } while (i < j);
   swap(arr[j], arr[l]);
   return j;
}
void quickSort(int arr[], int l, int h)
{
   if (l < h)
   {
      int j = partition(arr, l, h);
      quickSort(arr, l, j);
      quickSort(arr, j + 1, h);
   }
}