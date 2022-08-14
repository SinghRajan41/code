#include <iostream>
#include <vector>
using namespace std;
class maxHeap
{
public:
   int *harr, size, n;

   maxHeap();
   maxHeap(int x);
   void insert(int value);
   inline int peekRoot();
   void pushDown(int arr[], int i, int size);
   void deleteRoot();
   void heapSort(int arr[], int size);
};
vector<int> kLargest(int arr[], int n, int k);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      vector<int> res = kLargest(arr, n, k);
      for (int i = 0; i < res.size(); i++)
      {
         cout << res[i] << " ";
      }
      cout << endl;
   }
   return 0;
}
vector<int> kLargest(int arr[], int n, int k)
{
   int idx = n / 2 - 1;
   for (; idx >= 0; idx--)
   {
      int i = idx;
      while (i < n)
      {
         int j = 2 * i + 1;
         if (j + 1 < n && arr[j + 1] > arr[j])
         {
            j++;
         }
         if (arr[(j - 1) / 2] <= arr[j] && j < n)
         {
            swap(arr[j], arr[(j - 1) / 2]);
         }
         i = j;
      }
   }
   for (int idx = 0; idx < k; idx++)
   {
      swap(arr[0], arr[n - 1 - idx]);
      // pushDown lighter element
      int size = n - 2 - idx;
      int i = 0;
      while (i <= size)
      {
         int j = 2 * i + 1;
         if (j + 1 <= size && arr[j + 1] >= arr[j])
         {
            j++;
         }
         if (arr[(j - 1) / 2] <= arr[j] && j <= size)
         {
            swap(arr[j], arr[(j - 1) / 2]);
         }
         i = j;
      }
   }
   vector<int> res;
   for (int i = 0; i < n; i++)
   {
      res.push_back(arr[n - 1 - i]);
   }

   return res;
}
void maxHeap::heapSort(int arr[], int size)
{
   if (size <= 0)
   {
      return;
   }
   // Converting the array into heap
   int i = size / 2 - 1;
   for (; i >= 0; i--)
   {
      pushDown(arr, i, size - 1);
   }
   // Now deleting elements from the array
   for (i = 0; i < size; i++)
   {
      swap(arr[0], arr[size - 1 - i]);
      pushDown(arr, 0, size - 2 - i);
   }
   cout << endl;
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}
inline int maxHeap::peekRoot()
{
   if (n == -1)
   {
      return -1;
   }
   else
   {
      return harr[0];
   }
}
void maxHeap::pushDown(int arr[], int i, int size)
{
   int j = 2 * i + 1;
   if (j + 1 <= size && arr[j + 1] > arr[j])
   {
      j++;
   }
   if (j <= size && arr[j] > arr[(j - 1) / 2])
   {
      swap(arr[j], arr[(j - 1) / 2]);
      pushDown(arr, j, size);
   }
}
void maxHeap::deleteRoot()
{
   if (n == -1)
   {
      return;
   }
   else if (n == 0)
   {
      n -= 1;
   }
   else
   {
      swap(harr[0], harr[n]);
      n -= 1;
      pushDown(harr, 0, n);
   }
}
void maxHeap::insert(int value)
{
   if (n == size - 1)
   {
      cout << "\nHeap is FULL\n";
   }
   harr[++n] = value;
   int i = n;
   while (i > 0)
   {
      if (harr[i] > harr[(i - 1) / 2])
      {
         swap(harr[i], harr[(i - 1) / 2]);
      }
      i = (i - 1) / 2;
   }
}
maxHeap::maxHeap()
{
   size = 1000;
   harr = new int[size];
   n = -1;
}
maxHeap::maxHeap(int x)
{
   size = x;
   harr = new int[size];
   n = -1;
}