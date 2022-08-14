#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int h);
void mergesort(int arr[], int l, int h)
{
   if (l < h)
   {
      int m = (l + h) / 2;
      mergesort(arr, l, m);
      mergesort(arr, m + 1, h);
      merge(arr, l, m, h);
   }
}
void merge(int arr[], int l, int m, int h)
{
   int i = l, j = m + 1;
   while (i <= m && j <= h)
   {
      if (arr[i] < arr[j])
      {
         i++;
      }
      else
      {
         // Right elements
         int key = arr[j], k;
         for (k = j; k > i; k--)
         {
            arr[k] = arr[k - 1];
         }
         arr[k] = key;
         i++;
         j++;
      }
   }
}
int main()
{
   int arr[17] = {17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   mergesort(arr, 0, 16);
   for (int i = 0; i < 17; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}