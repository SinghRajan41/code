#include <iostream>
using namespace std;
int main()
{
   int arr[100], temp, j, n = 100;
   for (int i = 0; i < 100; i++)
   {
      arr[i] = 100 - i;
   }
   int k = 5;
   for (int i = 0; i < k; i++)
   {
      for (j = 0; j < n - i - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            // Swap
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
      cout << arr[j] << " ";
   }
   return 0;
}
