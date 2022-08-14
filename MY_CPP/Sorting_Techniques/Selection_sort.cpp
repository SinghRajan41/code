#include <iostream>
using namespace std;
void selection_sort(int arr[], int n)
{
   int idx;
   for (int i = 0; i < n - 1; i++)
   {
      idx = i;
      for (int j = i; j < n; j++)
      {
         if (arr[j] < arr[idx])
         {
            idx = j;
         }
      }
      if (idx != i)
      {
         int temp = arr[i];
         arr[i] = arr[idx];
         arr[idx] = temp;
      }
   }
}
int main()
{

   int arr[100];
   for (int i = 0; i < 100; i++)
   {
      arr[i] = 211 - i;
   }
   selection_sort(arr, 100);
   for (int i = 0; i < 100; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}