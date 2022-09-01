#include <iostream>
using namespace std;
void customSort(int arr[], int n);
void printArray(int arr[], int n);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   customSort(arr, n);
   printarray(arr, n);
   return 0;
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}
void customSort(int arr[], int n)
{
   // Sorting even position elements in ascending order
   for (int i = 3; i < n; i += 2)
   {
      int j = i;
      int key = arr[j];
      while (j > 1 && key < arr[j - 2])
      {
         arr[j] = arr[j - 2];
         j -= 2;
      }
      if (i != j)
      {
         arr[j] = key;
      }
   }
   // Sorting odd position elements in descending order
   for (int i = 2; i < n; i += 2)
   {
      int j = i;
      int key = arr[i];
      while (j > 0 && key > arr[j - 2])
      {
         arr[j] = arr[j - 2];
         j -= 2;
      }
      if (i != j)
      {
         arr[j] = key;
      }
   }
}
#include <iostream>
using namespace std;
void determineSortedness(int arr[], int n)
{
   int maxstep = (n * (n - 1)) / 2;
   int steps = 0;
   for (int i = 1; i < n; i++)
   {
      int key = arr[i];
      int j = i;
      while (j > 0 && key < arr[j - 1])
      {
         arr[j] = arr[j - 1];
         j--;
         steps++;
      }
      if (i != j)
      {
         arr[j] = key;
      }
   }
   float sortPercent = 100.0 - 100.0 * (1.0 * steps) / (1.0 * maxstep);
   if (sortPercent == 100.0)
   {
      cout << "Fully sorted";
   }
   else if (sortPercent >= 75 && sortPercent < 100)
   {
      cout << "Almost sorted";
   }
   else
   {
      cout << "Not Sorted";
   }
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
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
   detSort(arr, n);
   return 0;
}
#include <iostream>
using namespace std;
void specialSort(int arr[], int n)
{
   if (arr[0] > arr[1])
   {
      swap(arr[0], arr[1]);
   }
   for (int i = 2; i < n; i++)
   {
      int key = arr[i];
      if (key <= arr[0])
      {
         for (int j = i - 1; j > -1; j--)
         {
            arr[j + 1] = arr[j];
         }
         arr[0] = key;
      }
      else
      {

         for (int j = 0; j < i; j++)
         {
            if (key > arr[j] && key < arr[j + 1])
            {
               for (int z = i - 1; z >= j; z--)
               {
                  arr[z + 1] = arr[z];
               }
               arr[j + 1] = key;
               break;
            }
         }
      }
   }
}
void printarray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
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
   specialSort(arr, n);
   printarray(arr, n);
   return 0;
}