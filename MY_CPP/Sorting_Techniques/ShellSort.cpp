#include <iostream>
using namespace std;
void shellSort(int arr[], int n);
void insert(int arr[], int gap, int i);
void shellSort(int arr[], int n)
{
   int gap = n / 2;
   for (; gap > 0; gap /= 2)
   {
      for (int i = gap; i < n; i++)
      {
         insert(arr, gap, i);
      }
   }
}
void insert(int arr[], int gap, int i)
{
   if (i < 0)
   {
      return;
   }
   if (arr[i] < arr[i - gap] && i - gap >= 0)
   {
      int temp = arr[i];
      arr[i] = arr[i - gap];
      arr[i - gap] = temp;
      insert(arr, gap, i - gap);
   }
}
int main()
{
   int arr[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   shellSort(arr, 12);
   for (int i = 0; i < 12; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}