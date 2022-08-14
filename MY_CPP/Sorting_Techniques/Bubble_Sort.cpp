// No of comparisions O(n^2)
// Max number of swaps = O(n^2)
// It is called bubble sort coz heavier elements go down
// After performing k passes you get "k" largest elements
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n)
{
   int flag = 0;
   for (int i = 0; i < n - 1; i++)
   {
      flag = 0;
      for (int j = i; j < n - 1 - i; j++)
      {
         if (arr[j + 1] < arr[j])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            flag = 1;
         }
      }
      if (flag == 0)
      {
         cout << "Hello" << endl;
         break;
      }
   }
}
int main()
{
   int arr[200000];
   for (int i = 0; i < 200000; i++)
   {
      arr[i] = i + 1;
   }
   bubble_sort(arr, 200000);
   for (int i = 0; i < 200000; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}

// Adaptivity
// 2 3 5 7 8 Swapping and comparision keeps happening
// That is the reason why we check in each pass if the array is already sorted or not
// Minimum time O(n) for already sorted list, so we make it adoptive by introducing flag
// Stability-Order of duplicate elements is maintained like for example 8 8 2 34 54 1 2