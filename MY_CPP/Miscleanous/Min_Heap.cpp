#include <iostream>
using namespace std;
class heap
{
   int arr[500], i, size;

public:
   heap()
   {
      i = 0;
      size = 0;
   }
   void insert(int value);
   void display();
   void remove();
   void swap(int &x, int &y);
   void heapsort(int arr[], int n);
   void heapify(int arr[], int i, int n);
};
void heap::swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}
void heap::insert(int value)
{
   arr[++i] = value;
   int j = i;
   size++;
   while (value < arr[j / 2] && j / 2 >= 1)
   {
      arr[j] = arr[j / 2];
      j = j / 2;
   }
   if (i != j)
   {
      arr[j] = value;
   }
}
void heap::remove()
{
   if (i <= 1)
   {
      return;
   }
   else
   {
      swap(arr[i], arr[1]);
      int j = 2;
      i--;
      while (j <= i)
      {
         if (arr[j] > arr[j + 1] && j + 1 <= i)
         {
            j += 1;
         }
         if (arr[j / 2] > arr[j])
         {
            swap(arr[j], arr[j / 2]);
            j = j * 2;
            continue;
         }
         break;
      }
   }
}
void heap::display()
{
   for (int it = 1; it <= size; it++)
   {
      cout << arr[it] << " ";
   }
}
int main()
{
   heap h;
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   h.heapsort(arr, 10);

   return 0;
}
void heap::heapsort(int arr[], int n)
{
   int i = (n / 2) - 1;
   for (; i >= 0; i--)
   {
      heapify(arr, i, n);
   }
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}
void heapify(int arr[], int i, int n)
{
   int j = 2 * i;
   if (arr[j] < arr[j + 1] && j + 1 < n)
   {
      j += 1;
   }
   if (arr[j / 2] < arr[j])
   {
      swap(arr[j / 2], arr[j]);
      heapify(arr, j, n);
   }
}
