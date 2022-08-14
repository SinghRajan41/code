#include <iostream>
using namespace std;
int main()
{
   int arr[100];
   for (int i = 0; i < 100; i++)
   {
      arr[i] = 101 - i;
   }
   // Insertion Sort
   // 9 8 7 6 5 4 3 2 1
   for (int i = 1; i < 100; i++)
   {
      int j = i, key = arr[i], flag = 0;

      while (key < arr[j - 1] && j > 0)
      {
         // Shift ahead
         arr[j] = arr[j - 1];
         flag++;
         j--;
      }
      if (flag != 0)
      {
         arr[j] = key;
      }
   }
   for (int i = 0; i < 100; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}
// It is adoptive and stable as order of duplicates is maintained
