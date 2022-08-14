#include <iostream>
using namespace std;
class heap
{
   int arr[1001], i, size;

public:
   heap()
   {
      i = 0;
      size = 0;
   }
   void make_heap(int arr[], int n);
   void heapify(int arr[], int i, int n);
   void heapsort();
   void insert(int value);
   void remove();
   void swap(int &x, int &y);
   void display();
   inline int heapsize();
   int ispowerof2(int n);
   void array_to_heap(int arr[], int n);
   void heapsort(int arr[], int n);
};
void heap::array_to_heap(int arr[], int n)
{
   for (int i = n / 2; i >= 0; i--)
   {
      heapify(arr, i, n);
   }
}
void heap::heapify(int arr[], int i, int n)
{
   int j = 2 * i;
   if (arr[j] < arr[j + 1] && j + 1 < n)
   {
      j += 1;
   }
   if (arr[j] > arr[j / 2] && j < n)
   {
      swap(arr[j], arr[j / 2]);
      heapify(arr, j, n);
   }
}
inline int heap::heapsize()
{
   return size;
}
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
   size = i;
   while (arr[j / 2] < value && j / 2 >= 1)
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
      swap(arr[1], arr[i]);
      i--;
      int j = 2;
      while (j < i)
      {
         if (arr[j] < arr[j + 1] && j + 1 <= i)
         {
            j += 1;
         }
         if (arr[j / 2] < arr[j])
         {
            swap(arr[j], arr[j / 2]);
            j = j * 2;
         }
      }
   }
}
void heap::display()
{
   for (int i = 1; i <= size; i++)
   {
      cout << arr[i] << " ";
      if (ispowerof2(i + 1))
      {
         cout << endl;
      }
   }
}
int heap::ispowerof2(int n)
{
   if ((n & n - 1) == 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int main()
{
   heap h;
   /*for (int i = 0; i < 11; i++)
   {
      h.insert(i);
   }
   for (int i = 0; i < h.heapsize(); i++)
   {
      h.remove();
   }
   h.display();*/
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   h.array_to_heap(arr, 10);
   for (int i = 0; i < 10; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}